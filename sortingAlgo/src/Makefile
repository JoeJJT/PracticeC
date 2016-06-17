FUNC = ../func

CFLAGS= -O0 -std=gnu99 -g
EXEC = bubbleSort mergeSort LL_insertionSort #LL_bubbleSort mergeSort #insertionSort mergeSort

all:$(EXEC)

mergeSort:main.c mergeSort.c $(FUNC)/array.c
	$(CC) $(CFLAGS) -DArray -DMerge $^ -o $@

bubbleSort:main.c bubbleSort.c $(FUNC)/array.c
	$(CC) $(CFLAGS) -DArray -DBubble $^ -o $@


LL_insertionSort:main.c LL_insertionSort.c $(FUNC)/linkedlist.c
	$(CC) $(CFLAGS) -DList -DInsertion $^ -o $@

LL_bubbleSort: main.c LL_bubbleSort.c $(FUNC)/linkedlist.c
	$(CC) $(CFLAGS) -DList -DBubble $^ -o $@ 

clean:
	$(RM) $(EXEC) *.o
