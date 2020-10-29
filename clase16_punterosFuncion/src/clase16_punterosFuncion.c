/*
 ============================================================================
 Name        : clase16_punterosFuncion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int (*pSaludar) (char*,int); // puntero a funcion


int saludarEsp (char* mensaje, int numero){

	printf("Hola %s - %d \n",mensaje,numero);
	return 0;

}

int saludarIng (char* mensaje, int numero){

	printf("Hello %s - %d",mensaje,numero);
	return 0;

}

void saludo (char* mensaje, int numero, int (*pSaludar) (char*,int)){

	pSaludar(mensaje,numero); //funcion que recibe como parametro otra funcion(puntero)

}

int main(void) {



	saludo ("Pedro",1,saludarEsp);
	saludo ("Pedro",1,saludarIng);


	return EXIT_SUCCESS;
}
