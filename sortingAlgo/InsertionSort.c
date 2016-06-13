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
	n2->next = n1->next;
	n1->next = n2;
}

node* insertNsort(node* list,int num) {
	node* n = createNode(num);
	node* head = list;
	node* p = list;
	if(head->val > n->val) {
		n->next = head;
		head = n;
	}
	else {
		while(list) {
			if(list->val < n->val) {
				p = list;
				list = list->next;
			}
			else break;
		}
		insertNode(p,n);
	}
	return head;
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
	node* list = head;
	
	for(i=1;i<size;i++) {
		head = insertNsort(head,A[i]);
	}	
	printList(head);
	head = insertNsort(head,-1);
	printList(head);
	freeList(head);		
	return 0;
}
