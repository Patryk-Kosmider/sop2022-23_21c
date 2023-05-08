#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]){
        FILE *plik = fopen(argv[1], "rb");
	if(plik == NULL){
		printf("Błąd pliku\n");
		return 0;
	
	} else {
        	int ilosclinii;
		int group;
		int i;
        	char *linia;
		int poczatek = 0;
		printf("Podaj sposob grupowania: \n");
		scanf("%d", &group);
		linia=malloc(sizeof(char) * group);
        	printf("Loading file: %s\n", argv[1]);
        	while((ilosclinii = fread(linia, 1 , group, plik))){
			printf("%08x :", poczatek);
			for(i = 0; i < ilosclinii; i++){
				if(i < group ){
					printf(" %02x ", linia[i]);
				} else {
					printf("  ");
			
				}
			}
			printf("  ");
        		for(i = 0; i < group; i++){
				if(i < ilosclinii){	
					printf("%c", isprint(linia[i]) ? linia[i] : '.');
				}
				if(i == group) {
					break;
			
				}	
			}

		
			printf("\n");
			poczatek = poczatek + group;
		}	
       
        printf("Closing file: %s\n", argv[1]);
        fclose(plik);
	free(linia);
	return 0;
	       

	}
}

