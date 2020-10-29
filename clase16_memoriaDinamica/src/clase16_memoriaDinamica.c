/*
 ============================================================================
 Name        : clase16_memoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int initArray(int *pArray, int limite, int valor) {

	int ret = -1;

	if (pArray != NULL && limite > 0) {

		for (int i = 0; i < limite; i++) {

			*(pArray + i) = valor;

		}

		ret = 0;
	}

	return ret;

}

int imprimirArray(int *pArray, int size) {

	int ret = -1;

	if (pArray != NULL && size > 0) {

		ret = 0;

		for (int i = 0; i < size; i++) {

			printf("%d\n", *(pArray + i));
		}

	}

	return ret;

}

int resizeArray(int *pArray, int *sizeActual, int sizeNuevo) {

	int ret = -1;

	int *pArrayTemp = NULL;

	if (pArray != NULL && sizeActual > 0 && sizeNuevo >= 0) {

		//REASIGNAMOS LA CANTIDAD DE LUGARES QUE VA A GUARDAR EL ARRAY = REALLOC
		pArrayTemp = realloc(pArray, sizeof(int) * (sizeNuevo));

		//SI EL RESULTADO ES DISTINTO DE NULL SIGNIFICA QUE SE ENCONTRO ESPACIO EN MEMORIA PARA PODER ASIGNARLO
		if (pArrayTemp != NULL) {

			*sizeActual = sizeNuevo;
			pArray = pArrayTemp;

			ret = 0;

		}

	}

	return ret;
}

int main(void) {

	int *pArrayEdades = NULL;
	int sizeArrayEdades = 10;

	pArrayEdades = (int*) malloc(sizeof(int) * sizeArrayEdades);

	if (pArrayEdades != NULL) {

		if (initArray(pArrayEdades, sizeArrayEdades, 0) == 0) {

			printf("Init ok");
			imprimirArray(pArrayEdades, sizeArrayEdades);
		}

		if (resizeArray(pArrayEdades, &sizeArrayEdades, 60) == 0) {

			printf("Resize ok\n");
			initArray(pArrayEdades, sizeArrayEdades, 0);
			imprimirArray(pArrayEdades, sizeArrayEdades);

		}

	}


return EXIT_SUCCESS;
}
