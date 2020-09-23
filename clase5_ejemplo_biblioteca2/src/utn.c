#include <stdio.h>
#include <stdlib.h>

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int ret;
	int num;

	while (reintentos > 0) {
		printf(mensaje);
		if (scanf("%d", &num) == 1) {
			if (num <= maximo && num >= minimo)
				break;
		}
		fpurge(stdin);
		reintentos--;
		printf(mensajeError);
	}

	if (reintentos == 0) {
		ret = -1;
	} else {
		ret = 0;
		*pResultado = num;
	}
	return ret;
}

static int getInt(int *pResultado) {

	int ret = -1;

	char buffer[64];
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strlen(buffer) - 1] = '\0';

	// FUNCIÓN QUE VALIDE LA CADENA SEGÚN CRITERIO ESTABLECIDO
	if (esNumerica(buffer)) {
		//
		*pResultado = atoi(buffer);
		ret = 1;
	}
	return ret;

}

/*
static int esNumerica(char *cadena) {

	int ret = -1;
	int i = 0;
	if (cadena != NULL) {

		while (cadena[i] != '\0') {

			if (cadena[i] < '0' || cadena[i] > '9') {
				break;
			}
			i++;

		}

		if (cadena[i] == '\0')
			ret = 1;
	}
	return ret;

}
*/
int utn_getChar(int *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos) {

	int ret;
	char bufferChar;

	do {
		printf("%s", mensaje);
		fpurge(stdin);
		scanf("%c", &bufferChar);
		if (bufferChar <= maximo && bufferChar >= minimo) {

			*pResultado = bufferChar;
			ret = 0;
			break;

		}

		else {
			printf("%s", mensajeError);
			reintentos--;
		}

	} while (reintentos >= 0);

	return ret;
}

