// WAP to use the _Atomic int datatype to avoid race-condition.
#include<stdio.h>
#include<pthread.h>
#include<stdatomic.h>
_Atomic int n = 0;  //faster than mutex as it's H/W based synch tool. can check with "time ./a.out" cmd.
void* Th1(){
	int i = 0;
	for(;i<100000;i++)
		n++;
	return NULL;
}
void* Th2(){
	int i = 0;
	for(;i<100000;i++)
		n--;
	return NULL;
}
int main(){
	pthread_t th1;
	pthread_t th2;
//	pthread_mutex_init(&lock, NULL);
	pthread_create(&th1, NULL, Th1, NULL);
	pthread_create(&th2, NULL, Th2, NULL);
	pthread_join(th1, NULL);//wil not allow the main thread to get blked/terminate before the two threads. 
	pthread_join(th2, NULL);
//	pthread_mutex_destroy(&lock);
	printf("%d\n", n);
	return 0;
}

