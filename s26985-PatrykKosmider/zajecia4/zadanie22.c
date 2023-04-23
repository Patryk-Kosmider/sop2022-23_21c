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
		return 0;
	}	
	fscanf(plik, "%d", &liczba);
	liczba = liczba + 1;
	linie = malloc(liczba * sizeof(char *));	
	for(i=0; i < liczba; i++){
		linie[i] = malloc(1024 * sizeof(char));
		fgets(linie[i], 1024, plik);
		linie[i][strcspn(linie[i], "\n")] = 0;
	}
	fclose(plik);
	for(i = liczba - 1; i >= 0; i--){
		printf("%s\n", linie[i]);
		free(linie[i]);
	}
		free(linie);
	return 0;
}

