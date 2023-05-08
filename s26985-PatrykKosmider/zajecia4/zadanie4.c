#include<stdio.h>
int max(int a, int b){
	if( a > b){
		return a;
	} else {
		return b;
	}
}
int min(int a, int b){
	if(a < b){
		return a;
	} else {
		return b;
	}
}
int suma(int a, int b){
	return a + b;
}


int main(){
	int(*f[3])(int,int) = {max,min,suma};
	int i = 0;
	int functionId;
	int elementCount;
	int v;
	int el;
	printf("Podaj functionID: \n");
	scanf("%d", &functionId);
	printf("Podaj ilosc elementow: \n");
	scanf("%d", &elementCount);
	scanf("%d",&v);;
	while(i < elementCount - 1){
		scanf("%d", &el);
		v = f[functionId](v, el);	
	 	i++;
	}
	printf("%d" , v);
	return 0;

}
