

#ifndef PANTALLA_H_
#define PANTALLA_H_

#define QTY_TIPOS 2
#define MIN_PRECIO 500
#define MAX_PRECIO 200000
#define MIN_ID 1
#define MAX_ID 1000
#define MAX_NOMBRE 51
#define MAX_DIRECCION 51
#define QTY_PANTALLAS 100


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



/**
 * Imprime todos los datos del cliente
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
int pantalla_imprimir(Pantalla *employee);




/** \brief Imprime la lista de clientes con sus respectivos datos
* \param list puntero a array de cliente
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/
int pantalla_imprimirArray(Pantalla* list, int length);



/**
* Para indicar que todas las posiciones del array están vacías,
* pone la bandera (isEmpty) en TRUE en todas las posiciones
* \param list puntero al array
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/

int pantalla_iniciar(Pantalla* list, int len);

/**
 * Busca un lugar vacio en el array y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int pantalla_emptyIndex(Pantalla *array, int length, int* indice);


/**
 * Agrega un cliente al array de clientes
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int pantalla_alta(Pantalla *array, int length, int *pId);

/**
 * Verifica si el array en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int pantalla_emptyArray(Pantalla *list, int length);



/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int pantalla_buscarId(Pantalla *array, int length, int id, int* indice);

/**
 * Actualiza o nombre, o apellido, o salario o sector de un empleado
 * de la lista de empleados, verificando si existe su id
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int pantalla_modificar(Pantalla *array, int length);

/**
 * Pide un empleado de la lista de empleados a eliminar por id,
 * verifica que existe y llama a la funcion removeEmployee
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int pantalla_baja(Pantalla *list, int len);



/**
* Ordena los elementos del array
* en base a nombre y dni de manera ascendente o descendente
* @param array puntero a array
* @param largo del array
* @return 0 Éxito -1 Error
*
*/
int pantalla_ordenarNomTipo(Pantalla *array, int length);



/**
 * Calcula el promedio del salario de los empleados
 * y la cantidad de salarios por encima del promedio y lo imprime
 * @param list puntero a array de empleados
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */


int pantalla_altaForzada(Pantalla* array, int length, int* pId, char* nombre, char* direccion, float precio, int tipo);


#endif /* PANTALLA_H_ */

