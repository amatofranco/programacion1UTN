#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pantalla.h"
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

void arrayCompleto();



int main(void) {

	Pantalla arrayPantallas[QTY_PANTALLAS];

	int id = MIN_ID;
	int indiceAux;
	int opcion;
	int ret;

	if (pantalla_iniciar(arrayPantallas, QTY_PANTALLAS) == 0) {

		printf("El programa se inició correctamente \n");
	}

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- (Cargar) Alta Pantalla \n "
				"2- Modificar Pantalla \n "
				"3- (Eliminar) Baja Pantalla \n "
				"4- Imprimir Listado de Pantallas \n "
				"5- Salir \n", "Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

				indiceAux = pantalla_emptyIndex(arrayPantallas, QTY_PANTALLAS);

				if (indiceAux >= 0) {

					if (pantalla_alta(arrayPantallas, QTY_PANTALLAS, indiceAux,
							&id) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}
				}

				else {

					arrayCompleto();

				}

				break;

			case 2:

				if (pantalla_emptyArray(arrayPantallas, QTY_PANTALLAS) == 0) {

					if (pantalla_modificar(arrayPantallas, QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				} else {
					arrayVacio();
				}

				break;

			case 3:

				if (pantalla_emptyArray(arrayPantallas, QTY_PANTALLAS) == 0) {

					if (pantalla_baja(arrayPantallas, QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				} else {
					arrayVacio();
				}

				break;

			case 4:

				if (pantalla_emptyArray(arrayPantallas, QTY_PANTALLAS) == 0) {

					if (pantalla_ordenar(arrayPantallas, QTY_PANTALLAS) == 0
					 && pantalla_imprimirArray(arrayPantallas,QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				} else {
					arrayVacio();
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

	char mensaje[] = "No se registra la carga de ningún cliente \n";

	printf("%s", mensaje);

}

void arrayCompleto() {

	char mensaje[] = "No hay mas lugar para realizar una carga \n";

	printf("%s", mensaje);

}


