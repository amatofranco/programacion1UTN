/*
 * Realizar un menú con:
 A) Saludar
 B) Brindar.
 C) Despedirse.
 D) Salir.

 Nota:

 - Antes de salir preguntar si "esta seguro que desea salir?"
 - Si brinda sin hacer saludado, debe avisar "Debe saludar antes de brindar" y no dejar continuar.
 - Si se despide antes de saludar debe avisar "Debe saludar antes de despedirse" y no dejar continuar.
 - Si se despide antes de brindar debe avisar "Debe brindar antes de despedirse" y no dejar que continue.

 */

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h> // contiene getchar()

	int main(void) {

	char respuesta;
	int flagSaludar = 0;
	int flagBrindar = 0;

		do {

		printf("Elija una opción: \n a - Saludar \n b - Brindar \n c - Despedirse \n d - Salir \n");
		fpurge(stdin);
		respuesta = getchar();

		switch (respuesta) {

		case 'a':
			flagSaludar = 1;
			printf("Hola! \n");
			break;

		case 'b':
			flagBrindar = 1;
			if (flagSaludar == 0) {
				printf("Debe saludar antes de brindar. \n");
			}

			else {
				system("clear");
				printf("Chin chin! \n");
			}
			break;

		case 'c':
			system("clear");

			if (flagSaludar == 0) {
				printf("Debe saludar antes de despedirse \n");
			}

			else if (flagBrindar == 0) {
				printf("Debe brindar antes de despedirse \n");
			}

			else {
				printf("Chau \n");
			}
			break;

		case 'd':
			printf("Salir? s/n \n");
			fpurge(stdin);
			scanf("%c", &respuesta);
			break;
		}


	} while (respuesta != 's');


	return EXIT_SUCCESS;
}
