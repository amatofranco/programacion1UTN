#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Contratacion.h"
#include "utn_inputs.h"

#define QTY_CONTRATACIONES 100


int contratacion_imprimir(Contratacion *pContratacion) {

	int ret = -1;

	if (pContratacion != NULL && pContratacion->isEmpty == 0) {

		printf("Cliente id %d: %s, altura: %.2f, dni: %d \n",
				pContratacion->id, pContratacion->direccion,
				pContratacion->precio, pContratacion->tipo);

		ret = 0;

	}
	return ret;
}

int contratacion_imprimirArray(Contratacion *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				contratacion_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}


int contratacion_iniciar(Contratacion *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

int contratacion_emptyIndex(Contratacion *list, int len) {

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

int contratacion_emptyArray(Contratacion *list, int length) {

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



int contratacion_alta(Contratacion *array, int length, int indice, int *pId) {


	Contratacion bufferContratacion;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";


	int ret = -1;

	if (array != NULL && length > 0 && indice >=0 && pId!=NULL) {


		if (utn_getNombre(bufferContratacion.direccion, "Ingrese nombre \n", "Nombre inválido \n", 2)== 0

				&& utn_getFloat(&bufferContratacion.precio, "Ingrese altura en cm \n",
				   "Número inválido \n", 0, 300, 2) == 0

				&& utn_getNumero(&bufferContratacion.tipo,
				   "Ingrese número correspondiente al dni \n",
				   "Número inválido \n", 1000000, 50000000, 2) == 0) {

			bufferContratacion.id = *pId;

			bufferContratacion.isEmpty = 0;

			array[indice] = bufferContratacion;

			(*pId)++;

			ret = 0;

		}

		else if (indice == -1){

			printf("%s",arrayCompleto);

		}
	}
	return ret;
}




int contratacion_buscarId(Contratacion *array, int length, int id) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = i;

				contratacion_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

int contratacion_modificar(Contratacion *array, int length) {


	int ret = -1;
	int index = -1;
	int opcion;
	char idError[] = "No existe un cliente con el Id seleccionado \n";

	char nombre[MAX_DIRECCION];
	int dni;
	float altura;
	int id;


	if (utn_getNumero(&id, "Ingrese el Id del cliente a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		index = contratacion_buscarId(array, QTY_CONTRATACIONES, id);

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

int contratacion_baja(Contratacion *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int index = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "El id seleccionado no corresponde a ningún empleado \n";

	if (utn_getNumero(&id, "Ingrese el Id del empleado a buscar \n",
			"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		index = contratacion_buscarId(array, QTY_CONTRATACIONES, id);

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

int contratacion_ordenar(Contratacion *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Contratacion buffer;


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


