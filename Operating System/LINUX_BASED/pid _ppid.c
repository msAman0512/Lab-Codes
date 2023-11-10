// WAP to use getpid() and getppid().
#include<stdio.h>
#include<unistd.h>

int main(){
	int m = fork();
	if(m == 0)
		fork();
	printf("I am the process with pid = %d and ppid = %d\n", getpid(), getppid());
	return 0;
}
