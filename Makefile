CC=gcc
CFLAGS=-Wall -Werror

build:
	@$(CC) $(CFLAGS) main.c -o main
