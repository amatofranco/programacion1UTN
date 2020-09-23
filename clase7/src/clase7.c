/*
---Arrays----
Ingresar la carga de 5 empleados con nro legajo (correspondiente al nro de indice), edad y sueldo.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main(void) {

	int edades [MAX];
	int sueldo [MAX];
	int acumSueldo = 0;
	float promedio = 0;

	for(int i = 0; i<MAX; i++){

		printf("Ingrese edad, legajo %d:",i);
		scanf("%d",&edades[i]);
		printf("Ingrese sueldo, legajo %d:",i);
		scanf("%d",&sueldo[i]);
		acumSueldo += sueldo[i];
	}

	promedio = acumSueldo/MAX;


	printf("Suma sueldos: %d",acumSueldo);
	printf("\nPromedio sueldo: %.2f", promedio);


	return EXIT_SUCCESS;
}
