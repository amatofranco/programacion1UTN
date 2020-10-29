

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define QTY_CLIENTES 100
#define MIN_ID 1
#define MAX_ID 1000
#define MAX_NOMBRE 51
#define MIN_DNI 8
#define MAX_DNI 10

struct {
char nombre[MAX_NOMBRE];
float altura;
char dni[MAX_DNI];

int id;
int isEmpty;
} typedef Cliente;

// MEMORIA DINAMICA
int cli_inicializarArrayPunteros(Cliente** array, int length);

int cli_getEmptyIndex(Cliente **array, int length);

int cli_alta(Cliente **array, int length, int *pId);



Cliente* cli_new(void);


//

int cliente_imprimir(Cliente *employee);


int cliente_imprimirArray(Cliente* list, int length);


int cliente_iniciar(Cliente* list, int len);


int cliente_emptyIndex(Cliente *array, int length, int* indice);


int cliente_alta(Cliente *array, int length, int *pId);


int cliente_emptyArray(Cliente *list, int length);


int cliente_buscarId(Cliente *array, int length, int id, int* indice);

int cliente_modificar(Cliente *array, int length);


int cliente_baja(Cliente *list, int len);


int cliente_ordenarPorNombreDni(Cliente *array, int length);


int cliente_altaForzada(Cliente* array, int length, int* pId, char* nombre, float altura, char* dni);


#endif /* CLIENTE_H_ */

