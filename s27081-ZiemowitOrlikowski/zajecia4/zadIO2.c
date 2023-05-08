#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 16

int main(int argc, char *argv[]){
	/*Zarzadzanie plikiem*/
	FILE *file = fopen(argv[1], "rb");
    	if (file == NULL) {
        	printf("Nie udało się otworzyć pliku %s\n", argv[1]);
        	return 1;
    	}

	unsigned char buffer[BUFFER_SIZE];
    	size_t bytes_read = BUFFER_SIZE;
    	int offset = 0;
	int i; int j;
	/*Wypisywanie danych z pliku*/
    	while (fread(buffer, sizeof(unsigned char), BUFFER_SIZE, file)) {
        	printf("%08x  ", offset);
        	for (i = 0; i < bytes_read; i++) {
            		printf("%02x ", buffer[i]);
        	}

	/*ASCI*/
        for (j = 0; j < bytes_read; j++) {
            if (buffer[j] >= 32 && buffer[j] <= 126) {
                printf("%c", buffer[j]);
            } else {
                printf(".");
            }
        }
        printf("\n");
        offset += bytes_read;
    }

    fclose(file);

    return 0;

}

