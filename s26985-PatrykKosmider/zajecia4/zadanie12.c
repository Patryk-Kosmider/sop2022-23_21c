#include <stdio.h>

int main(){
	int wynik;
	int liczba;
	printf("By zakonczyc dzialanie programu podaj 0\n");
	do{
		printf("Podaj liczbe:\n");
		scanf("%d",&liczba);
		wynik = wynik + liczba;
	}while(liczba != 0);
	return wynik;
}

