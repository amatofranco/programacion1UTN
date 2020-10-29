#include "Pantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_inputs.h"

/**
 * Imprime todos los datos de una Pantalla
 * @param puntero a estructura Pantalla a imprimir
 * @return 0 Éxito -1 Error
 */

int pantalla_imprimir(Pantalla *pPantalla) {

	int ret = -1;

	char tipo[32];

	switch (pPantalla->tipo) {

	case TIPO_LED:
		strncpy(tipo, "LED", sizeof(tipo));
		break;

	case TIPO_LCD:
		strncpy(tipo, "LCD", sizeof(tipo));
	}

	if (pPantalla != NULL && pPantalla->isEmpty == 0) {

		printf(
				"Pantalla id %d Nombre: %s, direccion: %s, precio: %.2f tipo: %s \n ",
				pPantalla->id, pPantalla->nombre, pPantalla->direccion,
				pPantalla->precio, tipo);

		ret = 0;

	}
	return ret;
}

/** \brief Imprime la lista de Pantallas con sus respectivos datos
 * \param list puntero a array de Pantallas
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
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

/**
 * Para indicar que todas las posiciones del array están vacías,
 * pone la bandera (isEmpty) en TRUE en todas las posiciones
 * \param list puntero al array
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
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

/**
 * Busca un lugar vacio en el array y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int pantalla_emptyIndex(Pantalla *array, int length, int *indice) {

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

/**
 * Agrega una Pantalla al array de Pantallas
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int pantalla_alta(Pantalla *array, int length, int *pId) {

	Pantalla bufferPantalla;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (pantalla_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getNombre(bufferPantalla.nombre, "Ingrese nombre \n",
				"Nombre inválido \n", 2) == 0

				&& utn_getAlfanumerica(bufferPantalla.direccion,
						"Ingrese direccion \n", "Nombre inválido \n", 2) == 0

				&& utn_getFloat(&bufferPantalla.precio, "Ingrese precio",
						"Número inválido \n", MIN_PRECIO, MAX_PRECIO, 2) == 0

				&& utn_getNumero(&bufferPantalla.tipo,
						"Ingrese número correspondiente al tipo: 1 LED 2 LCD \n",
						"Número inválido \n", 1, QTY_TIPOS, 2) == 0) {

			bufferPantalla.id = *pId;

			bufferPantalla.isEmpty = 0;

			array[indice] = bufferPantalla;

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
int pantalla_buscarId(Pantalla *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				pantalla_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

/**
 * Actualiza uno de los datos de una Pantalla
 * en el array, verificando si existe su id
 * @param list puntero al array
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int pantalla_modificar(Pantalla *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char nombre[MAX_NOMBRE];
	char direccion[MAX_DIRECCION];
	int tipo;
	float precio;
	int id;

	if (pantalla_emptyArray(array, length)) {

		printf("No se registra ninguna carga \n");
	}

	else if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		     pantalla_buscarId(array, QTY_PANTALLAS, id, &indice);

		     if (indice != -1 && utn_getNumero(&opcion,
				"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar NOMBRE "
								"\n 2-Modificar DIRECCION "
								"\n 3-Modificar PRECIO "
								"\n 4-Modificar TIPO \n",

						"Opción inválida \n", 1, 4, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(nombre, "Ingrese el nuevo nombre \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[indice].nombre, nombre, sizeof(nombre));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getAlfanumerica(direccion,
						"Ingrese la nueva direccion \n",
						"Direccion Inválida \n", 2) == 0) {

					strncpy(array[indice].direccion, direccion,
							sizeof(direccion));

					ret = 0;
				}

				break;

			case 3:

				if (utn_getFloat(&precio, "Ingrese el nuevo precio\n",
						"Número fuera de rango", MIN_PRECIO, MAX_PRECIO, 2)
						== 0) {

					array[indice].precio = precio;

					ret = 0;
				}

				break;

			case 4:

				if (utn_getNumero(&tipo, "Ingrese el nuevo tipo 1 LED 2 LCD\n ",
						"Número inválido \n", 1, QTY_TIPOS, 2) == 0) {

					array[indice].tipo = tipo;

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
 * Pide una Pantalla del array a eliminar por id,
 * verifica que existe y pone la bandera Is Empty en 1
 * @param list puntero al array
 * @param len largo del array
 * @return
 */

int pantalla_baja(Pantalla *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		pantalla_buscarId(array, QTY_PANTALLAS, id, &indice);

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
 * @param array puntero a array
 * @param largo del array
 * @return 0 Éxito -1 Error
 *
 */
int pantalla_ordenarNomTipo(Pantalla *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Pantalla buffer;

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
									&& array[i].tipo > array[i + 1].tipo)) {

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

/**
 * Inserta una Pantalla en el array con los datos ya cargados
 * @param array Puntero al array
 * @param length Largo del array
 * @param pId Puntero a id
 * @param nombre Datos nombre Pantalla
 * @param direccion Datos direccion Pantalla
 * @param precio Datos precio Pantalla
 * @param tipo Datos tipo de Pantalla
 * @return 0 Éxito -1 Error
 */

int pantalla_altaForzada(Pantalla *array, int length, int *pId, char *nombre,
		char *direccion, float precio, int tipo) {

	Pantalla bufferPantalla;

	int indice = -1;

	int ret = -1;

	if (array != NULL
			&& length > 0&& pId != NULL &&nombre!=NULL &&direccion!=NULL) {

		pantalla_emptyIndex(array, length, &indice);

		strncpy(bufferPantalla.nombre, nombre, MAX_NOMBRE);
		strncpy(bufferPantalla.direccion, direccion, MAX_DIRECCION);

		bufferPantalla.precio = precio;
		bufferPantalla.tipo = tipo;

		bufferPantalla.id = *pId;

		bufferPantalla.isEmpty = 0;

		array[indice] = bufferPantalla;

		(*pId)++;

		ret = 0;

	}

	return ret;

}

