#include<stdio.h>
#include<stdlib.h>
void reverseArr(int arrLength, int arr[]){
	int numb; int k;
	for(k=0; k < arrLength / 2; k++){
		numb = arr[k];
		arr[k] = arr[arrLength - k -1];
		arr[arrLength - k - 1] = numb;
	}
}

int main(int argc, char* argv[]){
	int i; int j;
	FILE *file;
	if(argv[1] != NULL){
		file = fopen(argv[1], "r");
		if (file == NULL) {
			printf("Nie udało się otworzyć pliku.\n");
        		return 1;
		}
	}
	else{
		file = fopen("test", "r");
		if (file == NULL){
			printf("Nie udało się otworzyć pliku.\n");
			return 1;
		}	
	}
	int n;
    	fscanf(file, "%d", &n);
    	int *arr = (int *)malloc(n * sizeof(int));

    	for (i = 0; i < n; i++) {
        	fscanf(file, "%d", &arr[i]);
    	}

    	fclose(file);
	
	reverseArr(n, arr);


	for(j=0; j < n; j++){
		printf("%d\n",arr[j]);
	}
	return 0;
	}

