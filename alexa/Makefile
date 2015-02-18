CC=gcc
CFLAGS+=-std=c11
CFLAGS+=-ggdb
LDFLAGS=-lpthread
OBJS=wordcount.o

all: wordcount

wordcount: $(OBJS)
	$(CC) $(LDFLAGS) $< -o $@
.o: .c
	$(CC) $(CFLAGS) $< -o $@
clean: 
	@rm -rf wordcount $(OBJS)
