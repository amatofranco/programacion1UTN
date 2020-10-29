#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"
#include "utn_inputs.h"


int main(void) {

	int indiceAux;



	Cliente* punterosClientes[QTY_CLIENTES];

	cli_inicializarArrayPunteros(punterosClientes,QTY_CLIENTES);

	indiceAux = cli_getEmptyIndex(punterosClientes,QTY_CLIENTES);

	if(indiceAux>=0){



			// 1 PEDIR DATOS

			//2 GUARDAR LA DIRECCION DEL NUEVO CLIENTE EN ARRAY DE PUNTEROS

			punterosClientes[indiceAux] = pCliente;


		}


	}





	return EXIT_SUCCESS;

}


