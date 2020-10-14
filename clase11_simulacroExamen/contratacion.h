

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define MIN_ID 1
#define MAX_ID 1000
#define MAX_DIRECCION 51
#define MAX_APELLIDO 51

struct {
int id;
char direccion[MAX_DIRECCION];
float precio;
int tipo;
int isEmpty;
} typedef Contratacion;



/**
 * Imprime todos los datos del cliente
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
int contratacion_imprimir(Contratacion *pantalla);




/** \brief Imprime la lista de clientes con sus respectivos datos
* \param list puntero a array de cliente
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/
int contratacion_imprimirArray(Contratacion* list, int length);



/**
* Para indicar que todas las posiciones del array están vacías,
* pone la bandera (isEmpty) en TRUE en todas las posiciones
* \param list puntero al array
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/

int contratacion_iniciar(Contratacion* list, int len);

/**
 * Devuelve el primer indice vacio del array, en caso de que exista
 * @param list Puntero al array
 * @param len longitud del array
 * @return -1 Array Completo >=0 Indice vacio
 */

int contratacion_emptyIndex(Contratacion *list, int len);


/**
 * Agrega un cliente al array de clientes
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int contratacion_alta(Contratacion *array, int length, int indice, int *pId);

/**
 * Verifica si el array en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int contratacion_emptyArray(Contratacion *list, int length);



/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del parametro id y devuelve la posicion
 * @param list Puntero a array de empleados
 * @param len longitud del array
 * @param id id a buscar
 * @return posición del array
 */
int pantalla_buscarId(Contratacion* list, int len,int id);

/**
 * Actualiza o nombre, o apellido, o salario o sector de un empleado
 * de la lista de empleados, verificando si existe su id
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int pantalla_modificar(Contratacion *array, int length);

/**
 * Pide un empleado de la lista de empleados a eliminar por id,
 * verifica que existe y llama a la funcion removeEmployee
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int pantalla_baja(Contratacion *list, int len);





/**
* Ordena los elementos del array
* en base a nombre y dni de manera ascendente o descendente
* @param array puntero a array
* @param largo del array
* @return 0 Éxito -1 Error
*
*/
int contratacion_ordenar(Contratacion *array, int length);



/**
 * Calcula el promedio del salario de los empleados
 * y la cantidad de salarios por encima del promedio y lo imprime
 * @param list puntero a array de empleados
 * @param length largo del array
 * @return 0 Éxito -1 Error
 */



#endif /* CONTRATACION_H_ */

