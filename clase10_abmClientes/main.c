#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
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

	Cliente arrayClientes[QTY_CLIENTES];

	int id = MIN_ID;
	int opcion;
	int ret;

	if (cliente_iniciar(arrayClientes, QTY_CLIENTES) == 0) {

		printf("El programa se inició correctamente \n");
	}

	cliente_altaForzada(arrayClientes,QTY_CLIENTES,&id,"Juan Perez",200.5,"34567543");

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

					if (cliente_alta(arrayClientes, QTY_CLIENTES, &id) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}

				break;

			case 2:

					if (cliente_modificar(arrayClientes, QTY_CLIENTES) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 3:


					if (cliente_baja(arrayClientes, QTY_CLIENTES) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				break;

			case 4:

					if (cliente_ordenarPorNombreDni(arrayClientes, QTY_CLIENTES) == 0
					 && cliente_imprimirArray(arrayClientes,QTY_CLIENTES) == 0) {//

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

