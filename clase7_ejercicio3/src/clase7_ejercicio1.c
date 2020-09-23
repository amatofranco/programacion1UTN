//* Cargar 5 valores en array y mostrar mayor y menor

#include <stdio.h>
#include <stdlib.h>
#define LENGHT 5 //tamaño del array

void inicializarArray(int array[], int lenght);
void cargarIntArray(char* mensajePos, char* mensajeValor, char*mensajeError, int array[], int lenght);
void menorArray(int array[], int lenght);

int main(void) {

	int edades[LENGHT];

	inicializarArray(edades,LENGHT);
	cargarIntArray ("Elija la posicion", "Ingrese la edad", "Posicion incorrecta",edades,LENGHT);
	menorArray(edades,LENGHT);

	return EXIT_SUCCESS;
}

void inicializarArray(int array[], int lenght)
{
	for (int i = 0; i < lenght; i++) {
		array[i] = 0;
	}
}

void cargarIntArray(char* mensajePos, char* mensajeValor, char*mensajeError, int array[], int lenght) {

	int i;
	char respuesta;


	do {
			printf("%s \n",mensajePos);
			scanf("%d", &i);
			if (i>=0 && i<=lenght){

			printf("%s \n", mensajeValor);
			scanf("%d", &array[i]);
			}
			else{
				printf("%s \n", mensajeError);
			}

			printf("Seguir ingresando? (s/n): ");
			fpurge(stdin);
			scanf("%c", &respuesta);


		} while (respuesta != 'n');

}

void menorArray(int array[], int lenght){

	int menor;
	int flag=0;

	for (int i=0; i<=lenght;i++){

		if (array[i]!=0 && (array[i]<menor || flag == 0)){

			menor = array[i];
			flag = 1;
		}
	}

		printf("Menor: %d", menor);

}


