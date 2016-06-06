#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int val;
	struct Node *next;
}node;

node* createNode(int val) {
	node* n = (node*) malloc(sizeof(node));
	n->val = val;
	n->next = NULL;
	return n;
}

void insertNode(node* n1,node* n2) {
	n2->next = n1->next;
	n1->next = n2;
}

void removeNode(node* list,node* n) {
	list->next = n->next;
	free(n);
}

void printList(node* list) {
	node* n = list;
	while(n) {
		printf("%d->",n->val);
		n = n->next;
	}
	printf("\n");
}

int main(int argc,int **argv) {
	node* list = createNode(0);
	node* a = createNode(6);
	insertNode(list,a);
	printList(list);		
	return 0;
}
