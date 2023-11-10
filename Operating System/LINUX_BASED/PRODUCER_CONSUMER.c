// WAP to implement Producer-Consumer Problem
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#define N 100
sem_t empty, full, mutex;
int buffer[N], num = 0;
void* producer(void*){
	int in = 0;
	while(1){
	sem_wait(&empty);
	sem_wait(&mutex);
	num = (num+1)%100;
	buffer[in] = num;
	in = (in+1)%N;
	printf("Producer produced item %d\n", num);
	sem_post(&mutex);
	sem_post(&full);
	}
	return NULL;
}
void* consumer(void*){
	int out = 0,item ;
	while(1){
	sem_wait(&full);
	sem_wait(&mutex);
	item = buffer[out];
	out = (out+1)%N;
	printf("consumer consumed item %d\n", item);
	sem_post(&mutex);
	sem_post(&empty);
	}
	return NULL;
}
int main(){
	pthread_t prod, cons;
	sem_init(&empty, 0 ,N);
	sem_init(&full, 0, 0);
	sem_init(&mutex, 0, 1);
	pthread_create(&prod, NULL, producer, NULL);
	pthread_create(&cons, NULL, consumer, NULL);
	pthread_join(prod, NULL);
	pthread_join(cons, NULL);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
	return 0;
}
