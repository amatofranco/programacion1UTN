#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Pantalla.h"
#include "Contratacion.h"

#include "utn_inputs.h"




/**
 * Imprime mensaje error
 */
void mensajeError();

/**
 * Imprime mensaje de operación exitosa
 */
void mensajeExito();

/**
 * Imprime mensaje de array vacío
 */
void arrayVacio();

/**
 * Imprime mensaje de array completo
 */

void arrayCompleto();


int main(void) {

	Pantalla arrayPantallas[QTY_PANTALLAS];
	Contratacion arrayContrataciones[QTY_CONTRATACIONES];

	int idContratacion = MIN_ID;
	int idPantalla = MIN_ID;
	int opcion;
	int ret;
	int idAux;
	int indice;

	if (pantalla_iniciar(arrayPantallas, QTY_PANTALLAS) == 0) {

		printf("El array 1 se inició correctamente \n");
	}

	if (contratacion_iniciar(arrayContrataciones, QTY_CONTRATACIONES) == 0) {

		printf("El array 2 se inició correctamente \n");
	}


	pantalla_altaForzada(arrayPantallas, QTY_PANTALLAS,&idPantalla,"Pantalla 1","Irigoyen 3400",1500,1);
	pantalla_altaForzada(arrayPantallas, QTY_PANTALLAS,&idPantalla,"Pantalla 2","Rosas 400",100,2);
	pantalla_altaForzada(arrayPantallas, QTY_PANTALLAS,&idPantalla,"Pantalla 3","Saenz 1000",5000,2);

	contratacion_altaForzada(arrayContrataciones,QTY_CONTRATACIONES,&idContratacion,"wiwjdwdk","3400000",5,3);
	contratacion_altaForzada(arrayContrataciones,QTY_CONTRATACIONES,&idContratacion,"asdasdw","3500000",5,2);

	do {

		ret = utn_getNumero(&opcion, "Seleccione una opción \n "
				"1- Alta Pantalla \n "
				"2- Modificar Pantalla \n "
				"3- Baja Pantalla \n "
				"4- Contratar PUBLICIDAD \n "
				"5- Modificar PUBLICIDAD \n "
				"6- Baja PUBLICIDAD \n "
                "8- Imprimir Listado de Publicidades \n"
				"9- Imprimir Listado de Pantallas \n "
				"11- Salir \n", "Opción no válida  \n", 1, 10, 2);

		if (ret == 0) {

			switch (opcion) {

			case 1:

					if (pantalla_alta(arrayPantallas, QTY_PANTALLAS, &idPantalla) == 0) {
						mensajeExito();
					} else {
						mensajeError();
					}

				break;

			case 2:

					if (pantalla_modificar(arrayPantallas, QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 3:


					if (pantalla_baja(arrayPantallas, QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}
				break;


			case 4:
				pantalla_imprimirArray(arrayPantallas,QTY_PANTALLAS);

				if (utn_getNumero(&idAux,"Seleccione el ID correspondiente","numero invalido",MIN_ID,MAX_ID,2)==0
					&& pantalla_buscarId(arrayPantallas,QTY_PANTALLAS,idAux,&indice)==0){

					if (contratacion_alta(arrayContrataciones,QTY_CONTRATACIONES,&idContratacion,idAux)==0){

						mensajeExito();

					}
					else {
						   mensajeError();
					}


				}
				else{

					printf("El ID no existe \n");
				}


				break;


			case 5:
				/*
				if (utn_getDni(&cuitAux,"Ingrese cuit","Numero invalido",MIN_DNI,MAX_DNI,3)==0){


					imprimirPantallasporCuit(arrayContrataciones,QTY_CONTRATACIONES,arrayPantallas,QTY_PANTALLAS,cuitAux);


				}
				*/

				if (contratacion_modificar(arrayContrataciones,QTY_CONTRATACIONES)==0){

					mensajeExito();
				}

				else{
					mensajeError();
				}

				break;



			case 6:

				if (contratacion_baja(arrayContrataciones,QTY_CONTRATACIONES)==0){

					mensajeExito();
				}
				else {
					mensajeError();
				}


				break;



			case 8:

				if (contratacion_imprimirArray(arrayContrataciones,QTY_CONTRATACIONES)==0){

					mensajeExito();

				}
				else {
					mensajeError();
				}

				break;
			case 9:

					if (pantalla_ordenarNomTipo(arrayPantallas, QTY_PANTALLAS) == 0
					 && pantalla_imprimirArray(arrayPantallas,QTY_PANTALLAS) == 0) {

						mensajeExito();
					}

					else {

						mensajeError();
					}

				break;

			case 11:
				printf("Saliendo del programa");
			}

		} else {
			mensajeError();
		}

	} while (opcion != 11);

	return EXIT_SUCCESS;

}

void mensajeError() {

	char mensaje[] = "Se produjo un error. Se redigirá al menú \n";

	printf("%s", mensaje);

}

void mensajeExito() {

	char mensaje[] = "Operación exitosa \n";

	printf("%s", mensaje);

}

void arrayVacio() {

	char mensaje[] = "No se registra ninguna carga \n";

	printf("%s", mensaje);

}

void arrayCompleto() {

	char mensaje[] = "No hay mas lugar para realizar una carga \n";

	printf("%s", mensaje);

}

