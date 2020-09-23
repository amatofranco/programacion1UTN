#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) {

		while (reintentos > 0) {

			printf("%s",mensaje);

			fpurge(stdin);

			scanf("%d", &bufferInt);

			if (bufferInt >= minimo && bufferInt <= maximo){

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

