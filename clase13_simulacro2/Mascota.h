

#ifndef MASCOTA_H_
#define MASCOTA_H_

#define QTY_MASCOTAS 1000
#define QTY_TIPOS 3
#define MIN_EDAD 1
#define MAX_EDAD 100
#define MIN_ID 1
#define MAX_ID 1000
#define MAX_NOMBRE 51
#define MAX_SEXO 1

#define TIPO_LED 1
#define TIPO_LCD 2

struct {
char nombre[MAX_NOMBRE];
char sexo[MAX_SEXO];
int edad;
int tipo;

int id;
int isEmpty;
} typedef Mascota;




int mascota_imprimir(Mascota *employee);


int mascota_imprimirArray(Mascota* list, int length);


int mascota_iniciar(Mascota* list, int len);


int mascota_emptyIndex(Mascota *array, int length, int* indice);


int mascota_alta(Mascota *array, int length, int *pId);


int mascota_emptyArray(Mascota *list, int length);


int mascota_buscarId(Mascota *array, int length, int id, int* indice);


int mascota_modificar(Mascota *array, int length);


int mascota_baja(Mascota *list, int len);


int mascota_ordenar(Mascota *array, int length);


int mascota_altaForzada(Mascota *array, int length, int *pId, char *nombre,
		char *sexo, int edad, int tipo);
#endif /* MASCOTA_H_ */

