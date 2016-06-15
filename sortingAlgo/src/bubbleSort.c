#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"
#if defined(List)
node* createList(int *A,int size) {
	int i;
	node* head = createNode(A[0]);
	node* p = head;
	node* n;
	for(i=1; i<size ;i++) {
		n = createNode(A[i]);
		insertNode(p,n);	
		p = p->next;
	}
	return head;
}

void L_bubbleSort(node* list) {

}
#endif
#if defined(Array)
void A_bubbleSort(int *A,int n) {
	int i,j;
	int tmp;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}

void print(int *A,int n) {
	int i;	
	for(i=0; i<n; i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
}
#endif

int main(int *argc,int **argv) {
	int A[] = {2,4,3,6,1,7,9,8,0};
	int size = sizeof(A) / sizeof(A[0]);

#if defined(Array)		
	A_bubbleSort(A,size);
	print(A,size);
#endif
#if defined(List)
	node* list = createList(A,size);
	printList(list);
	L_bubbleSort(list);
	printList(list);
#endif
	return 0;
}
