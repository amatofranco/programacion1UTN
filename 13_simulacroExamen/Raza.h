

#ifndef CLIENTE_H_
#define CLIENTE_H_

#define QTY_RAZAS 1000
#define MIN_ID 1
#define MAX_ID 1000
#define MAX_DESCRIPCION 51

struct {
char descripcion[MAX_DESCRIPCION];
int tipo;
int tamaño;
char pais[MAX_DESCRIPCION];

int id;
int isEmpty;
} typedef Raza;



/**
 * Imprime todos los datos del cliente
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
int raza_imprimir(Raza *employee);




/** \brief Imprime la lista de clientes con sus respectivos datos
* \param list puntero a array de cliente
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/
int raza_imprimirArray(Raza* list, int length);



/**
* Para indicar que todas las posiciones del array están vacías,
* pone la bandera (isEmpty) en TRUE en todas las posiciones
* \param list puntero al array
* \param len largo del array
* \return 0 Éxito -1 Error
*
*/

int raza_iniciar(Raza* list, int len);

/**
 * Busca un lugar vacio en el array y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int raza_emptyIndex(Raza *array, int length, int* indice);


/**
 * Agrega un cliente al array de clientes
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int raza_alta(Raza *array, int length, int *pId);

/**
 * Verifica si el array en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int raza_emptyArray(Raza *list, int length);



/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int raza_buscarId(Raza *array, int length, int id, int* indice);

/**
 * Actualiza o nombre, o apellido, o salario o sector de un empleado
 * de la lista de empleados, verificando si existe su id
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int raza_modificar(Raza *array, int length);

/**
 * Pide un empleado de la lista de empleados a eliminar por id,
 * verifica que existe y llama a la funcion removeEmployee
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int raza_baja(Raza *list, int len);





/**
* Ordena los elementos del array
* en base a nombre y dni de manera ascendente o descendente
* @param array puntero a array
* @param largo del array
* @return 0 Éxito -1 Error
*
*/
int raza_ordenar(Raza *array, int length);



int raza_altaForzada(Raza* array, int length, int* pId, char* nombre, float altura, char* dni);


#endif /* CLIENTE_H_ */

