
CC ?= gcc
VALGRIND ?= valgrind
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Ideps -Isrc
TESTS = $(wildcard test/*.c)
VALGRIND_OPTS ?= --leak-check=full

test: $(TESTS)

$(TESTS): $(OBJS)
	@$(CC) $(CFLAGS) -o $(basename $@) $@ $(OBJS)
	@$(TEST_RUNNER) ./$(basename $@)

grind:
	@TEST_RUNNER="$(VALGRIND) $(VALGRIND_OPTS)" \
		$(MAKE) test

example: example.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	$(foreach t, $(TESTS), rm -f $(basename $(t));)
	rm -f $(OBJS) test.o example example.o

.PHONY: test clean $(TESTS)
