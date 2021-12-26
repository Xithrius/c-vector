CC=gcc
STD=c11
CFLAGS=-Wall -Wextra -Werror -O2 -std=$(STD) -pedantic

bin/%.o: */%.c
	$(CC) $< $(CFLAGS) -o $@

build: bin/main.o
    gcc -g -std=$(STD) ./src/main.c -o ./bin/main.o

debug: src/main.o
    gcc -g -std=$(STD) ./src/main.c -o ./bin/main.o -g

.PHONY: clean
clean:
	rm -f ./bin/*.o
