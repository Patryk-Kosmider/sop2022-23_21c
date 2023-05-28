#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
int main(){
	int val;


	printf("PID: %d\t PPID: %d\n", getpid(), getppid());
	scanf("%d", &val);

	return 0;
}


