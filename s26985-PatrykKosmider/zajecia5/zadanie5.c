#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
	int i;
	int status;
	pid_t processMain;
	for(i = 0; i < 100; i++){
		processMain = fork();
		if(processMain == 0){
			printf("PID: %d\t PPID: %d\n", getpid(), getppid());
			exit(0);
		}
	} 
	
	for(i = 0; i < 100; i++){
		processMain = waitpid(-1, &status, 0);
	
	}
	return 0;
}
