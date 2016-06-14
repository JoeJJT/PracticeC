#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

node* createNode(int val) {
	node* n = (node*) malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	return n;
}
/*insert Node2 after Node1*/
void insertNode(node* n1,node* n2) {
	n2->next = n1->next;
	n1->next = n2;
}

void removeNode(node* list,node* n) {
	list->next = n->next;
	free(n);
}

void freeList(node* list) {
	while(list) {
		free(list);
		list = list->next;
	}
}

void printList(node* list) {
	node* n = list;
	while(n) {
		printf("%d->",n->val);
		n = n->next;
	}
	printf("NULL\n");
}

int main(int argc,int **argv) {
	int A[] = {0,6,2,3,9,4,-2,-5};
	int size = sizeof(A)/sizeof(A[0]);
	int i;
	node* head = createNode(A[0]);
	node* n;
	node* list = head;
	
	for(i=1;i<size;i++) {
		n = createNode(A[i]);
		insertNode(list,n);
		list = list->next;
	}

	printList(head);
	freeList(head);		
	return 0;
}
