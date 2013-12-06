
CC ?= cc
CFLAGS = -std=c99 -Wall -Ideps -Isrc
SRC = $(wildcard src/*.c)
SRC += $(wildcard deps/*.c)
TESTS = $(wildcard test/*.c)

test: $(TESTS)

$(TESTS):
	$(CC) $@ $(SRC) $(CFLAGS) -o $(basename $@)
	./$(basename $@)

clean:
	$(foreach test, $(TESTS), rm -f $(basename $(test));)

.PHONY: test $(TESTS) clean
