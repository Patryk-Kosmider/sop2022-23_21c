#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	pid_t process = fork();
	if(process > 0){
		printf("Parent process - PID: %d\t PPID: %d\n",getpid(), getppid());
	} else if (process == 0){
		printf("Child process - PID: %d\t PPID: %d\n", getpid(), getppid());
		wait(NULL);
	} else {
		printf("Error");
	}
	return 0;
}



