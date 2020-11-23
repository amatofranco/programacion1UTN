/*
 ============================================================================
 Name        : clase20_punteroAFuncion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void sumar (int a, int b, int* pResultado);

void restar (int a, int b, int* pResultado);

void dividir (int a, int b, int* pResultado);

typedef void (*Operacion)(int, int, int*); // TYPEDEF: Limpiamos el codigo quedandonos solo con el nombre del puntero a la uncion

// int calcular (int a, int b, void (*Funcion)(int,int,int*));

int calcular (int a, int b, Operacion pOperacion);


int main(void) {


	int resultado;

	resultado = calcular(5,5,dividir);

	printf("%d",resultado);


	return EXIT_SUCCESS;
}

void sumar (int a, int b, int* pResultado){


	*pResultado = a + b;


}


void restar (int a, int b, int* pResultado){


	*pResultado = a - b;


}


void dividir (int a, int b, int* pResultado){


	*pResultado = a / b;


}

int calcular (int a, int b, void (*pFuncion)(int, int, int*)){

	int resultado;

	pFuncion (a,b,&resultado);



	return resultado;
}
