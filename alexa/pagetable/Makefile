CC=g++
CFLAGS+=-std=c99
CFLAGS+=-ggdb
LDFLAGS=
OBJS=VtoP.o PageTable.o PageFrameMap.o
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
