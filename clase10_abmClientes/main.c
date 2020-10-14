#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn_inputs.h"

/**
 * Imprime mensaje error
 */
void errorMessage();

/**
 * Imprime mensaje de operación exitosa
 */
void successMessage();

/**
 * Imprime mensaje de array vacío
 */
void arrayVacio();

void arrayCompleto();

int main(void) {

	Cliente arrayClientes[QTY_CLIENTES];

	int id = MIN_ID;
	int indiceAux;
	int opcion;
	int ret;

	if (cliente_iniciar(arrayClientes, QTY_CLIENTES) == 0) {

		printf("El programa se inició correctamente \n");
	}

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- Alta Cliente \n "
				"2- Modificar Cliente \n "
				"3- Baja Cliente \n "
				"4- Imprimir Listado de Clientes \n "
				"5- Salir \n", "Opción no válida  \n", 1, 5, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

				indiceAux = cliente_emptyIndex(arrayClientes, QTY_CLIENTES);

				if (indiceAux >= 0) {

					if (cliente_alta(arrayClientes, QTY_CLIENTES, indiceAux,
							&id) == 0) {
						successMessage();
					} else {
						errorMessage();
					}
				}

				else {

					arrayCompleto();

				}

				break;

			case 2:

				if (cliente_emptyArray(arrayClientes, QTY_CLIENTES) == 0) {

					if (cliente_modificar(arrayClientes, QTY_CLIENTES) == 0) {

						successMessage();
					}

					else {

						errorMessage();
					}

				} else {
					arrayVacio();
				}

				break;

			case 3:

				if (cliente_emptyArray(arrayClientes, QTY_CLIENTES) == 0) {

					if (cliente_baja(arrayClientes, QTY_CLIENTES) == 0) {

						successMessage();
					}

					else {

						errorMessage();
					}

				} else {
					arrayVacio();
				}

				break;

			case 4:

				if (cliente_emptyArray(arrayClientes, QTY_CLIENTES) == 0) {

					if (cliente_ordenarPorNombreDni(arrayClientes, QTY_CLIENTES) == 0
					 && cliente_imprimirArray(arrayClientes,QTY_CLIENTES) == 0) {

						successMessage();
					}

					else {

						errorMessage();
					}

				} else {
					arrayVacio();
				}

				break;

			case 5:
				printf("Saliendo del programa");
			}

		} else {
			errorMessage();
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;

}

void errorMessage() {

	char mError[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mError);

}

void successMessage() {

	char mSuccess[] = "Operación exitosa \n";

	printf("%s", mSuccess);

}

void arrayVacio() {

	char mensaje[] = "No se registra la carga de ningún cliente \n";

	printf("%s", mensaje);

}

void arrayCompleto() {

	char mensaje[] = "No hay mas lugar para realizar una carga \n";

	printf("%s", mensaje);

}

