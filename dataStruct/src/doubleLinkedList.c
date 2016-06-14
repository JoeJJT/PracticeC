#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

node* createNode(int val) {
	node* n = (node*)malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	n->pre = NULL;
	return n;
}

void insertNode(node* list,int val) {
	node* n = createNode(val);
	n->pre = list;
	n->next = list->next;
	list->next = n;
}
/*
node* insertNsort(node* list,node* n) {
	node* head = list;
	return head;
}
*/
void deleteNode(node* list,node* n) {
	list->next = n->next;
	n->next->pre = list;
	free(n);
}

void freeList(node* list) {
	while(list) {
		free(list);
		list = list->next;
	}
}

void printList(node* list) {
	node* p;
	while(list) {
		printf("%d->",list->val);
		p = list;
		list = list->next;
	}
	printf("NULL\n");
	printf("NULL");
	while(p) {
		printf("->%d",p->val);
		p = p->pre;
	}
	printf("\n");
}

int main(int argc,int **argv) {
	int A[] = {2,4,5,3,1,0};
	int size = sizeof(A) / sizeof(A[0]);
	int i;
	node* head = createNode(A[0]);
	node* p = head;
	for(i=1; i<size;i++) {
		insertNode(p,A[i]);
		p = p->next;
	}
	printList(head);
	freeList(head);
	return 0;
}
