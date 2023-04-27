#include <stdio.h>
#include<stdlib.h>

typedef struct wezel {
	int dane;
	struct wezel* wezel2;

}wezel;

void Dane(wezel** lista){
	printf("Podaj dane: \n");
	int liczba;
	scanf("%d", &liczba);
	wezel* noweDane =(wezel*)malloc(sizeof(wezel));
	noweDane->dane = liczba;
	noweDane->wezel2 = NULL;
	if(*lista == NULL){
		*lista = noweDane;
	}else{
		wezel* ostatni = *lista;
		while(ostatni->wezel2 != NULL){
			ostatni = ostatni->wezel2;
		
		}
		ostatni->wezel2 = noweDane;
	}



	
};

void wyswietldane(wezel* lista){
	wezel* ostatni = lista;
	while(ostatni != NULL){
		printf("%d\n", ostatni->dane);
		ostatni = ostatni->wezel2;
	}


}



int main(){
	wezel* lista;
	Dane(&lista);
	Dane(&lista);
	Dane(&lista);
	printf("Dane: \n");
	wyswietldane(lista);
	return 0;

}

