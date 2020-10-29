#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "juegos.h"

void cargarCategorias(eCategoria categorias[], int tamc)
{
    eCategoria sec[]=
    {
        {1, "Mesa"},
        {2, "Azar"},
        {3, "Estrategia"},
        {4, "salon"},
        {5, "magia"}
    };

    for(int i=0; i <tamc; i++)
    {
        categorias[i] = sec[i];
    }
}
int clientes_Inicializar(eJuegos* array, int size)
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
int clientes_buscarEmpty(eJuegos* array, int size, int* posicion)                    //cambiar fantasma
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

int clientes_alta(eJuegos* array, int size, int* contadorID)                          //cambiar fantasma
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
            array[posicion].idJuegos=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getTexto("\nIngrese Nombre: ","\nError",1,51,1,array[posicion].descripcion);
            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].importe);
            utn_getName("\nIngrese Domicilio: ","\nError",1,60,1,array[posicion].domicilio);
            utn_getName("\nIngrese sexo: F o M","\nError",1,20,1,array[posicion].sexo);
            utn_getTelefono("\nIngrese telefono: ","\nError",1,21,'0','9',2,array[posicion].telefono);

            printf("\n Posicion: %d\n ID: %d\n descripcion: %s\n Importe: %2.f\n ",
                   posicion, array[posicion].idJuegos,array[posicion].descripcion,array[posicion].importe);
            retorno=0;
        }
    }
    return retorno;
}

int clientes_listar(eJuegos* array, int size)                      //cambiar fantasma
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
            	printf("\n ID: %d\n descripcion: %s\n Importe: %2.f\n ",
            	                    array[i].idJuegos,array[i].descripcion,array[i].importe);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}

int clientes_baja(eJuegos* array, int sizeArray)                                      //cambiar fantasma
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
            array[posicion].idJuegos=0;
            strcpy(array[posicion].descripcion,"");                                                   //cambiar campo varString
            array[posicion].importe=0;

            retorno=0;
        }
    }
    return retorno;
}

int clientes_buscarID(eJuegos* array, int size, int valorBuscado, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idJuegos==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}


void cargarDescripcion(eJuegos* game, int cantidad, int idJuego, char cadena[])
{
        int i;
        for(i=0; i < cantidad; i++)
        {
            if( game[i].idJuegos == idJuego)
            {
                strcpy(cadena, game[i].descripcion);
                break;
            }
        }
    }

    void sortGameRent(eJuegos* game, int cantidad){
        eJuegos gameAux;
        int i,flag=1;
            while(flag==1){
                flag=0;
                for(i=1;i<cantidad;i++){
                    if(game[i].idJuegos<game[i-1].idJuegos&&(game[i].isEmpty==0&&game[i-1].isEmpty==0)){
                        gameAux=game[i];
                        game[i]=game[i-1];
                        game[i-1]=gameAux;
                        flag=1;
                    }
                }
        }
    }

    int selecGame(eJuegos* game, int cantidad)
    {
        int idGame;
        int i;
        sortGameRent(game,cantidad);
        printf("\nJuegos\n\n");
        for(i=0; i < cantidad; i++)
        {
            if(game[i].isEmpty==0)
            printf("%d %s \n", game[i].idJuegos, game[i].descripcion);
        }
        utn_getEntero(&idGame,"\nSeleccione ID de juego: ","ERROR seleccione ID valido: ",1,cantidad);
        for(i=0;i<cantidad;i++){
            if(idGame==game[i].idJuego && game[i].isEmpty==0)
            {
                break;
            }
            if(i==cantidad-1){
                printf("\nEl juego no existe...");
                utn_getEntero(&idGame,"\nSeleccione ID de juego: ","ERROR seleccione ID valido: ",1,cantidad);
                i=0;
            }
        }
        return idGame;
    }


    void sortGameImport(eJuego* game, int cantidad){
        eJuego gameAux;
        int i,flag=1;
            while(flag==1){
                flag=0;
                for(i=1;i<cantidad;i++){
                    if(game[i].importe>game[i-1].importe &&(game[i].isEmpty==0&&game[i-1].isEmpty==0)){
                        gameAux=game[i];
                        game[i]=game[i-1];
                        game[i-1]=gameAux;
                        flag=1;
                    }
                }
        }
    }
