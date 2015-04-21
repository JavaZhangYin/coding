CC=gcc
CFLAGS+=-std=c99
CFLAGS+=-ggdb
LDFLAGS=-lpthread
OBJS=pagetable.o
EXEC=pagetable

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@
.o:.c
	$(CC) $(CFLAGS) $< -o $@

byu_tracereader: byu_tracereader.c byutr.h
	$(CC) -o $@ $<

clean: 
	@rm -rvf $(OBJS) $(EXEC)
