/*
 ============================================================================
 Name        : pruebaValidaciones.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn_inputs.h"

int main(void) {

	char texto[25];

	if (utn_getTexto(texto, "Ingrese texto", "invalido",1,25,2)==0){

		printf("Ok");
	}

	else{
		printf("mal");
	}

	return EXIT_SUCCESS;
}
