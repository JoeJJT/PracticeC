#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

node* createNode(int val) {
	node* n = (node*) malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	return n;
}
/*insert Node2 after Node1*/
void insertNode(node* n1,node* n2) {
	n1->next = n2;
}

void insertNsort(node *list,node *n) {
	if(list->val > n->val)
		n->next = list;
	while(list) {
		if(list->val < n->val) {
			list = list->next;
		}
	}
	list = n; 
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
	int A[] = {0,6,2,3,9,4};
	int size = sizeof(A)/sizeof(A[0]);
	int i;
	node* head = createNode(A[0]);
	node* list = head;
	for(i=1;i<size;i++) {
		node* n = createNode(A[i]);
		insertNode(list,n);
		list = list->next;
	}	
	//insertNsort(list,a);
	//insertNsort(list,b);
	printList(head);
	freeList(head);		
	return 0;
}
