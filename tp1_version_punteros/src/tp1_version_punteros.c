
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void) {

	setbuf(stdout, NULL);

	int opcion = 0;
	int num1;
	int num2;
	int flagNum1 = 0;
	int flagNum2 = 0;
	int flagOperacion = 0;
	int suma;
	int resta;
	int producto;
	float division;
	int retornoDivision;
	int retornoFactorial1;
	int retornoFactorial2;
	int factorial1;
	int factorial2;

	do {


		printf("Ingrese el número correspondiente a la opción: \n 1 Ingresar 1er Operando ");

		if (flagNum1 == 1) {
			printf("(A= %d)", num1);
		}

		printf("\n 2 Ingresar 2do Operando ");

		if (flagNum2 == 1) {
			printf("(B= %d)", num2);
		}

		printf("\n 3 Calcular Operaciones \n 4 Mostrar Resultado \n 5 Salir \n");

		fpurge(stdin);
		scanf("%d", &opcion);

		switch (opcion) {

		case 1:
			printf("Ingrese el 1er Operando: ");
			getNum(&num1);
			flagNum1 = 1;
			break;

		case 2:
			printf("Ingrese el 2do Operando: ");
			getNum(&num2);
			flagNum2 = 1;
			break;

		case 3:
			if (flagNum1 == 0 || flagNum2 == 0) {
				printf( "Falta ingresar alguno de los 2 operandos. Ingréselos nuevamente \n");
			}

			else {

				sumar(&suma, num1, num2);
				restar(&resta, num1, num2);
				multiplicar(&producto, num1, num2);
				retornoDivision = dividir(&division, num1, num2);
				retornoFactorial1 = factorial(&factorial1,num1);
				retornoFactorial2 = factorial(&factorial2, num2);
				flagOperacion = 1;
				printf("Se calcularon las operaciones \n");
			}
			break;

		case 4:

				if (flagOperacion == 1) {

				printf("El resultado de %d + %d es: %d \n", num1, num2, suma);
				printf("El resultado de %d - %d es: %d \n", num1, num2, resta);
				printf("El resultado de %d * %d es: %d \n", num1, num2,producto);

				if (retornoDivision == 0) {
					printf("El resultado de %d / %d es: %f \n", num1, num2, division);
				}

				else {
					printf("El resultado de %d / %d es: No se puede dividir por cero \n",num1, num2);

				}

				if (retornoFactorial1 == 0) {
					printf("El factorial de %d es: %d \n", num1, factorial1);
				}

				else {

					printf("El factorial de %d es: No se puede realizar factorial de negativos \n", num1);

				}

				if (retornoFactorial2 == 0) {
					printf("El factorial de %d es: %d \n", num2, factorial2);
				}

				else {
					printf("El factorial de %d es: No se puede realizar factorial de negativos \n", num2);
				}

			}

			else {
				printf("Aún no se realizaron operaciones \n");
			}

			break;

		case 5:
			printf("Saliendo del programa");
			break;

		default:
			printf("Opcion no válida. \n");

		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}
