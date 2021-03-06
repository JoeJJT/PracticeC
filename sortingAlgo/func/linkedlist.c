#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

node* createNode(int val) {
	node* n = (node*) malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	return n;
}

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

