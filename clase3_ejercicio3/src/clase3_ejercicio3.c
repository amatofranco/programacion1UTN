/*
Crear una función que permita ingresar un
numero al usuario, lo retorne y lo muestre.

 */

#include <stdio.h>
#include <stdlib.h>

int getNumero();

int main(void) {

	int numero;

	numero = getNumero();

	printf("El numero es: %d", numero);

	return EXIT_SUCCESS;
}

int getNumero(){

	int num;
	printf("Ingrese numero \n");
	scanf("%d", &num);
	return (num);

}

