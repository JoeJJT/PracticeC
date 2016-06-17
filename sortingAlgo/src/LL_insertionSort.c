#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

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
