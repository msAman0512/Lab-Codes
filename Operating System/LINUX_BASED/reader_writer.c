// WAP to implement Reader-Writer Problem of process synchronization using semaphores.
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int num = 1;
int readcount = 0;
sem_t wrt;
pthread_mutex_t mutex; //Creates a binary semaphore of type mutex.
void* writer(void *wno){
	while(1){
		sem_wait(&wrt);
		num = num * 2 % 100;
		printf("Writer %d modified num to %d \n",(*(int *)wno),num);
		sem_post(&wrt);
	}
}

void* reader(void *rno){
	while(1){
		pthread_mutex_lock(&mutex);
		readcount++;
		if(readcount == 1)
			sem_wait(&wrt);
		pthread_mutex_unlock(&mutex);
		printf("Reader %d reads num as %d \n", *((int *)rno),num);
		pthread_mutex_lock(&mutex);
		readcount--;
		if(readcount == 0)
			sem_post(&wrt);
		pthread_mutex_unlock(&mutex);
	}
}
int main(){
	int n_read = 1, n_write = 1;
	pthread_t read[n_read], write[n_write];
	int no[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	sem_init(&wrt, 0, 1);
	for(int i = 0;i<n_read;i++)
		pthread_create(&read[i], NULL, reader, (void *)&no[i]);
	for(int i = 0; i<n_write;i++)
		pthread_create(&write[i], NULL, writer, (void *)&no[i]);
	for(int i = 0; i<n_write;i++)
		pthread_join(read[i], NULL);
	for(int i = 0;i<n_write;i++)
		pthread_join(write[i], NULL);
	sem_destroy(&wrt);
	pthread_mutex_destroy(&mutex);
	return 0;
}
