#include<stdio.h>
#include<stdlib.h>

struct Car{
	int power;
	struct Car *nextCar;
	struct Car *prevCar;
};

struct Car *createCar(const int power){
	struct Car *newCar = NULL;
	newCar = malloc(sizeof(struct Car));
	newCar->power=power;
	printf("Stworzono nowe auto w %p\n", newCar);
	return newCar;
}
void showCar(const struct Car *car){
	if(car == NULL){
       		printf("Auto nie istnieje");
 	}else{
	 	printf("Moc: %d adres w pamięci: %p poprzedni pojazd w: %p następny pojazd w: %p\n",
				car->power,car,car->prevCar,car->nextCar);	
	}
}

int main(){
	struct Car *BMW = NULL;
	struct Car *Volvo = NULL;
	struct Car *Skoda = NULL;
	
	Volvo = createCar(130);
	BMW = createCar(500);
	Skoda = createCar(200);
	
	BMW->nextCar=Volvo;
	Volvo->nextCar=Skoda;

	Volvo->prevCar=BMW;
	Skoda->prevCar=Volvo;

	showCar(BMW);
	showCar(Volvo);
	showCar(Skoda);

	free(BMW);
	free(Volvo);
	free(Skoda);

	return 0;
}


