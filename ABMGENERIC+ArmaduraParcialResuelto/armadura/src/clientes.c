#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "clientes.h"

int clientes_Inicializar(eClientes* array, int size)
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

int clientes_buscarEmpty(eClientes* array, int size, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int clientes_buscarID(eClientes* array, int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idCliente==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int clientes_alta(eClientes* array, int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(clientes_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idCliente=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getName("\nIngrese Nombre: ","\nError",1,51,1,array[posicion].nombre);
            utn_getName("\nIngrese Apellido: ","\nError",1,51,1,array[posicion].apellido);
            utn_getName("\nIngrese Domicilio: ","\nError",1,60,1,array[posicion].domicilio);
            utn_getName("\nIngrese sexo: F o M","\nError",1,20,1,array[posicion].sexo);
            utn_getTelefono("\nIngrese telefono: ","\nError",1,21,'0','9',2,array[posicion].telefono);

            printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Domicilio %s\n sexo: %s\n Telefono: %s",
                   posicion, array[posicion].idCliente,array[posicion].nombre,array[posicion].apellido,array[posicion].domicilio,array[posicion].sexo,array[posicion].telefono);
            retorno=0;
        }
    }
    return retorno;
}
int clientes_modificar(eClientes* array, int sizeArray)                                //cambiar
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcionModificar;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID del cliente que desea modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(clientes_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
            	 printf("\n Posicion: %d\n ID: %d\n Nombre: %s\n Apellido: %s\n Domicilio %s\n sexo: %s\n Telefono: %s",
            	                   posicion, array[posicion].idCliente,array[posicion].nombre,array[posicion].apellido,array[posicion].domicilio,array[posicion].sexo,array[posicion].telefono);
                utn_getChar("\nModificar: A B C S(salir)","\nError",'A','Z',1,&opcionModificar);
                switch(opcionModificar)
                {
                    case 'A':
                    	utn_getName("\nIngrese nuevo nombre: ","\nError",1,51,1,array[posicion].nombre);            //mensaje + cambiar campo varInt
                        break;
                    case 'B':
                    	utn_getName("\nIngrese nuevo domicilio: ","\nError",1,60,1,array[posicion].domicilio);               //mensaje + cambiar campo varFloat
                        break;
                    case 'C':
                    	 utn_getTelefono("\nIngrese nuevo telefono: ","\nError",1,21,'0','9',2,array[posicion].telefono);                      //mensaje + cambiar campo varString
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcionModificar!='S');
            retorno=0;
        }
    }
    return retorno;
}

int clientes_baja(eClientes* array, int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(clientes_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idCliente=0;
            strcpy(array[posicion].nombre,"");                                                   //cambiar campo varString
            strcpy(array[posicion].apellido,"");
            strcpy(array[posicion].domicilio,"");                                                   //cambiar campo varString
            strcpy(array[posicion].sexo,"");                                               //cambiar campo varLongString
            strcpy(array[posicion].telefono,"");
            retorno=0;
        }
    }
    return retorno;
}

int clientes_listar(eClientes* array, int size)                      //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
            	 printf("\n ID: %d\t\t Nombre: %s\t\t Apellido: %s\t\t Domicilio %s\t\t sexo: %s\t\t Telefono: %s",
            	                    array[i].idCliente,array[i].nombre,array[i].apellido,array[i].domicilio,array[i].sexo,array[i].telefono);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

int ordenarXApellidoYNombre(eClientes* array,int len)
{
    int i;
	int j;
	int ret = -1;
	eClientes buffer;

    if(len > 0 && array != NULL)
    {
    	for( i=0; i<len - 1; i++)
    	{
    		for( j=i+1; j<len; j++)
    		{
    			if(strcmp(array[j].apellido, array[i].apellido) < 0)
    			{
    				buffer = array[i];
    				array[i] = array[j];
    				array[j] = buffer;
    			}
    			else if(strcmp(array[j].apellido, array[i].apellido) == 0 && array[j].nombre < array[i].nombre)
    			{
    				buffer = array[i];
    				array[i] = array[j];
    				array[j] = buffer;
    			}
    		}
    	}
    	ret = 0;
    }
    return ret;
}

int menuClientes()
{
    int opcion;
    system("cls");
    printf("***Menu de Clientes***\n\n");
    printf("1- Alta de Cliente\n");
    printf("2- Modificar Cliente\n");
    printf("3- Baja de Cliente\n");
    printf("4- Listar Clientes\n");
    printf("5- Alta de Juegos\n");
    printf("6- Modificar Juegos\n");
    printf("7- Baja de Juegos\n");
    printf("8- Listar Juegos\n");
    printf("9- Alta de Alquileres\n");
    printf("10- Informes\n");
    printf("11- Salir\n");
    printf("\nIngrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}



