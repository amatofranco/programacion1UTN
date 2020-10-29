/*
 ============================================================================
 Name        : parcialprogramacion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */

	typedef struct{

		int legajo;
		char nombre[51];
		int edad;
		float altura;
	}eEmpleado;


	eEmpleado personal[14];

	strcpy(personal[0].nombre,"Pepe");
	strcpy(personal[1].nombre,"Cacho");
	strcpy(personal[2].nombre,"Amara");
	strcpy(personal[3].nombre,"Ronberto");





	eEmpleado buffer;

    int flag = 0;

    int length = 13;

	do {

		flag = 0;



			for (int i = 0; i < length; i++) {

				if (strncmp(personal[i].nombre, personal[i + 1].nombre,51) > 0) {


					flag = 1;
					buffer = personal[i];
					personal[i] = personal[i + 1];
					personal[i + 1] = buffer;

				}
			}

			length--;

		} while (flag == 1);


	    for (int i=0; i<=14;i++){

			printf("%s \n",personal[i].nombre);
		}



	return EXIT_SUCCESS;
}
