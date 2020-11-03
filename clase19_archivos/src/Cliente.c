#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "utn_inputs.h"

static int isValidName(char *string, int length);

static int isValidNumber(char *string, int length);

//---------MEMORIA DINAMICA---------------

int cli_inicializarArrayPunteros(Cliente *array[], int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i] = NULL;
		}
		ret = 0;
	}

	return ret;

}

int cli_getEmptyIndex(Cliente *array[], int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		ret = -2;

		for (int i = 0; i < length; i++) {

			if (array[i] == NULL) {

				ret = i;
				break;

			}
		}
	}

	return ret;
}

int cli_printArray(Cliente *array[], int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i] != NULL) {

				printf(
						"Dirección memoria: %p, Nombre: %s, Altura: %f, Dni: %s, id: %d \n",
						array[i], array[i]->nombre, array[i]->altura,
						array[i]->dni, array[i]->id);

			}
		}
	}

	return ret;

}

Cliente* cli_new(void) {

	Cliente *auxP = NULL;

	auxP = (Cliente*) malloc(sizeof(Cliente) * 1);

	return auxP;

}

Cliente* cli_newParametros(char *nombre, float altura, char *dni, int id) {

	Cliente *auxP = NULL;

	auxP = cli_new();

	if (auxP != NULL) {

		strncpy(auxP->nombre, nombre, MAX_NOMBRE);

		auxP->altura = altura;

		strncpy(auxP->dni, dni, MAX_DNI);

		auxP->id = id;

	}

	return auxP;

}

void cli_delete(Cliente *this) {

	if (this != NULL) {

		free(this);

	}

}

int cli_deleteIndex(Cliente *array[], int length, int index) {

	int ret = -1;

	if (array != NULL && index >= 0 && array[index] != NULL) {

		cli_delete(array[index]);

		array[index] = NULL;

		ret = 0;

	}

	return ret;

}

int cli_setNombre(Cliente *this, char *nombre) {

	int ret = -1;

	if (this != NULL && nombre != NULL) {

		if (isValidName(nombre, MAX_NOMBRE)) {

			strncpy(this->nombre, nombre, MAX_NOMBRE);

		}

	}

	return ret;
}

int cli_getNombre(Cliente *this, char *nombre) {

	int ret = -1;

	if (this != NULL && nombre != NULL) {

		strncpy(nombre, this->nombre, MAX_NOMBRE);

	}

	return ret;
}

int cli_setId(Cliente *this, int id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		this->id = id;

		ret = 0;

	}

	return ret;

}

int cli_getIdTxt(Cliente *this, char *id) {

	int ret = -1;

	if (this != NULL && id != NULL) {

		sprintf(id,"%d",this->id);

		ret = 0;
	}

	return ret;

}

int cli_setIdTxt(Cliente *this, char *id) {

	int ret = -1;

	if (this != NULL && id != NULL) {

		if (isValidNumber(id, MAX_ID)) {

			this->id = atoi(id);

			ret = 0;

		}

	}

	return ret;

}

static int isValidNumber(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && (string[i] == '+' || string[i] == '-')) {

				continue;
			}

			if (string[i] < '0' || string[i] > '9') {

				ret = 0;

				break;

			}
		}
	}
	return ret;

}

static int isValidName(char *string, int length) {

	int ret = 1;
	int flagSpace = 0;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && string[i] >= 'A' && string[i] <= 'Z') {

				continue;
			}

			if (i != 0 && string[i] == ' ' && flagSpace == 0) {

				flagSpace = 1;

				continue;
			}

			if (flagSpace == 1 && string[i] >= 'A' && string[i] < 'Z') {

				flagSpace = 2;
				continue;
			}

			if (string[i] < 'a' || string[i] > 'z') {

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

int cli_getById(Cliente *array[], int length, int id) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= 0) {

		ret = -2;

		for (int i = 0; i < length; i++) {

			if (array[i] != NULL && id == array[i]->id) {

				ret = i;
				break;

			}
		}
	}

	return ret;
}

//---------------------------------------------
int cli_alta(Cliente *array[], int length, int *pId) {

	Cliente bufferCliente;

	Cliente *pCliente;

	int index;

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		index = cli_getEmptyIndex(array, length);

		if (index >= 0) {

			pCliente = cli_new();

			if (pCliente != NULL) {

				if (utn_getNombre(bufferCliente.nombre, "Ingrese nombre \n",
						"Nombre inválido \n", 2) == 0

						&& utn_getFloat(&bufferCliente.altura,
								"Ingrese altura en cm \n", "Número inválido \n",
								0, 300, 2) == 0

						&& utn_getDni(bufferCliente.dni,
								"Ingrese número correspondiente al dni \n",
								"Número inválido \n", 7, 8, 2) == 0) {

					bufferCliente.id = *pId;

					//MEMORIA DINAMICA

					*pCliente = bufferCliente;

					array[index] = pCliente;

					(*pId)++;

					ret = 0;

				}

			}

		}

		else {

			printf("Array completo");

		}
	}

	return ret;
}

// ----------------------------------------

/**
 * Imprime todos los datos del cliente
 * @param pCliente puntero a cliente a imprimir
 * @return 0 Éxito -1 Error
 */
int cliente_imprimir(Cliente *pCliente) {

	int ret = -1;

	if (pCliente != NULL && pCliente->isEmpty == 0) {

		printf("Cliente id %d: %s, altura: %.2f, dni: %s \n", pCliente->id,
				pCliente->nombre, pCliente->altura, pCliente->dni);

		ret = 0;

	}
	return ret;
}

