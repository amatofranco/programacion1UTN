
// FUNCIONES


#include <stdio.h>
#include <stdlib.h>

int suma(int num1, int num2); // PARÁMETROS FORMALES ---- prototipo o FIRMA de la función


int main(void) {

	int resultado;
	int num1;
	int num2;

	printf("Ingrese numero 1 \n");
	scanf("%d", &num1);
	printf("Ingrese numero 2 \n");
	scanf("%d", &num2);

	resultado = suma (num1,num2);



	return EXIT_SUCCESS;

}

int suma(num1, num2){ // PARÁMETROS FORMALES

	int retorno = 1; // Por defecto, 1 = error o no validado

	int total = num1 + num2;
	retorno = 0; // funcion validada, funcionó

	return retorno;
}

