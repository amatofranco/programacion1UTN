#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pantalla.h"
#include "utn_inputs.h"


int pantalla_imprimir(Pantalla *pPantalla) {

	int ret = -1;

	if (pPantalla != NULL && pPantalla->isEmpty == 0) {

		printf("Pantalla id %d: %s, precio: %.2f, direccion: %s tipo: %d \n",
				pPantalla->id, pPantalla->nombre, pPantalla->precio, pPantalla->direccion,
				pPantalla->tipo);

		ret = 0;

	}
	return ret;
}

int pantalla_imprimirArray(Pantalla *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				pantalla_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}


int pantalla_iniciar(Pantalla *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int pantalla_emptyIndex(Pantalla *list, int len) {

	int ret = 1;

	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {

			if (list[i].isEmpty == 1) {

				ret = i;
			}
		}
	}

	return ret;
}

int pantalla_emptyArray(Pantalla *list, int length) {

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



int pantalla_alta(Pantalla *array, int length, int indice, int *pId) {


	Pantalla bufferPantalla;


	int ret = -1;

	if (array != NULL && length > 0 && indice >=0 && pId!=NULL) {


		if (utn_getNombre(bufferPantalla.nombre, "Ingrese nombre \n", "Nombre inválido \n", 2)== 0

				&& utn_getNombre(bufferPantalla.direccion, "Ingrese direccion \n", "Dirección inválida \n", 2)== 0
				&& utn_getFloat(&bufferPantalla.precio, "Ingrese precio \n",
				   "Número inválido \n", 0, MAX_PRECIO, 2) == 0

				&& utn_getNumero(&bufferPantalla.tipo,
				   "Ingrese número correspondiente al tipo: 1 LED 2 LCD \n",
				   "Número inválido \n", 1, 2, 2) == 0) {

			bufferPantalla.id = *pId;

			bufferPantalla.isEmpty = 0;

			array[indice] = bufferPantalla;

			(*pId)++;

			ret = 0;

		}

	}
	return ret;
}




int pantalla_buscarId(Pantalla *array, int length, int id) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = i;

				pantalla_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

int pantalla_modificar(Pantalla *array, int length) {


	int ret = -1;
	int index = -1;
	int opcion;
	char idError[] = "No existe pantalla con el Id seleccionado \n";

	char nombre[MAX_NOMBRE];
	char direccion[MAX_DIRECCION];

	int dni;
	float altura;
	int id;


	if (utn_getNumero(&id, "Ingrese el Id de la pantalla a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		index = pantalla_buscarId(array, QTY_PANTALLAS, id);

		if (index != -1
			&& utn_getNumero(&opcion, "Ingrese el número correspondiente a la opción: "
		     "\n 1-Modificar NOMBRE \n 2-Modificar ALTURA \n 3-Modificar DNI \n",
			"Opción inválida \n", 1, 3, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(nombre, "Ingrese el nuevo nombre \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[index].direccion, nombre, sizeof(nombre));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getFloat(&altura, "Ingrese la nueva altura en cm\n",
						"Número fuera de rango", 0, 300, 2)
						== 0) {

					array[index].precio = altura;

					ret = 0;
				}

				break;

			case 3:

				if (utn_getNumero(&dni, "Ingrese el nuevo dni \n ",
					"Número inválido \n", 1000000, 500000, 2) == 0) {

					array[index].tipo = dni;

					ret = 0;

					break;

				}
			}
		}

		else if (index == -1) {
			(printf("%s", idError));
		}

	}

	return ret;
}

int pantalla_baja(Pantalla *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int index = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "El id seleccionado no corresponde a ninguna pantalla \n";

	if (utn_getNumero(&id, "Ingrese el Id de la pantalla a buscar \n",
			"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		index = pantalla_buscarId(array, QTY_PANTALLAS, id);

		if (index != -1 && utn_getNumero(&option, "Seleccione: 1 para borrar - "
			"2 para cancelar operación \n", "Opción inválida \n", 1, 2, 2) == 0 && option == 1) {

			array[index].isEmpty = 1;

			ret = 0;

		}

		else if (index == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}

int pantalla_ordenar(Pantalla *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Pantalla buffer;


	if (array != NULL && length > 0
	   && utn_getNumero(&orden, "Seleccione: 1 para Ordenamiento ascendete, "
	 "2 para Ordenamiento desdente","Opción no válida",1,2,2)==0){

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

				if (orden == 1) {

					if (strncmp(array[i].direccion, array[i + 1].direccion, MAX_DIRECCION) > 0
					    || (strncmp(array[i].direccion, array[i + 1].direccion, MAX_DIRECCION) == 0
						&& array[i].tipo > array[i + 1].tipo)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}

				else if (orden == 2) {

					if (strncmp(array[i].direccion, array[i + 1].direccion, MAX_DIRECCION) < 0
					   || (strncmp(array[i].direccion, array[i + 1].direccion, MAX_DIRECCION) == 0
					   && array[i].tipo < array[i + 1].tipo)) {

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





