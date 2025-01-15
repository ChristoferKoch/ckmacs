CC=gcc

ckmacs: ckmacs.c
	$(CC) ckmacs.c -o ckmacs -Wall -Wextra -Wpedantic -std=c11
