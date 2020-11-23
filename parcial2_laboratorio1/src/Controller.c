#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "parser.h"
#include "utn_inputs.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_loadFromText(char *path, LinkedList *pArticuloList) {

	int ret = -1;

	FILE *fp;

	if (path != NULL && pArticuloList != NULL) {

		fp = fopen(path, "r");

		if (fp != NULL) {

			if (parser_ArticuloFromText(fp, pArticuloList) == 0) {

				ret = 0;

			}
			fclose(fp);

		}

		else {

			printf("No se encuentra el archivo. \n");
		}

	}

	return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArticuloList) {

	int ret = -1;

	FILE *fp;

	if (path != NULL && pArticuloList != NULL) {

		fp = fopen(path, "rb");

		if (fp != NULL) {

			if (parser_ArticuloFromBinary(fp, pArticuloList) == 0) {

				ret = 0;

			}

			fclose(fp);

		}

		else {

			printf("No pudo abrirse el archivo\n");

		}

	}

	return ret;
}



/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* LinkedList de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_ListArticulo(LinkedList *pArticuloList) {

	int ret = -1;

	int len;

	eArticulo *pArticulo;

	if (pArticuloList != NULL) {

		len = ll_len(pArticuloList);

		if (len > 0) {


			printf("%10s  %20s   %20s  %20s  \n", "ID", "ARTICULO", "MEDIDA", "RUBRO ID" "DESCRIPCION RUBRO");
			printf("--------------------------------------------------------------------------------------\n");


			for (int i = 0; i < len; i++) {

				pArticulo = (eArticulo*) ll_get(pArticuloList, i);

				if (pArticulo != NULL) {
					articulo_print(pArticulo);
				}
			}

			ret = 0;

		}

	}

	return ret;

}

/** \brief Ordenar empleados segun criterio
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_sortArticulo(LinkedList *pArticuloList) {

	int ret = -1;

	if (pArticuloList != NULL) {


				if (ll_sort(pArticuloList, articulo_compareByName, 0) // ascendente
						== 0) {

					ret = 0;

				}


	}

	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArticuloList) {

	int ret = -1;

	FILE *fp;

	int idAux;

	char articuloAux[MAX_ARTICULO];

	char medidaAux[MAX_MEDIDA];

	float precioAux;

	int rubroIdAux;

	int len;

	eArticulo *pArticulo = NULL;

	if (path != NULL && pArticuloList != NULL) {

		fp = fopen(path, "w");

		if (fp != NULL) {

			len = ll_len(pArticuloList);

			fprintf(fp, "Id,Articulo,Medida,Precio,RubroId\n");

			for (int i = 0; i < len; i++) {

				pArticulo = (eArticulo*) ll_get(pArticuloList, i);

				if (pArticulo != NULL) {

					if (
							articulo_getId(pArticulo, &idAux) == 0

							&& articulo_getArticulo(pArticulo, articuloAux) == 0

							&& articulo_getMedida(pArticulo, medidaAux) == 0

							&& articulo_getPrecio(pArticulo, &precioAux) == 0

							&& articulo_getRubroId(pArticulo, &rubroIdAux) == 0) {

						fprintf(fp, "%d,%s,%s,%f,%d\n", idAux, articuloAux, medidaAux,
								precioAux,rubroIdAux);

					}
				}

			}

			ret = 0;

			fclose(fp);

		}

	}

	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char* Directorio del archivo
 * \param pArrayListEmployee LinkedList* Linkedlist de empleados
 * \return int 0 Éxito -1 Error
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArticuloList) {

	int ret = -1;

	FILE *fp;

	int len;

	eArticulo *pArticulo = NULL;

	if (path != NULL && pArticuloList != NULL) {

		fp = fopen(path, "wb");

		if (fp != NULL) {

			len = ll_len(pArticuloList);

			for (int i = 0; i < len; i++) {

				pArticulo = (eArticulo*) ll_get(pArticuloList, i);

				if (pArticulo != NULL) {

					fwrite(pArticulo, sizeof(eArticulo), 1, fp);

				}
			}

			fclose(fp);

		}

		ret = 0;

	}

	return ret;

}

