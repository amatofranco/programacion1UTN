#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Articulo.h"
#include "parser.h"
#include "utn_inputs.h"
#include "Controller.h"

int controller_loadFromText(LinkedList *pArticuloList) {

	int ret = -1;

	int intentos = 3;

	FILE *fp;

	char path[128];

	if (pArticuloList != NULL) {

		do {

			utn_getArchivo(path, "Ingrese nombre de archivo: datos.csv\n",
					"Ingreso inválido\n", 2);

			fp = fopen(path, "r");

			if (fp != NULL) {

				if (parser_ArticuloFromText(fp, pArticuloList) == 0) {

					ret = 0;
					break;

				}
				fclose(fp);
			}

			else {

				printf("No se encuentra el archivo. Intente nuevamente\n");
				intentos--;
			}
		} while (intentos);

	}

	return ret;
}

int controller_ListArticulo(LinkedList *pArticuloList) {

	int ret = -1;

	int len;

	eArticulo *pArticulo;

	if (pArticuloList != NULL) {

		len = ll_len(pArticuloList);

		if (len > 0) {

			printf("%10s  %40s   %10s  %10s %15s  \n", "ID", "ARTICULO",
					"MEDIDA", "PRECIO", "RUBRO");
			printf(
					"--------------------------------------------------------------------------------------------------------------\n");

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

int controller_sortArticulo(LinkedList *pArticuloList) {

	int ret = -1;

	if (pArticuloList != NULL) {

		if (ll_sort(pArticuloList, articulo_compareByName, 1) // orden ascendente
		== 0) {

			ret = 0;

		}

	}

	return ret;
}

int controller_setFinalPrice(LinkedList *pArticuloList) {

	int ret = -1;

	if (pArticuloList != NULL) {

		ll_map(pArticuloList, articulo_setFinalPrice);
		ret = 0;
	}

	return ret;

}

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

					if (articulo_getId(pArticulo, &idAux) == 0

					&& articulo_getArticulo(pArticulo, articuloAux) == 0

					&& articulo_getMedida(pArticulo, medidaAux) == 0

					&& articulo_getPrecio(pArticulo, &precioAux) == 0

					&& articulo_getRubroId(pArticulo, &rubroIdAux) == 0) {

						fprintf(fp, "%d,%s,%s,%.2f,%d\n", idAux, articuloAux,
								medidaAux, precioAux, rubroIdAux);

					}
				}

			}

			ret = 0;

			fclose(fp);

		}

	}

	return ret;
}

int controller_countMayorCien(LinkedList *pArticuloList) {

	int ret = -1;

	int count = -1;

	if (pArticuloList != NULL) {

		count = ll_count(pArticuloList, articulo_mayorCien);

		if (count >= 0) {

			printf("Se encontraron %d articulos\n", count);

			ret = 0;
		}

	}

	return ret;

}

int controller_countRubroUno(LinkedList *pArticuloList) {

	int ret = -1;

	int count = -1;

	if (pArticuloList != NULL) {

		count = ll_count(pArticuloList, articulo_rubroUno);

		if (count >= 0) {

			printf("Se encontraron %d articulos\n", count);

			ret = 0;
		}

	}

	return ret;

}

