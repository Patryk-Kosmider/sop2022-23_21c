#include<stdio.h>

int main(){
	int f0=0; int f1=1; int f; int n; int i;

	printf("Podaj liczbe wyrazow ciagu Fibonacciego: ");
	scanf("%d", &n);
	
	printf("%d ",f0);
	printf("%d ",f1);

	for(i=0; i < n; i++){
		f=f0+f1;
		printf("%d ",f);
		f0=f1;
		f1=f;
	}

	printf("\n");

	return 0;
}

