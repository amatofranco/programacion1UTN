#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int printEmployee(Employee* this){

	int ret = -1;

	if (this!= NULL){

	printf("%s, %d,%d,%d\n",this->nombre, this->horasTrabajadas, this->sueldo, this->id);

	ret = 0;

	}

	return ret;


}

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    int len;


    /*

    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);
    */


    Employee* e;

    e = (Employee*) malloc(sizeof(Employee));

    e->horasTrabajadas = 20;
    e->id = 2;
    strncpy(e->nombre,"Juan",50);
    e->sueldo = 30000;

    ll_add(listaEmpleados,e);


    Employee* e2;

        e2 = (Employee*) malloc(sizeof(Employee));

        e2->horasTrabajadas = 20;
        e2->id = 2;
        strncpy(e2->nombre,"Pepe",50);
        e2->sueldo = 40000;


        ll_add(listaEmpleados,e2);

        len = ll_len(listaEmpleados);

        //IMPRIMRI EMPLEADOS calcular len primero, en vez de llamar a la funcion siempre en el for

        Employee* aux;

        for (int i= 0; i<len;i++){

        	aux = (Employee*) ll_get(listaEmpleados,i);

        	printEmployee(aux);

        }
        //------------------BAJA EMPLEADO

		int index = 2; //ELECCION DEL USUARIO( seria ID 2, por lo que index = 1)

        ll_remove(listaEmpleados,index-1);

        Employee* aux2;

                for (int i= 0; i<len;i++){

                	aux2 = (Employee*) ll_get(listaEmpleados,i);

                	printEmployee(aux2);

                }








    return 0;
}

