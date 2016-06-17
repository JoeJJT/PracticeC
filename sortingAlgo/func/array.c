#include <stdio.h>
#include <stdlib.h>
#include "../lib/array.h"

void print(int *A,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%d ",A[i]);
    }
    printf("\n");
}
