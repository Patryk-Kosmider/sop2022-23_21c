#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	int i; int liczbaProcesow = 99;
	for(i=0; i< liczbaProcesow; i++){
		pid_t p=0;
		printf("PID: %d\t PPID: %d\n", getpid(), getppid());
		p = fork();		
		if(p > 0){
			wait(NULL);
			break;
		}
	}
	return 0;
}


