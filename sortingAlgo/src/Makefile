FUNC = ../func
LIB = ../lib

CFLAGS= -O0 -std=gnu99
EXEC = mergeSort insertionSort bubbleSort

all				:$(EXEC)

bubbleSort		: bubbleSort.o

bubbleSort.o	: bubbleSort.c $(LIB)/linkedlist.h
	$(CC) $(CFLAGS) -c -DArray -DList  bubbleSort.c \
	$(FUNC)/linkedlist.c 
#bubbleSort.o	: $(LIB)/linkedlist.h

clean:
	$(RM) $(EXEC) *.o
