/*
 De una compra debes ingresar una cantidad indeterminada de productos,
 validando los siguientes datos:
 marca, precio, peso en kilogramos, tipo(sólido o líquido)
 a)informar el peso total de la compra.
 b)la marca del más caro de los líquidos
 c)la marca del más barato de los sólidos
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char respuesta;
	char marca;
	float precio;
	int peso;
	char tipo;
	int acumPeso = 0;
	int flagLiquido = 0;
	float maxLiquido;
	int flagSolido = 0;
	float minSolido;
	char marcaSolido;
	char marcaLiquido;

	do {

		printf("Ingrese marca \n");

		fpurge(stdin);

		scanf("%c", &marca);

		do {

			printf("Ingrese precio \n");
			scanf("%f", &precio);

		}

		while (precio <= 0 || precio >= 1000);

		do {

			printf("Ingrese peso en kg \n");
			fpurge(stdin);
			scanf("%d", &peso);

		}

		while (peso <= 0 || peso > 1000);

		do {
			printf("Ingrese tipo: s - l \n");
			fpurge(stdin);
			scanf("%c", &tipo);
		} while (!(tipo == 's' || tipo == 'l'));

		acumPeso += peso;

		if (tipo == 's') {

			if (flagSolido == 0 || precio < minSolido) {

				minSolido = precio;

				marcaSolido = marca;

				flagSolido = 1;

			}

		}

		else {

			if (flagLiquido == 0 || precio > maxLiquido) {

				maxLiquido = precio;

				marcaLiquido = marca;

				flagLiquido = 1;

			}

		}

		printf("¿Agregar otro producto? s-n \n");
		fpurge(stdin);
		scanf("%c", &respuesta);

	}

	while (respuesta == 's');

	printf("Peso total de la compra: %d \n", acumPeso);
	printf("Marca del Solido mas barato: %c \n", marcaSolido);
	printf("Marca del Líquido más caro: %c \n", marcaLiquido);

	return EXIT_SUCCESS;
}
