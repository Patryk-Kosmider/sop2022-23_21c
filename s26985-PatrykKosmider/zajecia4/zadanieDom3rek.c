#include <stdio.h>
int fibonacci(int a){
	if(a == 0){
		return 0;
	} else if (a == 1){
		return 1;
	} else {
	
		return fibonacci(a - 2) + fibonacci (a - 1);
	}




}


int main(){
	int sumaFib = 0;
	int ilosc;
	int i;
	printf("Podaj ilosc wyrazow: \n");
	scanf("%d" , &ilosc);
	for(i = 1; i < ilosc; i++){
		sumaFib += fibonacci(i);
	}
	printf("%d\n", sumaFib);



	return 0;


}

