#include<stdio.h>
#include<stdlib.h>

typedef struct wezel{
	int dane;
	struct wezel* wezelprzed;
	struct wezel* wezelpo;

}wezel;

void poczatekDane(wezel** lista){
	int liczba;
	wezel* noweDane = (wezel*)malloc(sizeof(wezel));
	if(noweDane == NULL){
		printf("Blad\n");
		return;
	}
	wezel* poczatekwezel = *lista;
	printf("Podaj dane: \n");
	scanf("%d", &liczba);
	noweDane->wezelprzed = NULL;
	noweDane->wezelpo = *lista;
	noweDane->dane = liczba;
	if(poczatekwezel == NULL){
		*lista = noweDane;

	} else {
		poczatekwezel->wezelprzed = noweDane;
	       *lista = noweDane;	
	}
}


void koniecDane(wezel** lista){
	int liczba;
	wezel* noweDane = (wezel*)malloc(sizeof(wezel));
	if(noweDane == NULL){
		printf("Blad\n");
		return;
	}
	printf("Podaj dane: \n");
	scanf("%d", &liczba);
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

void usundane(wezel** lista, int dane){
	wezel* usun = *lista;
	while(usun->dane!=dane && usun != NULL){
		usun = usun->wezelpo;
	}
	wezel* przed = usun->wezelprzed;
	wezel* po = usun->wezelpo;
	if(po == NULL){
		return;
	} else {
		po->wezelprzed = przed;
	}
	if(usun->wezelprzed == NULL){
		*lista = po;
	} else {
		przed->wezelpo = po;
	}
	free(usun);
}

void freePamiec(wezel* lista){
	wezel* freeDane = lista;
	while(freeDane != NULL){
	wezel* nastepny = freeDane->wezelpo;
	free(freeDane);
	freeDane = nastepny;
	}
}


int main(){
	int usun;
	wezel* lista = NULL;
	poczatekDane(&lista);
	koniecDane(&lista);
	poczatekDane(&lista);
	poczatekDane(&lista);
	printf("Dane: \n");
	wyswietldane(lista);
	printf("Usun dane: \n");
	scanf("%d", &usun);
	usundane(&lista, usun);
	printf("Dane po usunieciu: \n");
	wyswietldane(lista);
	return 0;
	
}

