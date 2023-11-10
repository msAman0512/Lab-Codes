// WAP to create a mutli-threaded program to take input and print the character all at the same time.
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

char alpha = 'a';
void* Th1(void* arg){
	while(1){
		printf("%c\t", alpha);
		//usleep(500000);
		sleep(1);
	}
	return NULL;
}
void* Th2(void* arg){  //the func should accept void* and return void* argument. Its like a custom.
	while(1){
		scanf("%c\n", &alpha);
	}
	return NULL;
}
int main(){
	pthread_t th1;
	pthread_t th2;
	pthread_create(&th1, NULL, Th1, NULL);
	pthread_create(&th2, NULL, Th2, NULL);
	pthread_join(th1, NULL);
	pthread_join(th2,NULL);
	return 0;
}
