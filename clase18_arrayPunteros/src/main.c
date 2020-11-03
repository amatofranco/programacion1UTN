#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn_inputs.h"

int main(void) {

	int emptyIndex;

	int deleteIndex;

	int id=0;

	Cliente *arrayPunterosCliente[QTY_CLIENTES];

	if (cli_inicializarArrayPunteros(arrayPunterosCliente, QTY_CLIENTES) == 0) {

		printf("Init ok\n");

		emptyIndex = cli_getEmptyIndex(arrayPunterosCliente, QTY_CLIENTES);

		if (emptyIndex >= 0) {

			arrayPunterosCliente[emptyIndex] = cli_newParametros("Juan", 180,
					"34567876", 1);

		}

		emptyIndex = cli_getEmptyIndex(arrayPunterosCliente, QTY_CLIENTES);

		if (emptyIndex >= 0) {

			arrayPunterosCliente[emptyIndex] = cli_newParametros("Cacha", 120,
					"45555555", 8);

		}


		cli_printArray(arrayPunterosCliente,QTY_CLIENTES);

		deleteIndex = cli_getById(arrayPunterosCliente,QTY_CLIENTES,8);

		if(deleteIndex>=0){

			if (cli_deleteIndex(arrayPunterosCliente,QTY_CLIENTES,deleteIndex)==0){

				printf("Delete OK\n");

			}
		}

		cli_printArray(arrayPunterosCliente,QTY_CLIENTES);

		if (cli_alta(arrayPunterosCliente,QTY_CLIENTES,&id)==0){


			printf("alta ok\n");
		}

		cli_printArray(arrayPunterosCliente,QTY_CLIENTES);




	}



	return EXIT_SUCCESS;

}

