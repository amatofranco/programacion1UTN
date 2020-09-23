#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		while (reintentos > 0) {

			printf("%s", mensaje);

			fpurge(stdin);

			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo) {

				*pResultado = bufferInt;
				retorno = 0;
				break;
			}

			else {
				printf("%s", mensajeError);
				reintentos--;
			}

		}

		if (reintentos == 0) {
			retorno = -1;
		}

	}

	return retorno;
}

int inicializarArray(int array[], int lenght) {

	int ret = -1;
	if (array != NULL && lenght > 0) {

		for (int i = 0; i < lenght; i++) {
			array[i] = 0;
		}

		ret = 0;
	}

	return ret;
}

int cargarArrayInt(char *mensajePos, char *mensajeValor, char *mensajeError, int array[], int lenght) {

	int ret = -1;
	int i;
	char respuesta;

	if (array != NULL && lenght > 0) {

		do {
			printf("%s \n", mensajePos);
			scanf("%d", &i);
			if (i >= 0 && i <= lenght) {

				printf("%s \n", mensajeValor);
				scanf("%d", &array[i]);
			} else {
				printf("%s \n", mensajeError);
			}

			printf("Seguir ingresando? (s/n): ");
			fpurge(stdin);
			scanf("%c", &respuesta);

		} while (respuesta != 'n');

		ret = 0;
	}
	return ret;

}
