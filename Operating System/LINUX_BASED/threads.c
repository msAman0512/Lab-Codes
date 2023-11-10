//WAP to create a multi-threaded program using posix-thread library.
#include<stdio.h>
#include<pthread.h>

void* Th1(void*){
	printf("I am in thread1\n");  //Both the threads will run simultaneously.
	return NULL;
}
void* Th2(void*){
	printf("I am in thread2\n");
	return NULL;
}
int main(){
	pthread_t th1;
	pthread_t th2;
	pthread_create(&th2, NULL,Th2, NULL); //the 4th argument is the value of the argument that you provide the function.
	pthread_create(&th1, NULL,Th1, NULL);  //This is basically a call to the functions Th1 and Th2..
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	return 0;
}
