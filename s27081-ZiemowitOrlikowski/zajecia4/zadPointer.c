#include<stdlib.h>
#include<stdio.h>

/*funkcje*/
int max(int a, int b){
	if(a >= b){
		return a;
	}else{
		return b;
	}	
}

int min(int a, int b){
	if(a <= b){
		return a;
	}else{
		return b;
	}
}

int sum(int a, int b){
	return a+b;
}
int main(int argc, char* argv[]){
	int functionId;
	int elementCount;
	int i; int j; int v;
		
	printf("Podaj numer funkcji: ");
	scanf("%d", &functionId);

	/*Sprawdzaine argumentów*/
	if(functionId >= 0 && functionId <= 2){
		
		printf("Podaj liczbę elementów ciągu: ");
		scanf("%d", &elementCount);
		
		int numbArray[elementCount];

		int (*array[])(int, int) = {max, min, sum};

		for(i=0; i < elementCount; i++){
			scanf("%d", &numbArray[i]);	
		}
		
		v=numbArray[0];
		for(j=1; j < elementCount; j++){
			v+= (*array[functionId])(v,numbArray[j]);
		}

		printf("Wynik: %d\n", v);

		return 0;
	}else{
		printf("Błędne argumenty\n");
		return 1;
	}
}

