#include <stdio.h>
#include <stdlib.h>

#include "Articulo.h"
#include "LinkedList.h"

/**
 * Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * @param pFile Directorio del archivo
 * @param pArrayListEmployee Linkedlist de empleados
 * @return 0 Éxito -1 Error
 */
int parser_ArticuloFromText(FILE *pFile, LinkedList *pArticuloList) {

	int ret = -1;

	char idAux[4096];
	char articuloAux[4096];
	char medidaAux[4096];
	char precioAux[4096];
	char rubroIdAux[4096];

	int cont = 0;

	eArticulo *pArticulo = NULL;

	if (pFile != NULL && pArticuloList != NULL) {

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\r]\n", idAux, articuloAux, medidaAux,
				precioAux, rubroIdAux); // lectura fantasma

		do {

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\r]\n", idAux, articuloAux, medidaAux,
					precioAux, rubroIdAux) == 5) // cant. de variables

					{

				pArticulo = articulo_newParametrosTxt(idAux, articuloAux,
						medidaAux, precioAux, rubroIdAux);

				if (pArticulo != NULL) {

					if (ll_add(pArticuloList, pArticulo) == 0) {

						cont++;
					}

				}

			}

		} while (feof(pFile) == 0);

		if (cont > 0) {

			ret = 0;

			printf("Se agregaron %d artículos\n", cont);
		}

	}
	return ret;
}

/**
 * Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 * @param pFile Directorio del archivo
 * @param pArrayListEmployee Linkedlist de empleados
 * @return 0 Éxito -1 Error
 */
int parser_ArticuloFromBinary(FILE *pFile, LinkedList *pArticuloList) {

	int ret = -1;


	int idAux;
	char articuloAux[4096];
	char medidaAux[4096];
	float precioAux;
	int rubroIdAux;

	int cont = 0;

	int read;

	eArticulo *pArticulo = NULL;

	eArticulo eArticuloAux;

	if (pFile != NULL && pArticuloList != NULL) {

		do {

			read = fread(&eArticuloAux, sizeof(eArticulo), 1, pFile);

			if (read==1){

				if (articulo_getArticulo(&eArticuloAux, articuloAux) == 0
						&& articulo_getId(&eArticuloAux, &idAux) == 0
						&& articulo_getMedida(&eArticuloAux, medidaAux)== 0
						&& articulo_getPrecio(&eArticuloAux, &precioAux)== 0
						&& articulo_getRubroId(&eArticuloAux, &rubroIdAux) == 0) {

					pArticulo = articulo_newParametros(idAux, articuloAux, medidaAux,
							precioAux, rubroIdAux);

					if (pArticulo != NULL) {

						if (ll_add(pArticuloList, pArticulo) == 0) {

							cont++;
						}
					}
				}
			}

		} while (feof(pFile) == 0);

		if (cont > 0) {

			printf("Se agregaron %d empleados\n", cont);

			ret = 0;
		}

	}
	return ret;
}
