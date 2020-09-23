#include <stdio.h>
#include <stdlib.h>

int getNum(int *pNum) {

	int num;

	scanf("%d", &num);

	*pNum = num;

	return 0;

}

int sumar(int *pSuma, int num1, int num2) {

	int resultado = num1 + num2;
	*pSuma = resultado;
	return 0;
}

int restar(int *pResta, int num1, int num2) {

	int resultado = num1 - num2;
	*pResta = resultado;
	return 0;
}

int multiplicar(int *pProducto, int num1, int num2) {

	int resultado = num1 * num2;
	*pProducto = resultado;
	return 0;
}

float dividir(float *pDivision, int num1, int num2) {

	int retorno = -1;
	float resultado;

	if (num2 != 0) {

		resultado = (float) num1 / num2;
		*pDivision = resultado;
		retorno = 0;
	}

	return retorno;
}

int factorial(int *pFactorial, int num) {

	int retorno = -1;

	int resultado;

	int factorial = 1;

	if (num >= 0) {

		if (num == 0) {

			resultado = 1;

			*pFactorial = resultado;

		}

		else {
			for (int i = 1; i <= num; i++) {
				factorial = factorial * i;
			}

			*pFactorial = factorial;
		}

		retorno = 0;

	}

	return retorno;

}

