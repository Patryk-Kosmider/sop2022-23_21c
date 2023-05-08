#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	int i;
	pid_t processMain = getpid();
	for(i=0; i < 10; i++){
		pid_t processChild = fork();
		 if (processChild == 0){
			printf("PID: %d\t PPID: %d\n", getpid(), getppid());
				sleep(1);
		 } else if (processMain > 0){
			wait(NULL);
			exit(0);
		 } else {
		 	printf("Error");
		 
		 }
	}
	system("pstree -p");
	return 0;
}
