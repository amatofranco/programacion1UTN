/*
 crear una funcion que reciba el radio de un círculo y devuelva el área.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //#DEFINE M_PI 3.14159265358979323846264338327950288

float calcularArea(float radio);

int main(void) {

	setbuf(stdout, NULL);

	float radio = 0;
	float area = 0;

	printf("Ingrese radio del círculo \n");
	scanf("%f", &radio);
	area = calcularArea(radio);
	printf("Área del círculo: %.2f", area);

	return EXIT_SUCCESS;
}

float calcularArea(float radio) {

	float res = (radio * radio) * M_PI;

	return res;

}
