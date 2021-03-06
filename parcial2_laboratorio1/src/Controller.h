
/**
 * Pide el nombre del archivo a cargar (datos.csv) y en caso de obtenerlo
 * Parsea los datos de los Artículos (Lectura en modo texto).
 * \param pArticuloList Puntero a Estructura LinkedList de Artículos
 * \return 0 Éxito -1 Error
 *
 */

int controller_loadFromText(LinkedList *pArticuloList);

/**
 * Imprime la lista completa de Artículos cargados
 * @param pArticuloList Puntero a Estructura LinkedList de Artículos
 * @return  0 Éxito -1 Error
 */
int controller_ListArticulo(LinkedList* pArticuloList);

/**
 * Ordena la lista de Artrículos segun criterio
 * @param pArticuloList Puntero a Estructura LinkedList de Artículos
 * @return 0 Éxito -1 Error
 */
int controller_sortArticulo(LinkedList* pArticuloList);

/**
 * Aplica el precio final a la lista de Artículos segun función de descuento
 * @param pArticuloList Puntero a Estructura LinkedList de Artículos
 * @return
 */
int controller_setFinalPrice(LinkedList *pArticuloList);


/**
 * Guarda la Lista de Artículos como un archivo csv
 * @param path Nombre de archivo a guardar
 * @param pArticuloList Puntero a Estructura LinkedList de Artículos
 * @return
 */

int controller_saveAsText(char* path , LinkedList* pArticuloList);

/**
 * Informa la cantidad de articulos de la lista cuyo precio sea mayor a 100
 * @param pArticuloList Puntero a LinkedList de Articulos
 * @return 0 Éxito -1 Error
 */
int controller_countMayorCien(LinkedList *pArticuloList);

/**
 * Informa la cantidad de articulos de la lista que sean del rubro 1
 * @param pArticuloList Puntero a LinkedList de Articulos
 * @return 0 Éxito -1 Error
 */

int controller_countRubroUno(LinkedList *pArticuloList);