/** \brief Imprime la lista de clientes con sus respectivos datos
 * \param list puntero a array de cliente
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int cliente_imprimirArray(Cliente *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				cliente_imprimir(&array[i]);
			}

		}

		ret = 0;
	}
	return ret;
}

/**
 * Para indicar que todas las posiciones del array están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */

int cliente_iniciar(Cliente *array, int length) {

	int ret = -1;
	if (array != NULL && length > 0) {
		for (int i = 0; i < length; i++) {
			array[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

/**
 * Busca un lugar vacio en el array y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */
int cliente_emptyIndex(Cliente *array, int length, int *indice) {

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

/**
 * Verifica si el array en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int cliente_emptyArray(Cliente *list, int length) {

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

/**
 * Agrega un cliente al array de clientes
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int cliente_alta(Cliente *array, int length, int *pId) {

	Cliente bufferCliente;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (cliente_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getNombre(bufferCliente.nombre, "Ingrese nombre \n",
				"Nombre inválido \n", 2) == 0

				&& utn_getFloat(&bufferCliente.altura,
						"Ingrese altura en cm \n", "Número inválido \n", 0, 300,
						2) == 0

				&& utn_getDni(bufferCliente.dni,
						"Ingrese número correspondiente al dni \n",
						"Número inválido \n", 7, 8, 2) == 0) {

			bufferCliente.id = *pId;

			bufferCliente.isEmpty = 0;

			array[indice] = bufferCliente;

			(*pId)++;

			ret = 0;

		}
	}

	return ret;
}

/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */

int cliente_buscarId(Cliente *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				cliente_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

/**
 * Actualiza uno de los datos del cliente
 * verificando si existe su id
 * @param list puntero a array
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int cliente_modificar(Cliente *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char nombre[MAX_NOMBRE];
	char dni[MAX_DNI];
	float altura;
	int id;

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", 0, 1000, 2) == 0) {

		cliente_buscarId(array, QTY_CLIENTES, id, &indice);

		if (indice != -1
				&& utn_getNumero(&opcion,
						"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar NOMBRE "
								"\n 2-Modificar ALTURA "
								"\n 3-Modificar DNI \n", "Opción inválida \n",
						1, 3, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(nombre, "Ingrese el nuevo nombre \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[indice].nombre, nombre, sizeof(nombre));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getFloat(&altura, "Ingrese la nueva altura en cm\n",
						"Número fuera de rango", 0, 300, 2) == 0) {

					array[indice].altura = altura;

					ret = 0;
				}

				break;

			case 3:

				if (utn_getDni(dni, "Ingrese el nuevo dni \n ",
						"Número inválido \n", MIN_DNI, MAX_DNI, 2) == 0) {

					strncpy(array[indice].dni, dni, MAX_DNI);
					ret = 0;

					break;

				}
			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}

	}

	return ret;
}

/**
 * Pide un empleado d a eliminar por id,
 * verifica que existe y pone bandera Is Empty en 1
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int cliente_baja(Cliente *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		cliente_buscarId(array, QTY_CLIENTES, id, &indice);

		if (indice != -1
				&& utn_getNumero(&option, "Seleccione: 1 para borrar - "
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

/**
 * Ordena los elementos del array
 * en base a nombre y dni de manera ascendente o descendente
 * @param array puntero a array
 * @param largo del array
 * @return 0 Éxito -1 Error
 *
 */
int cliente_ordenarPorNombreDni(Cliente *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Cliente buffer;

	if (array != NULL && length > 0
			&& utn_getNumero(&orden,
					"Seleccione: 1 para Ordenamiento ascendete, "
							"2 para Ordenamiento desdente", "Opción no válida",
					1, 2, 2) == 0) {

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

				if (orden == 1) {

					if (strncmp(array[i].nombre, array[i + 1].nombre,
					MAX_NOMBRE) > 0
							|| (strncmp(array[i].nombre, array[i + 1].nombre,
							MAX_NOMBRE) == 0
									&& array[i].altura > array[i + 1].altura)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}

				else if (orden == 2) {

					if (strncmp(array[i].nombre, array[i + 1].nombre,
					MAX_NOMBRE) < 0
							|| (strncmp(array[i].nombre, array[i + 1].nombre,
							MAX_NOMBRE) == 0
									&& array[i].altura < array[i + 1].altura)) {

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

/**
 * Inserta un cliente en el array con los datos ya cargados
 * @param array Puntero al array
 * @param length Largo del array
 * @param pId Puntero a id
 * @param nombre Datos nombre del cliente
 * @param altura Datos altura del cliente
 * @param dni Datos dni del cliente
 * @return 0 Éxito -1 Error
 */
int cliente_altaForzada(Cliente *array, int length, int *pId, char *nombre,
		float altura, char *dni) {

	Cliente bufferCliente;

	int indice = -1;

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL && nombre != NULL) {

		cliente_emptyIndex(array, length, &indice);

		strncpy(bufferCliente.nombre, nombre, MAX_NOMBRE);
		bufferCliente.altura = altura;
		strncpy(bufferCliente.dni, dni, MAX_DNI);

		bufferCliente.id = *pId;

		bufferCliente.isEmpty = 0;

		array[indice] = bufferCliente;

		(*pId)++;

		ret = 0;

	}

	return ret;

}
