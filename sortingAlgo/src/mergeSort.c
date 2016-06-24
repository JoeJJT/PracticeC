#include <stdio.h>
#include <stdlib.h>

void merge(int *M,int *L,int leftCount,int *R,int rightCount) {
	int i,j,k;
	
	i = j = k = 0;
	while(i<leftCount && j<rightCount) {
		if( L[i] < R[j] ) {
			M[k++] = L[i++];
		}
		else {
			M[k++] = R[j++];
		}
	}
	while(i < leftCount) M[k++] = L[i++];
	while(j < rightCount) M[k++] = R[j++];
}

void mergeSort(int *M,int n) {
	int i,mid,*L,*R;
	
	if(n<2) return;	
	
	mid = n/2;	

	L = (int*)malloc(mid * sizeof(int));
	R = (int*)malloc((n-mid) * sizeof(int));
	
	for(i=0; i<mid; i++) L[i] = M[i];
	for(i=mid; i<n; i++) R[i-mid] = M[i];
	
	mergeSort(L,mid);
	mergeSort(R,n-mid);
	merge(M,L,mid,R,n-mid);

	free(L);
	free(R);	
}
