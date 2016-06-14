#include <stdio.h>
#include <stdlib.h>

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

void print(int *A,int n) {
	int i;	
	for(i=0; i<n; i++) {
		printf("%d ",A[i]);
	}
	printf("\n");
}

int main(int *argc,int **argv) {
	int A[] = {2,4,3,6,1,7,9,8,0};
	int size = sizeof(A) / sizeof(A[0]);

#if defined(Array)		
	bubbleSort(A,size);
	print(A,size);
#endif
#if defined(List)
#endif
	return 0;
}
