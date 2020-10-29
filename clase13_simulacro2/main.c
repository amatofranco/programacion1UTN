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

	Mascota arrayMascotas[QTY_MASCOTAS];

	int id = MIN_ID;
	int opcion;
	int ret;

	if (mascota_iniciar(arrayMascotas, QTY_MASCOTAS) == 0) {

		printf("El programa se inició correctamente \n");
	}

	mascota_altaForzada(arrayMascotas,QTY_MASCOTAS,&id,"Pichicho","m",10,2);



	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- Alta Mascota \n "
				"2- Modificar Mascota \n "
				"3- Baja Mascota \n "
				"4- Imprimir Listado de Mascota \n "
				"5- Salir \n", "Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

					if (mascota_alta(arrayMascotas, QTY_MASCOTAS, &id) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}

				break;

			case 2:

					if (mascota_modificar(arrayMascotas, QTY_MASCOTAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 3:


					if (mascota_baja(arrayMascotas, QTY_MASCOTAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				break;

			case 4:

					if (mascota_ordenar(arrayMascotas, QTY_MASCOTAS) == 0
					 && mascota_imprimirArray(arrayMascotas,QTY_MASCOTAS) == 0) {

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

