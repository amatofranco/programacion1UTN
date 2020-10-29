/*
 * categoria.h
 *
 *  Created on: 8 oct. 2019
 *      Author: sergio
 */

#ifndef ALQUILERES_H_
#define ALQUILERES_H_

typedef struct
{
	int idAlquiler;
	int idJuego;
	int idCliente;
	int isEmpty;
	eFecha fecha;
}eAlquiler;

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;




#endif /* ALQUILERES_H_ */
