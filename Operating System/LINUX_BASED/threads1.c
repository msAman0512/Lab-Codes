//WAP to create a multi-threaded program using posix-thread library.
#include<stdio.h>
#include<pthread.h>

void* Th1(){
	printf("I am in thread1\n");
	return NULL;
}
void* Th2(){
	printf("I am in thread2\n");
	return NULL;
}
int main(){
	pthread_t th1;
	pthread_t th2;
	pthread_create(&th2, NULL,Th2, NULL);
	pthread_create(&th1, NULL,Th1, NULL);  //Output depends in this order.
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}


// O/P
// I am in thread2
// I am in thread1