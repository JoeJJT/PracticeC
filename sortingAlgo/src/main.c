#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"
#include "../lib/array.h"

int main(int *argc,int **argv) {
    int A[] = {2,4,3,6,1,7,9,8,0};
    int size = sizeof(A) / sizeof(A[0]);
	int i;
    printf("Raw data:");
	for(i=0 ; i < size ; i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
#if defined(Array)
#if defined(Bubble) 
    bubbleSort(A,size);
#endif

#if defined(Merge)
	mergeSort(A,size);
#endif

#if defined(Insertion)
#endif
#if defined(Quick)
#endif
	printf("After Sort:");
    print(A,size);
#endif

#if defined(List)

#if defined(Insertion)
    node* head = createNode(A[0]);
    node* list = head;
    for(i=1;i<size;i++) {
        head = insertNsort(head,A[i]);
    }   
    printList(head);
    printf("after insert -1\n");
    head = insertNsort(head,-1);
#endif

#if defined(Bubble)
    node*  = createList(A,size);
    printList(list);
    bubbleSort(list);
#endif
    printList(head);
	freeList(head);
#endif
    return 0;
}
