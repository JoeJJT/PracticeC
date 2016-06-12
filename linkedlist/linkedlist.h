#ifndef _LIST_H
#define _LIST_H

typedef struct Node {
	int val;
	struct Node *next;
	struct Node *pre;
}node;

node* createNode(int );
//void insertNode(node* ,node* );
void removeNode(node* ,node* );
void freeList(node* );
void printList(node* );

#endif
