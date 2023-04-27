#include<stdio.h>
int forAll(int *tab, int n, int(*f)(int,int)){
	int res = tab[0];
	int i;
	for(i = 1; i < n; i++){
		res = f(res, tab[i]);
	}
	return res;
}


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
	int tab[] = {1,2,4,10,5};
	int n = sizeof(tab) / sizeof(tab[0]);
	int wynik = forAll(tab, n, max);
	printf("%d\n" , wynik);
	return 0;

}

