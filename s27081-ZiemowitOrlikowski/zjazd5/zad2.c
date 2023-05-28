#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	
	
	switch (fork()){
		case -1:
			printf("%d Nie udało się utworzyć dziecka!\n", getpid());
			break;
		case 0:
			printf("PID: %d\t PPID: %d\n", getpid(), getppid());
			break;
		default:
			wait(NULL);	
			printf("PID: %d\t PPID: %d\n", getpid(), getppid());
			break;
	}
	return 0;
}


