/*
 ============================================================================
 ARCHIVOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

int main(void) {

	FILE *fp;

	fp = fopen("archivo.txt", "w"); //si no se pone directorio, lo toma como la carpeta del proyecto

	if (fp != NULL) {

		// LO USAMOS EN MODO TEXTO - 1 funcion para leer y 1 funcion para escribir

		// fprintf(fp, "Hola mundo"); //Igual que printf pero poniendo el puntero a FILE. Se puede usar variables tambien


		// int i = 127;

		// fwrite(&i, sizeof(int), 1,fp); //FWRITE: Escribe en binario. Pasa el valor de la variable (binario) al archivo. Pide direccion de memoria de la variable, el tamaño y CUANTOS (porque podrian ser varios, en caso de array)

		Cliente c;
/*

		c.altura = 200;
		sprintf(c.dni,"36821939");
		c.id = 1;
		c.isEmpty = 1;
		sprintf(c.nombre,"Pepe");

		fwrite(&c, sizeof(Cliente),1,fp);
*/

		//fread(&c, sizeof(Cliente),1,fp);

		//cli_newParametros(c.nombre,c.altura,c.dni,c.id);


		// printf("%s",c.dni);

		//ESCRITURA MODO TEXTO

		char nombreAux[MAX_NOMBRE];
		float alturaAux;
		char dniAux[MAX_DNI];
		int idAux;




		// LO CERRAMOS
		fclose(fp); // Siempre le vamos a hacer close, pero si es distinto de null


	} else {
		printf("Error abriendo archivo");
	}


	return EXIT_SUCCESS;
}
