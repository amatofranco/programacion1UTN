	#include <stdio.h>
	#include <stdlib.h>

	int sumar(int num1, int num2);
	int restar(int num1, int num2);
	float dividir(float num1, int num2);
	int multiplicar(int num1, int num2);

	int main(void) {

		int num1;
		int num2;
		int operacion;
		int resultado;

		printf("Ingrese numero 1 \n");
		scanf("%d", &num1);
		printf("Ingrese numero 2 \n");
		scanf("%d", &num2);
		printf("Seleccione opcion: 1 sumar, 2 restar, 3 dividir, 4 multiplicar \n");
		scanf("%d", &operacion);

		switch (operacion) {

		case 1:
			resultado = sumar(num1, num2);
			break;
		case 2:
			resultado = restar(num1, num2);
			break;
		case 3:
			resultado = dividir(num1, num2);
			break;
		case 4:
			resultado = multiplicar(num1, num2);
			break;
		}

		printf("El resultado es: 1%d", resultado);

		return EXIT_SUCCESS;
	}

	int sumar(int num1, int num2) {

		int resultado = num1 + num2;
		return resultado;
	}

	int restar(int num1, int num2) {

		int resultado = num1 - num2;
		return resultado;
	}

	float dividir(float num1, int num2) {

		float resultado = num1 / num2;
		return resultado;
	}

	int multiplicar(int num1, int num2) {

		int resultado = num1 / num2;
		return resultado;
	}

