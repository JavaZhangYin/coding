CC=gcc
CFLAGS+=-std=c11
all: wordcount

wordcount: wordcount.c
	$(CC) $(CFLAGS) $< -o $@
clean: 
	@rm -rf wordcount
