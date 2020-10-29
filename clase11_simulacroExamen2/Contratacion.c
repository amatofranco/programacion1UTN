#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Contratacion.h"
#include "Pantalla.h"

#include "utn_inputs.h"

int contratacion_imprimir(Contratacion *pContratacion) {

	int ret = -1;

	if (pContratacion != NULL && pContratacion->isEmpty == 0) {

		printf("Contratacion id %d, Archivo: %s, cuit: %s , dias: %d, idPantalla: %d \n", pContratacion->id,
				pContratacion->archivo, pContratacion->cuit, pContratacion->dias, pContratacion->idPantalla);

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

int contratacion_emptyIndex(Contratacion *array, int length, int* indice) {

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

int contratacion_alta(Contratacion *array, int length, int *pId, int idPantalla) {

	Contratacion bufferContra;

	int ret = -1;
	int indice;

	char arrayCompleto[] = "No hay más espacio para realizar una carga \n";


	if (array != NULL && length > 0 && pId != NULL) {

		if (contratacion_emptyIndex(array, length, &indice) == -1) {

			printf("%s", arrayCompleto);

		}

		else if (utn_getAlfanumerica(bufferContra.archivo,"Inserte nombre de archivo \n","Nombre invalido \n",2)==0

			    && utn_getDni(bufferContra.cuit,"Ingrese número correspondiente al cuit \n",
			    "Número inválido \n", 7, 8, 2) == 0

		        && utn_getNumero(&bufferContra.dias,
		       "Ingrese cantidad de dias \n","Numero invalido \n",1,MAX_DIAS,2)==0)

		{

			    bufferContra.idPantalla = idPantalla;

				bufferContra.id = *pId;

				bufferContra.isEmpty = 0;

				array[indice] = bufferContra;

				(*pId)++;

				ret = 0;

			}
		}

	return ret;
}

int contratacion_buscarId(Contratacion *array, int length, int id, int* indice) {

	int ret = -1;

	if (array != NULL && length > 0 && id >= MIN_ID) {

		for (int i = 0; i < length; i++) {

			if (array[i].isEmpty == 0 && array[i].id == id) {

				ret = 0;

				*indice = i;

				contratacion_imprimir(&array[i]);
				break;

			}

		}
	}

	return ret;
}

int contratacion_modificar(Contratacion *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char archivo[MAX_ARCHIVO];
	char cuit[MAX_DNI];
	int dias;
	int id;

	if(array!=NULL && length>0 &&
	   utn_getNumero(&id, "Ingrese el Id a buscar \n",
			"Número inválido \n", 0, 1000, 2) == 0) {

		contratacion_buscarId(array, QTY_CONTRATACIONES, id, &indice);

		if (indice != -1 && utn_getNumero(&opcion,
			"Ingrese el número correspondiente a la opción: "
			"\n 1-Modificar ARCHIVO "
			"\n 2-Modificar DIAS "
			"\n 3-Modificar CUIT",
			"Opción inválida \n", 1, 3, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(archivo, "Ingrese el nuevo archivo \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[indice].archivo, archivo, MAX_ARCHIVO);

					ret = 0;
				}

				break;

			case 2:

				if (utn_getNumero(&dias, "Ingrese cantidad de dias",
						"Numero invalido",1,MAX_DIAS,2)==0){


					array[indice].dias = dias;
					ret = 0;
				}

				break;

			case 3:

				if (utn_getDni(cuit, "Ingrese el nuevo cuit \n",
						"Número inválido \n", MIN_DNI, MAX_DNI, 2) == 0) {

					strncpy(array[indice].cuit, cuit, MAX_DNI);
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

int contratacion_baja(Contratacion *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array!=NULL && length>0 &&
		utn_getNumero(&id, "Ingrese el Id a buscar \n",
		"Número inválido \n", MIN_ID, MAX_ID, 2) == 0) {

		contratacion_buscarId(array, QTY_CONTRATACIONES, id,&indice);

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

int contratacion_ordenar(Contratacion *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Contratacion buffer;

	if (array != NULL && length > 0
			&& utn_getNumero(&orden,
					"Seleccione: 1 para Ordenamiento ascendete, "
							"2 para Ordenamiento desdente", "Opción no válida",
					1, 2, 2) == 0) {

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

				if (orden == 1) {

					if (strncmp(array[i].archivo, array[i + 1].archivo,
							MAX_ARCHIVO) > 0
							|| (strncmp(array[i].archivo, array[i + 1].archivo,
									MAX_ARCHIVO) == 0
									&& array[i].dias > array[i + 1].dias)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}

				else if (orden == 2) {

					if (strncmp(array[i].archivo, array[i + 1].archivo,
							MAX_ARCHIVO) < 0
							|| (strncmp(array[i].archivo, array[i + 1].archivo,
									MAX_ARCHIVO) == 0
									&& array[i].dias < array[i + 1].dias)) {

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

		printf("hola");

	}
	return ret;
}

int contratacion_altaForzada(Contratacion* array, int length, int* pId, char* archivo, char* cuit, int dias, int idPantalla){

	Contratacion bufferContra;


		int indice = -1;

		int ret = -1;

		if (array != NULL && length > 0 && pId != NULL &&archivo!=NULL && cuit!=NULL){


			      contratacion_emptyIndex(array, length, &indice);

			       strncpy(bufferContra.archivo, archivo, MAX_NOMBRE);
			       strncpy(bufferContra.cuit, cuit, MAX_DNI);

			       bufferContra.dias = dias;
			       bufferContra.idPantalla = idPantalla;

					bufferContra.id = *pId;

					bufferContra.isEmpty = 0;

					array[indice] = bufferContra;

					(*pId)++;

					ret = 0;

				}

		return ret;



}
