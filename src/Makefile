CC=gcc
RM=rm
CFLAGS=-O2
CFILES=$(wildcard *.c)
OBJS=$(CFILES: .c=.o)
TARGET=a.out
all:$(TARGET)   
$(TARGET):$(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o:%.c	
	$(CC) $(CFLAGS) -c $< -o $@ 
clean:
	$(RM) *.o $(TARGET)

