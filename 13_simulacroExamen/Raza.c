#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Raza.h"
#include "utn_inputs.h"

int raza_imprimir(Raza *pRaza) {

	int ret = -1;

	char tamaño[10];

	switch(pRaza->tamaño){

	case 1:

		strncpy(tamaño, "chico",10);
		break;
	case 2:
		strncpy(tamaño, "mediano",10);
		break;
	case 3:
		strncpy(tamaño, "grande",10);
		break;

	}

	if (pRaza != NULL && pRaza->isEmpty == 0) {

		printf("Raza id %d: %s, tamaño: %s pais de origen: %s \n", pRaza->id,
				pRaza->descripcion, tamaño, pRaza->pais);

		ret = 0;

	}
	return ret;
}

int raza_imprimirArray(Raza *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				raza_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}

int raza_iniciar(Raza *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int raza_emptyIndex(Raza *array, int length, int* indice) {

	int ret = -1;

	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 1) {

				ret = 0;
				*indice = i;
				break;

			}
		}
	}

	return ret;
}

int raza_emptyArray(Raza *list, int length) {

	int ret = 1; // TRUE

	if (list != NULL && length > 0) {
		for (int i = 0; i < length; i++) {

			if (list[i].isEmpty == 0) {

				ret = 0;
				break;
			}
		}
	}

	return ret;
}

int raza_alta(Raza *array, int length, int *pId) {

	Raza bufferCliente;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (raza_emptyIndex(array, length, & indice)==-1){


			printf("%s",arrayCompleto);

		}

		else if (utn_getNombre(bufferCliente.descripcion, "Ingrese nombre \n",
					"Nombre inválido \n", 2) == 0


					) {

				bufferCliente.id = *pId;

				bufferCliente.isEmpty = 0;

				array[indice] = bufferCliente;

				(*pId)++;

				ret = 0;

			}
		}

	return ret;
}

int raza_buscarId(Raza *array, int length, int id, int* indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				raza_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

int raza_modificar(Raza *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char nombre[MAX_DESCRIPCION];
	int id;

	if(array!=NULL && length>0 &&
	   utn_getNumero(&id, "Ingrese el Id a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		raza_buscarId(array, QTY_RAZAS, id, &indice);

		if (indice != -1 && utn_getNumero(&opcion,
			"Ingrese el número correspondiente a la opción: "
			"\n 1-Modificar NOMBRE "
			"\n 2-Modificar ALTURA "
			"\n 3-Modificar DNI \n",
			"Opción inválida \n", 1, 3, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(nombre, "Ingrese el nuevo nombre \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[indice].descripcion, nombre, sizeof(nombre));

					ret = 0;
				}

				break;

			case 2:

				break;

			case 3:


					break;

				}
			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}



	return ret;
}

int raza_baja(Raza *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array!=NULL && length>0 &&
		utn_getNumero(&id, "Ingrese el Id a buscar \n",
		"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		raza_buscarId(array, QTY_RAZAS, id,&indice);

		if (indice != -1 && utn_getNumero(&option, "Seleccione: 1 para borrar - "
			"2 para cancelar operación \n", "Opción inválida \n", 1,
			2, 2) == 0 && option == 1) {

			array[indice].isEmpty = 1;

			ret = 0;

		}

		else if (indice == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}

int raza_ordenar(Raza *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Raza buffer;

	if (array != NULL && length > 0
			&& utn_getNumero(&orden,
					"Seleccione: 1 para Ordenamiento ascendete, "
							"2 para Ordenamiento desdente", "Opción no válida",
					1, 2, 2) == 0) {

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

				if (orden == 1) {

					if (strncmp(array[i].descripcion, array[i + 1].descripcion,
							MAX_DESCRIPCION) > 0
							|| (strncmp(array[i].descripcion, array[i + 1].descripcion,
									MAX_DESCRIPCION) == 0
									&& array[i].tamaño > array[i + 1].tamaño)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}

				else if (orden == 2) {

					if (strncmp(array[i].descripcion, array[i + 1].descripcion,
							MAX_DESCRIPCION) < 0
							|| (strncmp(array[i].descripcion, array[i + 1].descripcion,
									MAX_DESCRIPCION) == 0
									&& array[i].tamaño < array[i + 1].tamaño)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}
			}

			length--;

		} while (flagSwap == 1);

		ret = 0;

	}
	return ret;
}

int raza_altaForzada(Raza* array, int length, int* pId, char* nombre, float altura, char* dni){

	Raza bufferCliente;

		int indice = -1;

		int ret = -1;

		if (array != NULL && length > 0 && pId != NULL &&nombre!=NULL) {


			       raza_emptyIndex(array, length, &indice);

			       strncpy(bufferCliente.descripcion, nombre, MAX_DESCRIPCION);


					bufferCliente.id = *pId;

					bufferCliente.isEmpty = 0;

					array[indice] = bufferCliente;

					(*pId)++;

					ret = 0;

				}

		return ret;



}
