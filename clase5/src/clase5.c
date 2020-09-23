
	#include <stdio.h>
	#include <stdlib.h>

	int calcular(int num1, int num2, int* pSuma, int* pResta);
	int main(void) {

		int num1;
		int num2;
		int suma;
		int resta;
		int resultado;


		printf("Ingrese numero 1 \n");
		scanf("%d", &num1);
		printf("Ingrese numero 2 \n");
		scanf("%d", &num2);


		resultado = calcular(num1,num2,&suma,&resta);
		if (resultado==0){
			printf("se realizo la operación \n");
		}

		printf("La suma de %d y %d es: %d \n",num1, num2, suma);
		printf("La resta de %d y %d es: %d",num1,num2,resta);


	return EXIT_SUCCESS;
}

	int calcular(int num1, int num2, int* pSuma, int* pResta){

		int suma = num1 + num2;
		int resta = num1 - num2;

		*pSuma = suma;
		*pResta = resta;
		return 0;


	}
