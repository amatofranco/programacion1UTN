/*
 * juegos.h
 *
 *  Created on: 8 oct. 2019
 *      Author: sergio
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_

typedef struct
{
	int idJuegos;
	char descripcion[51];
	float importe;
	int idCategoria;
	int isEmpty;
}eJuegos;

typedef struct
{
	int id;
	char descripcion[51];
}eCategoria;



#endif /* JUEGOS_H_ */
