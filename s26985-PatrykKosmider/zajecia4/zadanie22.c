#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	char **linie;
	int i;
	FILE *plik;
	int liczba;
	if(argc == 2){
		plik = fopen(argv[1], "r");
	} else {
		char plik1[1024];
		printf("Podaj nazwe pliku\n");
		fgets(plik1, 1024, stdin);
		plik1[strcspn(plik1,"\n")] = 0;
		plik = fopen(plik1, "r");
	
	}
	if(!plik){
		printf("Brak pliku\n");
		return 1;
	}	
	fscanf(plik, "%d", &liczba);
	linie = malloc(liczba * sizeof(char *));
	if(linie == NULL){
		printf("Blad alokacji pamieci\n");
		return 1;
	}
	for(i = 0; i < liczba; i++){
		linie[i] = malloc(1024 * sizeof(char));
			if(linie[i] != NULL){
				if(fgets(linie[i],1024,plik) != NULL){
					if(linie[i][0] == '\n'){
					free(linie[i]);
					i--;
					} else {
						linie[i][strcspn(linie[i], "\n")] = 0;
					}	
				} else {
					free(linie[i]);
					i--;
				}
			}
	}	
	fclose(plik);
	for(i = liczba - 1; i >= 0; i--){
		printf("%s\n", linie[i]);
		free(linie[i]);
	}
		free(linie);
	return 0;
}
