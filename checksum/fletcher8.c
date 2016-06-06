#include <stdio.h>
#include <stdlib.h>

void Fletcher8(char *buffer,int N,unsigned char *cka,unsigned char *ckb) {
	uint32_t i;
	*cka = 0;
	*ckb = 0;
	for(i=2; i<N;i++ ) {
		*cka += buffer[i];
		*ckb += *cka;
	}
}

int main(int argc,int **argv) {
	
	return 0;
}
