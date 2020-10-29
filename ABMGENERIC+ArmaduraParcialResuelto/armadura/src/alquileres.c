#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "alquileres.h"
#include "juegos.h"
#include "clientes.h"

int obtenerEspacioLibreAlquiler(eAlquiler* rent , int cantidad,int cantiGame){
    int i, retorno=-1;
    for (i=0;i<cantidad*cantiGame;i++){
        if(rent[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
    void addRent(eAlquiler* rent,int cantidad,int cantiGame,eCliente* user,eJuego* game)
    {
        int index;
        char salida;
        index=obtenerEspacioLibreAlquiler(rent,cantidad,cantiGame);
        if(index!=-1)
        {
            do{
                system("cls");
                printf("***Alquileres***\n\n");
                rent[index].idAlquier=index+1;
                printf("Codigo de alquier: %d\n",rent[index].idAlquier);
                rent[index].idCliente=selecUser(user,cantidad);
                rent[index].idJuego=selecGame(game,cantiGame);
                printf("Fecha\n");
                GetDay(rent,index);
                system("cls");
                printRent(rent[index],game,user,cantidad,cantiGame);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }while(salida!='s');
            rent[index].isEmpty=0;
        }
    }

    void printRent(eAlquileres rent,eJuego* game,eCliente* user,int cantidad,int cantiGame)
    {
        char descripcion[51],nombre[102];
        cargarNombre(user,cantidad,rent.idCliente,nombre);
        cargarDescripcion(game,cantiGame,rent.idJuego,descripcion);
        printf("\nID alquiler: %d",rent.idAlquier);
        printf("\tCliente: %s",nombre);
        printf("\tJuegos: %s",descripcion);
        printf("\tFecha: %d/%d/%d\n",rent.fecha.dia,rent.fecha.mes,rent.fecha.anio);
    }
    void GetDay(eAlquiler* rent, int cantidad)
        {
            utn_getEntero(&rent[cantidad].fecha.mes,"Mes del 1 al 12: ","ERROR Mes del 1 al 12: ",1,12);
            switch(rent[cantidad].fecha.mes){
                case 2:
                    utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 28: ","ERROR Dia del 1 al 28: ",1,28);
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 30: ","ERROR Dia del 1 al 30: ",1,30);
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 31: ","ERROR Dia del 1 al 31: ",1,31);
                    break;
            }
            utn_getEntero(&rent[cantidad].fecha.anio,"Anio 2018 o 2019: ","ERROR Anio 2018 o 2019: ",2018,2019);
        }
