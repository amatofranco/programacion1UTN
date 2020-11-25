#include <stdio.h>
#include <stdlib.h>

#include "Articulo.h"
#include "LinkedList.h"


int parser_ArticuloFromText(FILE *pFile, LinkedList *pArticuloList) {

	int ret = -1;

	char idAux[128];
	char articuloAux[128];
	char medidaAux[128];
	char precioAux[128];
	char rubroIdAux[128];

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
