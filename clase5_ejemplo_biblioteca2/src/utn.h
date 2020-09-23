
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

static int esNumerica(char *cadena);


int utn_getChar(int *pResultado, char *mensaje, char *mensajeError, char minimo,
		char maximo, int reintentos);

#endif /* UTN_H_ */
