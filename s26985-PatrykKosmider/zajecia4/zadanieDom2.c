#include<stdio.h>
#include<stdlib.h>

typedef struct wezel{
	int dane;
	struct wezel* wezelprzed;
	struct wezel* wezelpo;

}wezel;

void poczatekDane(wezel** lista){
	int liczba;
	printf("Podaj dane: \n");
	scanf("%d", &liczba);
	wezel* noweDane = (wezel*)malloc(sizeof(wezel));
	noweDane->wezelprzed = NULL;
	noweDane->wezelpo = *lista;
	noweDane->dane = liczba;
	wezel* poczatekwezel = *lista;
	if(poczatekwezel == NULL){
		*lista = noweDane;

	} else {
		poczatekwezel->wezelprzed = noweDane;
	       *lista = noweDane;	
	}
	

}


void koniecDane(wezel** lista){
	printf("Podaj dane: \n");
	int liczba;
	scanf("%d", &liczba);
	wezel* noweDane = (wezel*)malloc(sizeof(wezel));
	noweDane->wezelprzed = NULL;
	noweDane->wezelpo = NULL;
	noweDane->dane = liczba;

	if(*lista == NULL){
		*lista = noweDane;
 
	} else {
		wezel* ostatni = *lista;
		while(ostatni->wezelpo != NULL){
			ostatni =  ostatni->wezelpo;
		}
		ostatni->wezelpo = noweDane;
		noweDane->wezelprzed = ostatni;
	}

}

void wyswietldane(wezel* lista){
	wezel* ostatni = lista;
	while(ostatni != NULL){
		printf("%d\n", ostatni->dane);
		ostatni = ostatni->wezelpo;
	
	}


}

int main(){
	wezel* lista = NULL;

	poczatekDane(&lista);
	koniecDane(&lista);
	poczatekDane(&lista);
	poczatekDane(&lista);
	printf("Dane: \n");
	wyswietldane(lista);
	return 0;
}

