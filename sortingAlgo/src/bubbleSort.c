#include <stdio.h>
#include <stdlib.h>
#include "../lib/linkedlist.h"
#if defined(Array)
void bubbleSort(int *A,int n) {
	int i,j;
	int tmp;
	for(i=0; i<n; i++) {
		for(j=i+1; j<n; j++) {
			if(A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}
#endif
