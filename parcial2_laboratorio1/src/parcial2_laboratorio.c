/*
 ============================================================================
 Name        : parcial2_laboratorio.c
 Author      : Franco Amato
 Version     : 1.0
 ============================================================================
 */

/****************************************************
 Enunciado:
 1) Leer un archivo con los datos de Venta De una Distribuidora de Artículos de Limpieza y Perfumería,
 guardándolos en un linkedList de entidades eArtículo.
 ACLARACION: El nombre del archivo se debe pasar como parámetro por línea de comandos.

 2) Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
 ordenamiento “Artículo” de manera ascendente.

 3) Imprimir por pantalla todos los Artículos de la Distribuidora.
 ACLARACION: Se deberá imprimir la descripción del Rubro.

 4) Desarrollar la función ll_map en la biblioteca linkedList, la cual recibirá la lista y una
 función. La función ll_map ejecutará la función recibida como parámetro por cada ítem de la lista,
 de este modo se realizarán descuentos a los precios según se detalla:

 * CUIDADO DE ROPA: 20% (si el precio es mayor o igual a $120)
 * ELEMENTOS DE LIMPIEZA: 10% (si el monto es menor o igual a $200)

 5) Generar el archivo de salida: mapeado.csv

 *****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "utn_inputs.h"

int main(void) {
		
		LinkedList *listaArticulos = ll_newLinkedList();

		int option = 0;

		int flagFile = 0;

		do {

			printf(
					"/****************************************************/\n "
							"Menu:\n"

							"1. PEDIR AL USUARIO Cargar Lista Artículos desde archivo.\n"

							"2. Ordenar Lista de Artículos en base a Articulo(descendente)\n"

							"3. Imprimir Lista de Artículos\n"

							"4. Aplicar descuentos:\n"

							"CUIDADO DE ROPA 20 si el precio es mayor o igual a $120\n"

							"ELEMENTOS DE LIMPIEZA 10 si el monto es menor o igual a $200\n"

							"5. Generar el archivo de salida: mapeado.csv\n"

							"6. Salir\n"
							"/*****************************************************/\n"

							"");

			utn_getNumero(&option, "Ingrese opcion\n", "Opcion Inválida\n", 1,
					6, 2);

			switch (option) {
			case 1:

				if (flagFile == 1) {

					printf("El archivo ya se cargó anteriormente\n");
				}

				else if (controller_loadFromText("datos.csv", listaArticulos)
						== 0) {

					printf("Operación exitosa\n");

					flagFile = 1;
				}

				else {
					printf("Se produjo un error. Se redigirá al menú.\n");

				}

				break;

			case 2:

				if (ll_len(listaArticulos) == 0) {

					printf(
							"No existen artículos cargados para realizar la operación\n");

				}

				else if (controller_sortArticulo(listaArticulos) == 0) {

					printf("Operación exitosa\n");
				}

				else {

					printf("Se produjo un error. Se redigirá al menú.\n");

				}

				break;

			case 3:

				if (ll_len(listaArticulos) == 0) {

					printf(
							"No existen artículos cargados para realizar la operación\n");

				}

				else if (controller_ListArticulo(listaArticulos) == 0) {

					printf("Operación exitosa\n");
				}

				else {

					printf("Se produjo un error. Se redigirá al menú.\n");

				}
				break;

			case 4:
				break;

			case 5:

				if (ll_len(listaArticulos) == 0) {
					printf(
							"No existen artículos cargados para realizar la operación\n");
				}

				else if (controller_saveAsText("mapeado.csv", listaArticulos)
						== 0) {

					printf("Se guardaron %d artículos\n",
							ll_len(listaArticulos));

					printf("Operación exitosa");
				}

				else {

					printf("Se produjo un error. Se redigirá al menú.\n");

				}
				break;

			}
		} while (option != 6);


	return EXIT_SUCCESS;
}
