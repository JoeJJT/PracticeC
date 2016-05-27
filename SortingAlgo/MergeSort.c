#include <stdio.h>
#include <stdlib.h>

void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	
	i = j = k = 0;
	while(i<leftCount && j<rightCount) {
		if( L[i] < R[j] ) {
			A[k++] = L[i++];
		}
		else {
			A[k++] = R[j++];
		}
	}
	while(i < leftCount) A[k++] = L[i++];
	while(j < rightCount) A[k++] = R[j++];
}

void MergeSort(int *A,int n) {
	int i,mid,*L,*R;
	
	if(n<2) return;	
	
	mid = n/2;	

	L = (int*)malloc(mid * sizeof(int));
	R = (int*)malloc((n-mid) * sizeof(int));
	
	for(i=0; i<mid; i++) L[i] = A[i];
	for(i=mid; i<n; i++) R[i-mid] = A[i];
	
	MergeSort(L,mid);
	MergeSort(R,n-mid);
	Merge(A,L,mid,R,n-mid);

	free(L);
	free(R);	
}

int main() {
	
	int A[] = {5,6,223,75,235,7,824,145,8};
	int i,numOfElement;
	
	numOfElement = sizeof(A) / sizeof(A[0]);
	
	for(i=0;i<numOfElement;i++) printf("%d ",A[i]);
	printf("\n");
	MergeSort(A,numOfElement);
	for(i=0;i<numOfElement;i++) printf("%d ",A[i]);	
	printf("\n");
	return 0;
}
