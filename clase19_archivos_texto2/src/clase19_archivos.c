/*
 ============================================================================
 ARCHIVOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

int main(void) {

	Cliente *punteroCli;

	Cliente *arrayPunterosClientes[QTY_CLIENTES];

	punteroCli = cli_newParametros("Pepe", 200, "3456765", 1);

	if(punteroCli!=NULL){

	arrayPunterosClientes[0] = punteroCli;

	punteroCli = cli_newParametros("Cacho", 100, "1254541", 2);


	arrayPunterosClientes[1] = punteroCli;



	}

	cli_guardarArrayEnArchivo(arrayPunterosClientes, 10,
			"archivo.txt");

	cli_leerArrayEnArchivo(arrayPunterosClientes, 10,
			"archivo.txt");





	return EXIT_SUCCESS;
}
