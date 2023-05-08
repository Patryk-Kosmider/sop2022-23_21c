#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[]){
	pid_t process = fork();
	int i;
	int n = atoi(argv[1]);
	if (process > 0){
		for(i=1; i <= n; i+=2){
			printf("%d\n",i);
		}
		printf("\n");
	} else if (process == 0){
		int wynik;
		for(i=0; i <= n; i++){
			wynik = wynik + i;
		}	
		wait(NULL);
		printf("Suma liczb od 0 do %d : \t %d\n", n, wynik);
		
	} else {
		printf("Error");
	}	
	

	return 0;
}
