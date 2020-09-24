#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int esNumerica(char *cadena);

static int myGets(char *string, int lenght);

static int getInt(int *pResultado);

/**
 * Toma el dato ingresado solo si esta formado solo por numeros enteros
 * @param pResultado
 * @return 0 operacion exitosa -1 error
 */

static int esNumerica(char *cadena) {

	int ret = 1;

	if (cadena != NULL && strlen(cadena) > 0) {

		for (int i = 0; cadena[i] != '\0'; i++) {

			if (cadena[i] > '9' || cadena[i] < '0') {

				ret = 0;
				break;
			}
		}
	}

	return ret;

}

/**
 * Lee de stdin hasta encontrar \n o un maximo de longitud
 * de caracteres -1
 * @param string cadena a leer
 * @param lenght longitud cadena
 * @return 0 operación exitosa -1 error
 */

static int myGets(char *string, int lenght) {

	int ret = -1;

	if (string != NULL && lenght > 0) {

		fpurge(stdin);
		fgets(string, lenght, stdin);

		if (string[strlen(string) - 1] == '\n') {

			string[strlen(string) - 1] = '\0';

		}

		ret = 0;
	}

	return ret;

}

/**
 * Verifica si la cadena ingresada es numerica
 * @param cadena La cadena ingresada
 * @return 0 FALSO 1 VERDADERO
 */

static int getInt(int *pResultado) {

	int ret = -1;
	char buffer[4000];
	myGets(buffer, sizeof(buffer));
	if (esNumerica(buffer)) {

		*pResultado = atoi(buffer);
		ret = 0;
	}

	return ret;
}

int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError,
		int minimo, int maximo, int reintentos) {

	int retorno = -1;
	int buffer;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL
			&& minimo <= maximo && reintentos >= 0) {

		while (reintentos > 0) {

			printf("%s", mensaje);

			// scanf("%d", &buffer);

			if (getInt(&buffer) == 0 && buffer >= minimo && buffer <= maximo) {

				*pResultado = buffer;
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

