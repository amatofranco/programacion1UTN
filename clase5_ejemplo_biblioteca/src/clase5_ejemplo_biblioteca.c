
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	int edad;
	int respuesta;

	respuesta = utn_getNumero(&edad, "Ingrese edad \n", "Error, intente nuevamente \n", 0, 110, 2);


	if(respuesta==0){

		printf("La edad es: %d",edad);
	}
	else {

		printf("Se quedo sin reintentos, error!");
	}


	return EXIT_SUCCESS;
}
