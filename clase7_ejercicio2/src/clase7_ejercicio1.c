#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "arrays.h"
#define LENGHT 5 //tamaño del array

void promedioSueldo(float sueldo[], int lenght);
void mostrarEmpleados(int edades[], float sueldo[], int lenght);

int main(void) {

	int edades[LENGHT];
	float sueldo[LENGHT];

	inicArrayInt(edades,LENGHT);
	inicArrayFloat(sueldo,LENGHT);

	cargarArrayInt("Elija la posicion", "Ingrese la edad", "Posicion incorrecta",edades,LENGHT);


	return EXIT_SUCCESS;
}


void promedioSueldo(float sueldo[], int lenght){

	int cont=0;
	int suma=0;
	float promedio = 0;

	for (int i=0; i<lenght;i++){

		if(sueldo[i]!=0){

		suma += sueldo[i];
		cont++;
		}

	}

	if(cont!=0){
	promedio = suma/cont;
	}

	printf("Promedio sueldos: %.2f \n",promedio);
}



void mostrarEmpleados(int edades[], float sueldo[], int lenght){

	for (int i=0; i<lenght;i++){

			if(edades[i]!=0 && sueldo[i]!=0){

			printf("Legajo %d, edad: %d, sueldo: %.2f \n", i+1, edades[i], sueldo[i]);
			}

		}


}


