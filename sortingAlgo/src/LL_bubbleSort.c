#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"

void bubbleSort(node* list) {
    node* p = list;
    node* x = list;
    int temp;
    while(x) {
        while(p) {
            if(p->val > p->next->val) {
                temp = p->val;
                p->val = p->next->val;
                p->next->val = temp;    
            }
            p = p->next;
        }
        x = x->next;
    }   
}
