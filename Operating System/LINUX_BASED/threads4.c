#include<stdio.h>
#include<pthread.h>

int n = 0;
pthread_mutex_t lock;
void* Th1(void* arg){
	int i = 0;
	for(;i<100000;i++){
		pthread_mutex_lock(&lock);
		n++;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
void* Th2(void*){
	int i = 0;
	for(;i<100000;i++){
		pthread_mutex_lock(&lock);
		n--;
		pthread_mutex_unlock(&lock);
	}
	return NULL;
}
int main(){
	pthread_t th1;
	pthread_t th2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&th1, NULL, Th1, NULL);
	pthread_create(&th2, NULL, Th2, NULL);
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	pthread_mutex_destroy(&lock);
	printf("%d\n", n);
	return 0;
}

// O/P = 0 as race condn avoided