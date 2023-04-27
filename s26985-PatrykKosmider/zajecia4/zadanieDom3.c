#include<stdio.h>

int fibonacci(int a){
	int pom = 0;
	int pom1 = 1;
	int wynik = 1;
	int i;
	int temp;
	for(i = 1; i <= a - 2; i++){
		temp = pom + pom1;
		wynik += temp;
		pom = pom1;
		pom1 = temp;
	}
	return wynik;
}



int main(){
	int sumaFib; 
	int ilosc;
	printf("Podaj ilosc wyrazow: \n");
	scanf("%d", &ilosc);
	sumaFib = fibonacci(ilosc);
	printf("%d",sumaFib);
	return 0;
}

