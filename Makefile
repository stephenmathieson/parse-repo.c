
CC ?= gcc
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*/*.c)
OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Ideps -Isrc
# set a default repository owner
CFLAGS += -DDEFAULT_REPO_OWNER=\"clibs\"
# set a default repository version
CFLAGS += -DDEFAULT_REPO_VERSION=\"master\"
TESTS = $(wildcard test/*.c)

test: $(TESTS)

$(TESTS): $(OBJS)
	@$(CC) $(CFLAGS) -o $(basename $@) $@ $(OBJS)
	@./$(basename $@)

example: example.o $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS)

clean:
	$(foreach t, $(TESTS), rm -f $(basename $(t));)
	rm -f $(OBJS) test.o example example.o

.PHONY: test clean $(TESTS)
