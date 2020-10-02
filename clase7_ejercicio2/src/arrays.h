
#ifndef ARRAYS_H_
#define ARRAYS_H_


/**
 * Iniciar todas las posiciones de un array en 0
 * @param array Array a trabajar
 * @param lenght Largo del array
 * @return 0 operacion exitosa -1 error
 */
int inicArrayInt(int array[], int lenght);

int inicArrayFloat(float array[], int lenght);



/**
 * Cargar valores aleatoriamente en un Array de tipo Int
 * @param mensajePos Mensaje para pedir la posicion del array
 * @param mensajeValor Mensaje para pedir el valor en esa posicion
 * @param mensajeError Mensaje para indicar posicion fuera de rango
 * @param array Array a trabajar
 * @param lenght Largo del array
 * @return 0 operacion exitosa -1 error
 */
int cargarArrayInt(char* mensajePos, char* mensajeValor, char*mensajeError, int array[], int lenght);

int cargarArrayFloat(char* mensajePos, char* mensajeValor, char*mensajeError, float array[], int lenght);


/**
 * Imprimir array de int
 * @param array a imrpimir
 * @param lenght tamaño del array
 * @return 0 operacion exitosa -1 error
 */

int imprimirArrayInt(int array[], int lenght);

int imprimirArrayFloat(int array[], int lenght);




#endif /* ARRAYS_H_ */
