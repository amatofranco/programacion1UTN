

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

/*
	int edad;
	int respuesta;

	respuesta = utn_getNumero(&edad, "Ingrese edad \n", "Error, intente nuevamente \n", 0, 110, 2);

	if (respuesta==0){

		printf("La edad es: %d", edad);

	}
	else{

		printf("Error, la edad no pudo ser ingresada");
	}
	*/

	char letra;
	int respuesta;

	respuesta = utn_getChar(&letra, "Ingrese letra SOLO MAYUSCULA \n", "Error, intente nuevamente \n", 'A', 'Z', 2);

	if (respuesta==0){

		printf("La letra es: %c", letra);

	}
	else{

		printf("Error, la letra no pudo ser ingresada");
	}



	return EXIT_SUCCESS;
}
