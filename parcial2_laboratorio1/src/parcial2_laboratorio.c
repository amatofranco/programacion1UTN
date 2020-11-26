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
#include <string.h>

#include "LinkedList.h"
#include "Articulo.h"
#include "Controller.h"
#include "utn_inputs.h"

int main(void) {

	LinkedList *listaArticulos = ll_newLinkedList();

	int option = 0;

	int flagFile = 0;

	int flagMap = 0;

	do {

		printf("/****************************************************/\n "
				"Menu:\n"

				"1. Cargar Lista Artículos desde archivo.\n"

				"2. Ordenar Lista de Artículos en base a Articulo(ascendente)\n"

				"3. Imprimir Lista de Artículos\n"

				"4. Aplicar descuentos\n"

				"5. Generar el archivo de salida: mapeado.csv\n"

				"6. Informar Cantidad de Articulos con precio mayor a 100\n"

				"7. Informar Cantidad de Artículos del Rubro 1\n"

				"8. Salir\n"
				"/*****************************************************/\n"

				"");

		utn_getNumero(&option, "Ingrese opcion\n", "Opcion Inválida\n", 1, 8,
				2);

		switch (option) {
		case 1:

			if (flagFile == 1) {

				printf("El archivo ya se cargo anteriormente\n");
			}

			else if (controller_loadFromText(listaArticulos) == 0) {

				printf("Operacion exitosa\n");

				flagFile = 1;
			}

			else {
				printf(
						"No pudo completarse la operación. Se redigirá al menú.\n");

			}

			break;

		case 2:

			if (ll_isEmpty(listaArticulos)) {

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

			if (ll_isEmpty(listaArticulos)) {

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

			if (ll_isEmpty(listaArticulos)) {
				printf(
						"No existen artículos cargados para realizar la operación\n");
			}

			else if (controller_setFinalPrice(listaArticulos) == 0) {

				flagMap = 1;

				printf("Operacion exitosa\n");
			}

			else {

				printf("Se produjo un error. Se redigirá al menú.\n");

			}
			break;

		case 5:

			if (ll_isEmpty(listaArticulos)) {
				printf(
						"No existen artículos cargados para realizar la operación\n");
			}

			else if (!flagMap) {
				printf(
						"No se han aplicado los descuentos para realizar el archivo de salida.\n");

			}

			else if (controller_saveAsText("mapeado.csv", listaArticulos)
					== 0) {

				printf("Se exportaron %d artículos\n", ll_len(listaArticulos));

				printf("Operación exitosa\n");
			}

			else {

				printf("Se produjo un error. Se redigirá al menú.\n");

			}
			break;

		case 6:

			if (ll_isEmpty(listaArticulos)) {
				printf("No existen artículos cargados para realizar la operación\n");
			}

			else if (controller_countMayorCien(listaArticulos) == 0) {

				printf("Operación exitosa\n");

			}
			break;


		case 7:

			if (ll_isEmpty(listaArticulos)) {
				printf("No existen artículos cargados para realizar la operación\n");
			}

			else if (controller_countRubroUno(listaArticulos) == 0) {

				printf("Operación exitosa\n");

			}
			break;

		case 8:

			printf("Saliendo del programa");

		}
	} while (option != 8);

	return EXIT_SUCCESS;
}
