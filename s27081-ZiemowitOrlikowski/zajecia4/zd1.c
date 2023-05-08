#include<stdio.h>
#include<stdlib.h>

struct Car{
	int power;
	struct Car *nextCar;
};

struct Car *createCar(const int power){
	struct Car *newCar = NULL;
	newCar = malloc(sizeof(struct Car));
	newCar->power=power;
	newCar->nextCar=NULL;
	printf("Stworzono nowe auto w %p\n", newCar);
	return newCar;
}
void showCar(const struct Car *car){
	if(car == NULL){
       		printf("Auto nie istnieje");
 	}else{
	 	printf("Moc: %d adres w pamięci: %p następny pojazd w: %p\n", car->power,car,car->nextCar);	
	}
}

int main(){
	struct Car *BMW = NULL;
	struct Car *Volvo = NULL;
	struct Car *Skoda = NULL;

	BMW = createCar(500);
	Volvo = createCar(130);
	Skoda = createCar(200);

	BMW->nextCar = Volvo;
	Volvo->nextCar = Skoda;

	showCar(BMW);
	showCar(Volvo);
	showCar(Skoda);

	free(BMW);
	free(Volvo);
	free(Skoda);

	return 0;
}

