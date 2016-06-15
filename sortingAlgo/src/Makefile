FUNC = ../func

CFLAGS= -O0 -std=gnu99
EXEC = bubbleSort insertionSort mergeSort

all:$(EXEC)

bubbleSort: bubbleSort.c $(FUNC)/linkedlist.c
	$(CC) $(CFLAGS) -DList -DArray $^ -o bubbleSort

clean:
	$(RM) $(EXEC) *.o
