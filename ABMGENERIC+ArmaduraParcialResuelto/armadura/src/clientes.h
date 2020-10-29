/*
 * clientes.h
 *
 *  Created on: 8 oct. 2019
 *      Author: sergio
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
	int idCliente;
	char nombre[51];
	char apellido[51];
	char domicilio[60];
	char sexo[2];
	char telefono[21];
	int isEmpty;
}eClientes;

int clientes_Inicializar(eClientes* array, int size);
int clientes_buscarEmpty(eClientes* array, int size, int* posicion);
int clientes_buscarID(eClientes* array, int size, int valorBuscado, int* posicion);
int clientes_alta(eClientes* array, int size, int* contadorID);
int clientes_modificar(eClientes* array, int sizeArray);
int clientes_baja(eClientes* array, int sizeArray);
int clientes_listar(eClientes* array, int size);
int ordenarXApellidoYNombre(eClientes* array,int len);






#endif /* CLIENTES_H_ */
