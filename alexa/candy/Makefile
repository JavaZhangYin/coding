CC=gcc
CFLAGS+=-std=c99
CFLAGS+=-ggdb
LDFLAGS=-lpthread
OBJS=options.o queue.o reports.o producer.o consumer.o candy.o defs.o
EXEC=candy

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
.o: .c
	$(CC) $(CFLAGS) $< -o $@
clean: 
	@rm -rf $(OBJS)
