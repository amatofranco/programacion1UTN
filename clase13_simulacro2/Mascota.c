#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Mascota.h"
#include "utn_inputs.h"

/**
 * Imprime todos los datos de una Pantalla
 * @param puntero a estructura Pantalla a imprimir
 * @return 0 Éxito -1 Error
 */

int mascota_imprimir(Mascota *pMascota) {

	int ret = -1;

	char tipo[32];

	switch (pMascota->tipo) {

	case 1:
		strncpy(tipo, "Gato", sizeof(tipo));
		break;

	case 2:
		strncpy(tipo, "Perro", sizeof(tipo));
		break;

	case 3:
		strncpy(tipo, "Raro", sizeof(tipo));
		break;



	}

	if (pMascota != NULL && pMascota->isEmpty == 0) {

		printf(
				"Mascota id %d Nombre: %s, Sexo: %s, edad: %d tipo: %s \n ",
				pMascota->id, pMascota->nombre, pMascota->sexo,
				pMascota->edad, tipo);

		ret = 0;

	}
	return ret;
}

/** \brief Imprime la lista de MAscotas con sus respectivos datos
 * \param list puntero a array de Mascota
 * \param len largo del array
 * \return 0 Éxito -1 Error
 *
 */
int mascota_imprimirArray(Mascota *array, int length) {

	int ret = -1;

	if (array != NULL && length > 0) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0) {

				mascota_imprimir(&array[i]);
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
int mascota_iniciar(Mascota *array, int length) {

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

int mascota_emptyIndex(Mascota *array, int length, int *indice) {

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

int mascota_emptyArray(Mascota *list, int length) {

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
 * Agrega una MAscota al array de Mascotas
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int mascota_alta(Mascota *array, int length, int *pId) {

	Mascota bufferMascota;

	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";

	int ret = -1;

	if (array != NULL && length > 0 && pId != NULL) {

		if (mascota_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getNombre(bufferMascota.nombre, "Ingrese nombre \n",
				"Nombre inválido \n", 2) == 0

				&& utn_getChar(bufferMascota.sexo,
						"Ingrese sexo: m o f \n", "Ingreso inválido \n", 1,1,2) == 0

				&& utn_getNumero(&bufferMascota.edad, "Ingrese edad",
						"Número inválido \n", MIN_EDAD, MAX_EDAD, 2) == 0

				&& utn_getNumero(&bufferMascota.tipo,
						"Ingrese número correspondiente al tipo: 1 PERRO 2 GATO 3 RARO \n",
						"Número inválido \n", 1, QTY_TIPOS, 2) == 0) {

			bufferMascota.id = *pId;

			bufferMascota.isEmpty = 0;

			array[indice] = bufferMascota;

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
int mascota_buscarId(Mascota *array, int length, int id, int *indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				mascota_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

/**
 * Actualiza uno de los datos de una MAscota
 * en el array, verificando si existe su id
 * @param list puntero al array
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int mascota_modificar(Mascota *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char nombre[MAX_NOMBRE];
	char sexo[MAX_SEXO];
	int tipo;
	int edad;
	int id;

	if (mascota_emptyArray(array, length)) {

		printf("No se registra ninguna carga \n");
	}

	else if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		     mascota_buscarId(array, QTY_MASCOTAS, id, &indice);

		     if (indice != -1 && utn_getNumero(&opcion,
				"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar NOMBRE "
								"\n 2-Modificar SEXO "
								"\n 3-Modificar EDAD "
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

				if (utn_getChar(sexo,
						"Ingrese Sexo \n",
						"Ingreso invalido \n", 1,1,2) == 0) {

					strncpy(array[indice].sexo, sexo,
							sizeof(sexo));

					ret = 0;
				}

				break;

			case 3:

				if (utn_getNumero(&edad, "Ingrese Edad\n",
						"Número fuera de rango", MIN_EDAD, MAX_EDAD, 2)
						== 0) {

					array[indice].edad = edad;

					ret = 0;
				}

				break;

			case 4:

				if (utn_getNumero(&tipo, "Ingrese tipo 1 PERRO 2 GATO 3 RARO \n ",
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
 * Pide una MAscota del array a eliminar por id,
 * verifica que existe y pone la bandera Is Empty en 1
 * @param list puntero al array
 * @param len largo del array
 * @return
 */

int mascota_baja(Mascota *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		mascota_buscarId(array, QTY_MASCOTAS, id, &indice);

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
int mascota_ordenar(Mascota *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Mascota buffer;

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
 * Inserta una Mascota en el array con los datos ya cargados
 * @param array Puntero al array
 * @param length Largo del array
 * @param pId Puntero a id
 * @param nombre Datos nombre Pantalla
 * @param direccion Datos direccion Pantalla
 * @param precio Datos precio Pantalla
 * @param tipo Datos tipo de Pantalla
 * @return 0 Éxito -1 Error
 */

int mascota_altaForzada(Mascota *array, int length, int *pId, char *nombre,
		char *sexo, int edad, int tipo) {

	Mascota bufferMascota;

	int indice = -1;

	int ret = -1;

	if (array != NULL
			&& length > 0&& pId != NULL &&nombre!=NULL &&sexo!=NULL) {

		mascota_emptyIndex(array, length, &indice);

		strncpy(bufferMascota.nombre, nombre, MAX_NOMBRE);
		strncpy(bufferMascota.sexo, sexo, MAX_SEXO);

		bufferMascota.edad = edad;
		bufferMascota.tipo = tipo;

		bufferMascota.id = *pId;

		bufferMascota.isEmpty = 0;

		array[indice] = bufferMascota;

		(*pId)++;

		ret = 0;

	}

	return ret;

}

