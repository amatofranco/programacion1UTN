

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define QTY_CLIENTES 100
#define MIN_ID 1
#define MAX_ID 10
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
int cli_inicializarArrayPunteros(Cliente* array[], int length);

int cli_getEmptyIndex(Cliente* array[], int length);

int cli_printArray(Cliente *array[], int length);

Cliente* cli_new(void);

Cliente* cli_newParametros(char* nombre,float altura, char* dni, int id);

Cliente* cli_newParametrosTxt(char *nombre, char *altura, char *dni, char *id);


void cli_delete(Cliente* this);

int cli_deleteIndex(Cliente* array[],int length,int index);


int cli_setNombre(Cliente* this, char* nombre);

int cli_getNombre(Cliente* this, char* nombre);

int cli_setAltura(Cliente *this, float altura);

int cli_setAlturaTxt(Cliente *this, char *altura);


int cli_getAltura(Cliente *this, float* altura);

int cli_setDni(Cliente *this, char *dni);

int cli_setDniTxt(Cliente *this, char *dni);

int cli_getDni(Cliente *this, char *dni);

int cli_setId (Cliente* this, int id);

int cli_setIdTxt (Cliente* this, char* id);


int cli_getId(Cliente *this, int* id);

int cli_getIdTxt(Cliente *this, char *id);



int cli_getById(Cliente *array[], int length, int id);

int cli_alta(Cliente **array, int length, int *pId);


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

