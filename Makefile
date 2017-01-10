SRC := $(wildcard *.c)
BIN := $(SRC:.c=)

.PHONY: all clean

all: $(BIN)

%: %.c
	$(CC) -o $@ -ansi -Wall -Werror -pedantic $<

clean:
	rm -f $(BIN)
