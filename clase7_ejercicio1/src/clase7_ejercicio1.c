#include <stdio.h>
#include <stdlib.h>
#define LENGHT 5 //tamaño del array

void inicializar(int edades[], float sueldo[], int lenght);
int validarPosicion(int lenght);
void cargar(int edades[], float sueldo[], int lenght);
void promedioSueldo(float sueldo[], int lenght);
void mostrarEmpleados(int edades[], float sueldo[], int lenght);
void ordenarSueldos(int edades[], float sueldo[], int lenght);


int main(void) {

	int edades[LENGHT];
	float sueldo[LENGHT];
	char nombres[LENGHT][20];

	for(int i=0;i<LENGHT;i++){

		printf("Ingrese nombre para legajo: %d \n",i+1);
		fgets(nombres[i],LENGHT,stdin);

	}



	//Cuando la carga de array va ser aleatoria, debe inicializarse todo el array en 0
	inicializar(edades,sueldo,LENGHT);
	cargar(edades,sueldo,LENGHT);




	promedioSueldo(sueldo,LENGHT);
	ordenarSueldos(edades,sueldo,LENGHT);
	mostrarEmpleados(edades,sueldo,LENGHT);


	return EXIT_SUCCESS;
}

void inicializar(int edades[], float sueldo[], int lenght) {
	for (int i = 0; i < LENGHT; i++) {
		edades[i] = 0;
		sueldo[i] = 0;
	}
}

void cargar(int edades[], float sueldo[], int lenght) {

	int pos;
	int legajo;
	char respuesta;


	do {
			printf("Ingrese numero de legajo a cargar: ");
			scanf("%d", &legajo);
			pos = legajo - 1;
			if (validarPosicion(pos)==0){

			printf("Ingrese edad para el legajo %d: ", legajo);
			scanf("%d", &edades[pos]);

			printf("Ingrese sueldo para el legajo %d: ", legajo);
			scanf("%f", &sueldo[pos]);
			}
			else{
				printf("Número de legajo invalido \n");
			}

			printf("Seguir ingresando? (s/n): ");
			fpurge(stdin);
			scanf("%c", &respuesta);


		} while (respuesta != 'n');

}

void promedioSueldo(float sueldo[], int lenght){

	int cont=0;
	int suma=0;
	float promedio = 0;

	for (int i=0; i<lenght;i++){

		if(sueldo[i]!=0){

		suma += sueldo[i];
		cont++;
		}

	}

	if(cont!=0){
	promedio = suma/cont;
	}

	printf("Promedio sueldos: %.2f \n",promedio);
}

int validarPosicion(int pos){

	int retorno = -1;

	if (pos>=0 && pos<=LENGHT){

		retorno = 0;

	}
	return retorno;

}

void mostrarEmpleados(int edades[], float sueldo[], int lenght){

	for (int i=0; i<lenght;i++){

			if(edades[i]!=0 && sueldo[i]!=0){

			printf("Legajo %d, edad: %d, sueldo: %.2f \n", i+1, edades[i], sueldo[i]);

			}

		}

}

void ordenarSueldos(int edades[], float sueldo[], int lenght){

	for (int i = 0; i < lenght - 1; i++) {

			for (int j = i + 1; j < lenght; j++) {

				if (sueldo[i] > sueldo[j]) {


					int aux = sueldo[i];
					sueldo[i] = sueldo[j];
					sueldo[j] = aux;

					aux = edades[i];
					edades[i] = edades[j];
					edades[j] = aux;
				}
			}

		}

}


