#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]){

	FILE *plik = fopen(argv[1], "r");
	char linia[10];
	while(fgets(linia, sizeof(linia), plik)){
		printf("%s", linia);
	
	}
	return 0;
}

