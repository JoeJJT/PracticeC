#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

void bubbleSort(node* list) {
    node* p;
    node* x = list;
    int temp;
    while(x) {
		p = list;
        while(p) {
            if(x->val < p->val) {
                temp = x->val;
                x->val = p->val;
                p->val = temp;    
            }
            p = p->next;
        }
        x = x->next;
    }   
}

