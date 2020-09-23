
#ifndef UTN_H_
#define UTN_H_
/**
 * Pide un numero por scanf y valida segun maximo y minimo
 * @param pResultado puntero para numero validado
 * @param mensaje mensaje para ingresar numero
 * @param mensajeError mensaje de numero incorrecto
 * @param minimo numero minimo aceptado
 * @param maximo numero maximo aceptado
 * @param reintentos cantidad de reintentos posibles
 * @return operacion exitosa o error
 */
int utn_getNumero(int *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);


/**
 * Iniciar todas las posiciones de un array en 0
 * @param array Array a trabajar
 * @param lenght Largo del array
 */
int inicializarArray(int array[], int lenght)


/**
 * Cargar valores aleatoriamente en un Array de tipo Int
 * @param mensajePos Mensaje para pedir la posicion del array
 * @param mensajeValor Mensaje para pedir el valor en esa posicion
 * @param mensajeError Mensaje para indicar posicion fuera de rango
 * @param array Array a trabajar
 * @param lenght Largo del array
 */
int cargarArrayInt(char* mensajePos, char* mensajeValor, char*mensajeError, int array[], int lenght);

#endif /* UTN_H_ */
