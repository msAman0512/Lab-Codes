//Usage of Fork system call to create a muti-process system.
#include<stdio.h>
#include<unistd.h>

int main(){
	fork();
	fork();  //Hello world gets printed 4 times = 2^n. 
	printf("Hello world\n");
	return 0;
}
