#include <stdio.h>
#include <pthread.h>
#define THREAD_NUM 3

void *show_message(void *ptr);

int main() {
	pthread_t thread1[THREAD_NUM];
	char *message = "thread 1";
	void *ret;
	int i;
	for(i=0;i<THREAD_NUM;i++) {
		pthread_create(&thread1[i], NULL, show_message, (void*)message);
	}
	for(i=0;i<THREAD_NUM;i++) {
		pthread_join(thread1[i], &ret);
	}	
	printf("return value from thread1 = %d\n",ret);
	
	return 0;
}


void *show_message(void *ptr) {
	char *message;
	message = (char *)ptr;
	int i;
	printf("%s\n",message);
	pthread_exit((void *)1234);
}
