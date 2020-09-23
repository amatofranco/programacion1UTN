/*
 ============================================================================
 BURBUJEO
 Ordenamiento de arrays
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int main(void) {

	int vec[SIZE] = { 54, 34, 36, 7, 3 };

	//ORDENAMIENTO ASCENDENTE

	for (int i = 0; i < SIZE - 1; i++) {

		for (int j = i + 1; j < SIZE; j++) {

			if (vec[i] > vec[j]) {

				int aux = vec[i];
				vec[i] = vec[j];
				vec[j] = aux;
			}
		}

	}

	for(int i =0; i<SIZE;i++){

		printf("%d ", vec[i]);

	}

	return EXIT_SUCCESS;
}
