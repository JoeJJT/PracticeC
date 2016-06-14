CC ?= gcc
CFLAGS_common ?= -O0 -Wall -std=gnu99

EXEC = iterative recursive
PERF_STAT = cycles,instructions,cache-misses
all: $(EXEC)
main = main.c

iterative: $(main) iterative.c BinaryTree.h
	$(CC) $(CFLAGS_common) -DITER -o $@ $(main) $@.c

recursive: $(main) recursive.c BinaryTree.h
	$(CC) $(CFLAGS_common) -DREC -o $@ $(main) $@.c

perf_stat:
	perf stat -r 1 -e $(PERF_STAT) ./recursive
	perf stat -r 1 -e $(PERF_STAT) ./iterative
clean:
	$(RM) $(EXEC) *.o perf.*
