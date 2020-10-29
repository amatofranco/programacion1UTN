#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mascota.h"
#include "utn_inputs.h"

/**
 * Imprime mensaje error
 */
void mensajeError();

/**
 * Imprime mensaje de operación exitosa
 */
void mensajeExito();

/**
 * Imprime mensaje de array vacío
 */
void arrayVacio();

/**
 * Imprime mensaje de array completo
 */

void arrayCompleto();


int main(void) {

	Pantalla arrayPantallas[QTY_MASCOTAS];

	int id = MIN_ID;
	int opcion;
	int ret;

	if (pantalla_iniciar(arrayPantallas, QTY_MASCOTAS) == 0) {

		printf("El programa se inició correctamente \n");
	}

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- Alta Pantalla \n "
				"2- Modificar Pantalla \n "
				"3- Baja Pantalla \n "
				"4- Imprimir Listado de Pantallas \n "
				"5- Salir \n", "Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

					if (pantalla_alta(arrayPantallas, QTY_MASCOTAS, &id) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}

				break;

			case 2:

					if (pantalla_modificar(arrayPantallas, QTY_MASCOTAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 3:


					if (pantalla_baja(arrayPantallas, QTY_MASCOTAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				break;

			case 4:

					if (pantalla_ordenarNomTipo(arrayPantallas, QTY_MASCOTAS) == 0
					 && pantalla_imprimirArray(arrayPantallas,QTY_MASCOTAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 5:
				printf("Saliendo del programa");
			}

		} else {
			mensajeError();
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;

}

void mensajeError() {

	char mensaje[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mensaje);

}

void mensajeExito() {

	char mensaje[] = "Operación exitosa \n";

	printf("%s", mensaje);

}

void arrayVacio() {

	char mensaje[] = "No se registra ninguna carga \n";

	printf("%s", mensaje);

}

void arrayCompleto() {

	char mensaje[] = "No hay mas lugar para realizar una carga \n";

	printf("%s", mensaje);

}

