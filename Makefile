CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -std=c11

ckmacs: ckmacs.c
	$(CC) ckmacs.c src/term.c src/input.c src/output.c -o bin/ckmacs $(CFLAGS)
