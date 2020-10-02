/*
 ============================================================================
 Name        : clase9_structs.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

//STRUCT DATOS PERSONALES - Se define arriba del main arriba de las funciones
typedef struct{ //TYPEDEF: PALABRA RESERVADA PARA REDEFINIR EL NOMRBE DE CUALQUIER TIPO DE DATO

		char nombre[20];
		char apellido[20];
		char calle[20];
		int numero;

	}datosPersonales;

int main(void) {

		//Declaracion de variable agenda de tipo datosPersonales
	    datosPersonales agenda;

	    strcpy(agenda.nombre, "Yanina"); // Asignacion a variables string: con el strcpy
	    strcpy(agenda.apellido, "Perez");
	    strcpy(agenda.calle, "Peña");
	    agenda.numero = 245;



	    printf("El nombre es: %s \n", agenda.nombre);
	    printf("El apellido es: %s", agenda.apellido);

	    datosPersonales vecAgenda[3];

	    int i;
	    ​
	        for(i=0;i<3;i++){
	            printf("\nIngrese nombre ");
	            gets(vecAgenda[i].nombre);
	            printf("\nIngrese apellido ");
	            gets(vecAgenda[i].apellido);
	            printf("\nIngrese calle ");
	            gets(vecAgenda[i].calle);
	            printf("\nIngrese numero ");
	            scanf("%d", &vecAgenda[i].numero);
	            fflush(stdin);
	        }
	        //Mostrar elementos de la estructura
	        for(i=0;i<3;i++){
	            printf("\n Nombre: %s ", vecAgenda[i].nombre);
	            printf("\nApellido: %s ", vecAgenda[i].apellido);
	            printf("\nCalle: %s ", vecAgenda[i].calle);
	            printf("\nNumero: %d ", vecAgenda[i].numero);
	        }



	return EXIT_SUCCESS;
}
