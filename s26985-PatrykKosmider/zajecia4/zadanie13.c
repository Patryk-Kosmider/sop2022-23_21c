#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[]){

	int wysokosc = atoi(argv[1]);
	int i;
	int j;
	for(i=0; i < wysokosc; i++){
		for(j=0; j < wysokosc - i; j++){
			printf(" ");
		}
		for(j=0; j < 2 * i - 1; j++){
			printf("*");
		}
	
		printf("\n");
	}
	return 0;	
}

