//WAP in C to implement race-condition in a multi-threaded program
#include<stdio.h>
#include<pthread.h>   //pthread = POSIX thread library.
int n = 0;
void* Th1(){
	int i = 0;
	for(;i<100000;i++)
		n++;
}
void* Th2(){
	int i = 0;
	for(;i<100000;i++) //if you change the no. of incr and decr to say 100000, race condn will occur.
		n--;   //it means every time you run the executable you end up with a different value of n.
}
int main(){
	pthread_t th1;
	pthread_t th2;
	pthread_create(&th1, NULL, Th1,NULL);
	pthread_create(&th2,NULL, Th2, NULL);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	printf("%d\n",n);
	return 0;
}
//Race condition is a prblm in multi-threaded prgrms where two or more threads
//access shared resources concurrently, and the final outcome is upredictable and depends on the relative
//timing or interleaving of thread execution. The threads race to access and modify the shared data without proper synch.

//H/W based tools for synch - Atomic data and ops
//S/W based tools for synch - Semaphores and mutexes.

//Atomic vars support atomic ops that are executed without interruption from
//other threads and such an opn is either completed entirely or not at all and no other thread can 
//observe an intermedite or partially modified state.
