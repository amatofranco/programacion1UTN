

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define QTY_PANTALLAS 1000
#define QTY_TIPOS 2
#define MIN_PRECIO 500
#define MAX_PRECIO 200000
#define MIN_ID 1
#define MAX_ID 1000
#define MAX_NOMBRE 51
#define MAX_DIRECCION 51

#define TIPO_LED 1
#define TIPO_LCD 2

struct {
char nombre[MAX_NOMBRE];
char direccion[MAX_DIRECCION];
float precio;
int tipo;

int id;
int isEmpty;
} typedef Pantalla;




int pantalla_imprimir(Pantalla *employee);


int pantalla_imprimirArray(Pantalla* list, int length);


int pantalla_iniciar(Pantalla* list, int len);


int pantalla_emptyIndex(Pantalla *array, int length, int* indice);


int pantalla_alta(Pantalla *array, int length, int *pId);


int pantalla_emptyArray(Pantalla *list, int length);


int pantalla_buscarId(Pantalla *array, int length, int id, int* indice);


int pantalla_modificar(Pantalla *array, int length);


int pantalla_baja(Pantalla *list, int len);



int pantalla_ordenarNomTipo(Pantalla *array, int length);


int pantalla_altaForzada(Pantalla* array, int length, int* pId, char* nombre, char* direccion, float precio, int tipo);

#endif /* PANTALLA_H_ */

