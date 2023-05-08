#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){
	pid_t b;
	pid_t c;
	pid_t d;
	pid_t e;
	pid_t f;
	pid_t g;
	
	printf("Main process - PID:%d\t PPID:%d\n", getpid(), getppid());

	b = fork();
	if( b == 0 ){
		printf("process B - PID: %d\t PPID: %d\n", getpid(), getppid());
		d = fork();
		if( d == 0){
			printf("process D - PID: %d\t PPID: %d\n", getpid(), getppid());
			exit(0);
		} else if (d > 0){
			wait(NULL);
		} else {
			printf("Error");
		}
		e = fork();
		if( e == 0 ){
			printf("process E - PID: %d\t PPID: %d\n", getpid(), getppid());
			exit(0);
		} else if (e > 0){
			wait(NULL);
		} else {
			printf("Error");
		}
	} else if (b > 0){
		c = fork();
		if(c == 0){
			printf("process C - PID: %d\t PPID:%d\n", getpid(), getppid());
			f = fork();
			if(f == 0){
				printf("process F - PID: %d\t PPID:%d\n", getpid(), getppid());
				exit(0);
			} else if (f > 0){
				wait(NULL);
			} else {
				printf("Error");
			}
			g = fork();
			if(g == 0){
				printf("Process G - PID: %d\t PPID: %d\n", getpid(), getppid());
				exit(0);			
			} else if (g > 0){
				wait(NULL);
			} else {
				printf("Error");
			}
		}else if (c > 0){
			waitpid(c, NULL, 0);
		} else {
			printf("Error");
		}
	}
	return 0;
}
