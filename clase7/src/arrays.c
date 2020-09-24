#include <stdio.h>
#include <stdlib.h>


int inicArrayInt(int array[], int lenght) {

	int ret = -1;
	if (array != NULL && lenght > 0) {

		for (int i = 0; i < lenght; i++) {
			array[i] = 0;
		}

		ret = 0;
	}

	return ret;
}

int cargarArrayInt(char *mensajePos, char *mensajeValor, char *mensajeError,
		int array[], int lenght) {

	int ret = -1;
	int i;
	char respuesta;

	if (array != NULL && mensajePos != NULL && mensajeValor != NULL
			&& mensajeError != NULL && lenght > 0) {

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

int imprimirArrayInt(int array[], int lenght) {

	int ret = -1;

	if (array != NULL && lenght > 0) {

		for (int i = 0; i < lenght; i++) {

			printf("%d", array[i]);

		}

		ret = 0;
	}

	return ret;

}




