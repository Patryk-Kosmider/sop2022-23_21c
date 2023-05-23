#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	FILE *plik = fopen(argv[1], "r");
	if(!plik){
		printf("Brak Pliku");
		return 1;
	} else {
		char linia[10];
		while(fgets(linia, sizeof(linia), plik)){
			printf("%s", linia);
		
		}
	}
	fclose(plik);
	return 0;
}

