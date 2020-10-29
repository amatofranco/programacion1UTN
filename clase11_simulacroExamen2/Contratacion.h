

#ifndef CONTRATACION_H_
#define CONTRATACION_H_

#define MIN_ID 1
#define MAX_ID 1000
#define MAX_ARCHIVO 51
#define MIN_DNI 8
#define MAX_DNI 10
#define MAX_DIAS 100
#define QTY_CONTRATACIONES 100

struct {
char archivo[MAX_ARCHIVO];
char cuit[MAX_DNI];
int dias;
int idPantalla;

int id;
int isEmpty;
} typedef Contratacion;



/**
 * Imprime todos los datos del cliente
 * @param employee empleado a imprimir
 * @return 0 Éxito -1 Error
 */
int contratacion_imprimir(Contratacion *employee);




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
 * Busca un lugar vacio en el array y lo asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param puntero indice
 * @return 0 Éxito -1 Error
 */

int contratacion_emptyIndex(Contratacion *array, int length, int* indice);


/**
 * Agrega un cliente al array de clientes
 * @param list puntero a Array
 * @param len longitud del array
 * @param indice indice del Array donde se agregará
 * @param *pId puntero a contador de Id
 * @return 0 Éxito -1 Error
 */

int contratacion_alta(Contratacion *array, int length, int *pId, int idPantalla);

/**
 * Verifica si el array en su totalidad está vacio
 * @param list puntero a Array
 * @param length largo del Array
 * @return 1 Verdadero (Array vacio) 0 Falso
 */
int contratacion_emptyArray(Contratacion *list, int length);



/**
 * Verifica si existe una posición ocupada del array
 * que coincida con el valor del id y la asigna a puntero indice
 * @param list Puntero al array
 * @param len longitud del array
 * @param id id a buscar
 * @param puntero a indice
 * @return posición del array
 */
int contratacion_buscarId(Contratacion *array, int length, int id, int* indice);

/**
 * Actualiza o nombre, o apellido, o salario o sector de un empleado
 * de la lista de empleados, verificando si existe su id
 * @param list puntero a array de empleados
 * @param len longitud del array
 * @return 0 Éxito -1 Error
 */
int contratacion_modificar(Contratacion *array, int length);

/**
 * Pide un empleado de la lista de empleados a eliminar por id,
 * verifica que existe y llama a la funcion removeEmployee
 * @param list puntero a array de empleados
 * @param len largo del array
 * @return
 */

int contratacion_baja(Contratacion *list, int len);





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



int contratacion_altaForzada(Contratacion* array, int length, int* pId, char* archivo, char* cuit, int dias, int idPantalla);


#endif /* CONTRATACION_H_ */

