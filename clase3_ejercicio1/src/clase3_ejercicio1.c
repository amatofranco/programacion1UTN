/*
Ingresar dos numeros y que la funcion muestre el resultado.

 */

#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int main(void) {

	int valor1;
	int valor2;
	int resultado;

	printf("Ingrese valor 1: \n");
	scanf("%d", &valor1);
	printf("Ingrese valor 2: \n");
	scanf("%d", &valor2);

	resultado = sumar(valor1, valor2);

	printf("El resultado es: %d", resultado);

	return EXIT_SUCCESS;
}


