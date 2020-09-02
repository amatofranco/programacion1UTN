/*
 Ejercicio 01:
 Se pide una cantidad indeterminada de edades enteras,
 informar:
 el máximo ingresado
 el mínimo ingresado
 el promedio
 la cantidad de edades ingresadas

 Ejercicio 02:
 Al ejercicio anterior :
 Ademas de la edad ingresar el estado civil de la persona ( 's' para soltera , 'c' para casada, 'd' divorciada)
 ademas de informar lo anterior ....informar:
 la persona mas joven de las casadas
 a persona mas Vieja de las solteras
 de los estados civiles , cual fue el mas ingresado
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int edad;
	char respuesta;
	char estadoCivil;
	char menorCasada;
	char mayorSoltera;
	int solteros = 0;
	int casados = 0;
	int divorciados = 0;
	int maximo;
	int minimo;
	float promedio;
	int contador = 0;
	int acumulador = 0;
	int flagEdad = 0;
	int flagMaximo = 0;
	int flagMinimo = 0;
	char mayorEstadoCivil;

	do {

		do {

			printf("Ingrese una edad \n");
			fpurge(stdin);
			scanf("%d", &edad);
		}
		while(! (edad>0 && edad <110));

		do{

			printf("Ingrese estado civil: s - c - d \n");
			fpurge(stdin);
			scanf("%c", &estadoCivil);
		}
		while (! (estadoCivil =='s' || estadoCivil == 'c' || estadoCivil == 'd'));

		switch(estadoCivil){

		case 's':
			solteros++;

			if(flagMaximo == 0 || edad > mayorSoltera){
				mayorSoltera = edad;
				flagMaximo = 1;
			}
			break;

		case 'd':
			divorciados++;
			break;

		case 'c':
			casados++;
			if(flagMinimo == 0 || edad < menorCasada){
				menorCasada = edad;
				flagMinimo =1;
			}
			break;
		}

		if(flagEdad == 0){

			maximo = edad;
			minimo = edad;
			flagEdad = 1;

		}

		else if (edad > maximo ){
			maximo = edad;
		}

		else if (edad < minimo){
			minimo = edad;
		}

		contador++;
		acumulador+=edad;


		printf("¿Desea agregar otra edad? \n");
		fpurge(stdin);
		scanf("%c", &respuesta);

	} while (respuesta == 's');

	promedio = acumulador /contador;

	if (solteros > casados && solteros > divorciados){
		mayorEstadoCivil = 's';
	}
	else if (casados > solteros && casados >= divorciados){
		mayorEstadoCivil = 'c';
	}

	else {
		mayorEstadoCivil = 'd';
	}

	printf("Edad máxima ingresada; %d \n", maximo);
	printf("Edad mínima ingresada: %d \n", minimo);
	printf("Cantidad de edades ingresadas: %d \n", contador);
	printf("Promedio de edad: %f \n",promedio);

	if(solteros !=0){
	printf("Edad del soltero mas viejo: %d \n", mayorSoltera);
	}

	if (casados !=0){
	printf("Edad del casado mas joven: %d \n", menorCasada);
	}
	printf("Estado Civil más ingresado: %c", mayorEstadoCivil);

	return EXIT_SUCCESS;
}
