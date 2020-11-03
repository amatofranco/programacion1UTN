/*
 ============================================================================
 ARCHIVOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Cliente.h"

int main(void) {

	//LECTURA EN MODO TEXTO - DATOS SEPARADOS POR COMA
	//(PARSER)

	FILE *fp;

	fp = fopen("archivo.txt", "rb"); //si no se pone directorio, lo toma como la carpeta del proyecto

	char nombre[128];
	char altura[128];
	char id[128];
	char dni[128]; //TODOS COMO CHAR PARA DESPUES VALIDAR
	int i = 0;
	Cliente *punteroCli;


	Cliente *arrayPunterosClientes[QTY_CLIENTES];

	if (fp != NULL) {

		do {

			if (fscanf(fp, "%[^,],%[^,],%[^,],%[^\n]\n", nombre, altura, id,
					dni) == 4) { //FSCANF DEVUELVE LA CANTIDAD DE SCANS REALIZADOS

				// %[^,] Leer cualquier caracter menos la coma

				//validar y despues..


				punteroCli = cli_newParametros(nombre, atof(altura), dni,
						atoi(dni));

				if (punteroCli != NULL) {

					arrayPunterosClientes[i] = punteroCli;

					i++;
				}
			}
		} while (feof(fp) == 0); //FEOF(END OF FILE) DEVUELVE 1 HASTA QUE ENCUENTRA EL FIN DE ARCHIVO Y AHI DEVUELVE 0





		for (int j=0;j<i;j++){
			printf("Nombre: %s, altura: %f\n",arrayPunterosClientes[j]->nombre, arrayPunterosClientes[j]->altura);

		}

	}


	return EXIT_SUCCESS;
}
