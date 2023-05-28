#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>
#include<string.h>

int main(int argc, char *argv[]){
	int i; int j; int result=0; int arg = atoi(argv[1]);
	if(argc < 2){
		printf("Brak argumentów\n");
		return 1;
	
	}
	switch (fork()){
		case -1:
			printf("%d Nie udało się utworzyć dziecka!\n", getpid());
			break;
		case 0:
			printf("Proces dziecka PID: %d\t PPID: %d\n", getpid(), getppid());
			for(i=1; i<arg; i+=2){
				printf("Liczba: %d \n", i);
			}
			printf("Proces dziecka PID: %d się zakończył\n",getpid());
			break;
		default:
			wait(NULL);	
			for(j=0; j<arg; j++){
				result+=j;
			}
			printf("Wynik rodzica(PID: %d) to %d \n", getpid(), result);	
			break;
	}
	
	return 0;
}


