CFLAGS= -O0 -std=gnu99
EXEC = mergeSort insertionSort bubbleSort

all:$(EXEC)

bubbleSort:
	$(CC) $(CFLAGS) -DArray -DList -o $@ \
	../func/linkedlist.c $@.c 

clean:
	$(RM) $(EXEC) *.o
