#include<stdio.h>

int main(){
	int height; int stars; int spaces; int i; int j; int k;
	printf("Podaj wielkosc choinki: ");
	scanf("%d", &height);
	
	spaces = height - 1;
	stars=1;

	for(i=0; i < height; i++){
		for(j=0; j<spaces; j++){
			printf(" ");	
		}

	for(k=0; k < stars; k++){
		printf("*");
	}
		spaces--;
		stars+=2;

		printf("\n");
	}
	return 0;
}

