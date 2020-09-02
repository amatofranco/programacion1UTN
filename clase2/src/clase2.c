#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int num;
	int suma = 0;
	char respuesta;

	do {

		printf("Ingrese numero mayor a 0 \n");

		scanf("%d", &num);

		if (num > 0) {
			suma += num;
		}

		else {
			printf("Numero invalido \n");
		}

		printf("Ingresar otro? \n");

		fpurge(stdin);

		scanf("%c", &respuesta);

	}

	while (respuesta == 's');

	printf("La suma es: %d", suma);

	return EXIT_SUCCESS;

}
