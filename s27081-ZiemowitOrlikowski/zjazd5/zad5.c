#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

int main(){
	int i; int liczbaProcesow = 100;
	pid_t masterPID = getpid();
	
	for(i=0; i< liczbaProcesow; i++){
		pid_t p=0;
		p = fork();		
		if(p == 0){
			printf("PID: %d\t PPID: %d\n", getpid(), getppid());
			sleep(2);
			break;
		}
	}
	
	if(masterPID == getpid()){
		waitpid(-1,NULL,0);
		printf("Rodzic %d przestał czekać\n", getpid());
	}
	return 0;
}


