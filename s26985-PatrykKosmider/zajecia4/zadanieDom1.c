#include <stdio.h>
#include<stdlib.h>

typedef struct wezel {
	int dane;
	struct wezel* wezel2;

}wezel;

void Dane(wezel** lista){
	int liczba;
	wezel *noweDane =(wezel*)malloc(sizeof(wezel));
	printf("Podaj dane: \n");
	scanf("%d", &liczba);
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


void usundane(wezel** lista, int dane){
	wezel* usun = *lista;
	wezel* dotylu = NULL;

	while(usun->dane!=dane && usun!=NULL ){
		dotylu = usun;
		usun = usun->wezel2;
	}

	if(dotylu == NULL){
		*lista = usun->wezel2;
	} else {
		dotylu->wezel2 = usun->wezel2;
	}


}

int main(){
	int usun;
	wezel* lista = NULL;
	Dane(&lista);
	Dane(&lista);
	Dane(&lista);
	printf("Dane: \n");
	wyswietldane(lista);
	printf("Usun dane: \n");
	scanf("%d", &usun);
	usundane(&lista, usun);
	printf("Dane po usunieciu: \n");
	wyswietldane(lista);
	return 0;

}

