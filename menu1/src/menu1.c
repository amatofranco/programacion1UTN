#include <stdio.h>
#include <stdlib.h>
​
int main(void)
{
    char respSalir='n';
    int flagControlSaludar=0;
    int flagControlBrindar=0;
​
​
    do
    {
​
        switch(menu())
        {
        case 'a':
            if(saludar()==0)
           // if(!saludar())
            {
                flagControlSaludar=1;
            }else{
                printf("\nHubo un error al saludar\n");
            }
            break;
​
        case 'b':
​
            if(!brindar(flagControlSaludar)){
                 flagControlBrindar=1;
            }else{
                printf("\nHubo un error al brindar\n");
            }
            break;
        case 'c':
           if(!despedirse(flagControlSaludar, flagControlBrindar)){
                flagControlBrindar=0;
                flagControlSaludar=0;
            }else{
                printf("\nHubo un error al despedirse\n");
            }
            break;
​
        case 'd':
            printf("Esta seguro que desea salir? s/n \n");
            fflush(stdin);
            scanf("%c", &respSalir);
            break;
        default:
            printf("Opcion invalida \n");
            break;
        }
        system("PAUSE"); // o getch(); //inlcuir conio.h
    }
    while(respSalir =='n' );
​
​
    return 0;
}
​
char menu(){
        char opcion;
        system("CLS");
        printf("Menu de Opciones\n");
        printf("a-Saludar \n");
        printf("b-Brindar \n");
        printf("c-Despedirse \n");
        printf("d-Salir \n");
        printf("Ingrese Opcion: \n");
        fflush(stdin);
        scanf("%c", &opcion);
        return opcion;
}
int saludar(){
    int retorno=0;
    int cant=0;
​
        cant= printf("Hola, como andas..\n");
        if(cant!=19){
            retorno=1;
        }
​
    return retorno;
}
​
int brindar(int flagControlSaludar){
    int retorno=0;
    int cant=0;
​
            if(flagControlSaludar)
            {
              cant= printf("chin chin..\n");
              if(cant!=12)
              {
                retorno=1;
              }
            }else
            {
                printf("Debe saludar antes de Brindar \n");
            }
​
    return retorno;
}
​
int despedirse(int flagControlSaludar, int flagControlBrindar){
    int retorno=0;
    int cant=0;
​
            if(!flagControlSaludar)
            {
                printf("Debe saludar antes de despedirse \n");
                retorno=1;
​
            }else if(flagControlBrindar)
            {
                cant= printf("chau..\n");
                if(cant!=7)
                {
                     retorno=1;
                }
            }else
             {
                printf("Debe brindar antes de despedirse\n");
                retorno=1;
             }
​
    return retorno;
}
