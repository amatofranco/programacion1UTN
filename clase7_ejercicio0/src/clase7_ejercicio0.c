/*
 Pedir 5 edades, cargar en array y mostrarlo, usando funcion utn get numero
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

#define SIZE 5

void imprimirArray(int array[], int lenght); // cuando se recibe array como parametro, es un pasaje por referencia (direccion de memoria). Es decir se va a sobreescribir el array

int main(void) {

	int edades[SIZE];
	int edad;

	for (int i = 0; i < SIZE; i++) {

		if (utn_getNumero(&edad, "Ingrese edad: ","Edad invalida, intente de nuevo \n", 1, 110, 2) == 0) {

			edades[i] = edad;
		}

		else {
			printf("Se quedó sin intentos \n");
		}

	}

	imprimirArray(edades,SIZE);


	return EXIT_SUCCESS;
}

void imprimirArray(int array [], int lenght){

	for (int i=0; i<lenght;i++){

		printf("Posicion %d: %d \n", i+1, array[i]);

	}



}
