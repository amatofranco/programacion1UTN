/*
 ============================================================================
 Name        : armadura.c
 Author      : Cardozo Sergio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alquileres.h"
#include "utn.h"
#include "juegos.h"
#include "clientes.h"

#define QTY_CLIENTES 30
int main()
{
	int contadorIdClientes = 0;
	int menuOpcionElegida;
	char menuPrinsipalMensaje[] =
		                "\n1-Alta de Clientes\
		                 \n2-Modificar datos del Cliente\
		                 \n3-Baja del Cliente\
		                 \n4-Ordenar y listar clientes\
		                 \n5-Alquileres listados\
		                 \n6-Informes\
		                 \n7-Salir\n\
		                 \nIngrese opcion: ";
	char menuPrinsipalMensajeError[] = "\nSe debe elegir una opcion del 1 al 7";

	eClientes arrayClientes[QTY_CLIENTES];
	clientes_Inicializar(arrayClientes,QTY_CLIENTES);

	do{
		menuOpcionElegida = 0;
		utn_getSignedInt(menuPrinsipalMensaje,menuPrinsipalMensajeError,0,sizeof(int),0,9,2,&menuOpcionElegida);

		switch(menuOpcionElegida)
		{
		case 1:
			clientes_alta(arrayClientes,QTY_CLIENTES,&contadorIdClientes);
			break;
		case 2:
			clientes_listar(arrayClientes,QTY_CLIENTES);
			clientes_modificar(arrayClientes,QTY_CLIENTES);
			break;
		case 3:
			clientes_listar(arrayClientes,QTY_CLIENTES);
			clientes_baja(arrayClientes,QTY_CLIENTES);
			break;
		case 4:
			ordenarXApellidoYNombre(arrayClientes,QTY_CLIENTES);
			clientes_listar(arrayClientes,QTY_CLIENTES);
			break;
		case 5:
			addRent(alquiler,cantiUser,cantiGame,users,game);
			break;
		case 6:
			sortRent(rent,(cantiGame*cantiUser),order);
			    for(i=0;i<(cantiGame*cantiUser);i++){
			        if(rent[i].isEmpty==0){
			            printRent(rent[i],game,user,cantiUser,cantiGame);
			            break;




		}

	}while(menuOpcionElegida != 7);
	return 0;
}
