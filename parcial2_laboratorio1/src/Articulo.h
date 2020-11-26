#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#define MAX_ID 5000
#define MAX_ARTICULO 51
#define MAX_DESCRIPCION 51
#define MAX_MEDIDA 51
#define MAX_PRECIO 1000000


typedef struct
{
    int id;
    char articulo[MAX_ARTICULO];
    char medida[MAX_MEDIDA];
    float precio;
    int rubroId;
}eArticulo;



/**
 * Guarda espacio en memoria correspondiente a un Artículo
 * y lo asigna a un puntero
 * @return Puntero al Artículo
 */

eArticulo* articulo_new(void);



/**
 *
 * Escribe los parámetros de un Artículo, recibidos por texto
 * @param idStr Id de Artículo (Texto)
 * @param articulo Nombre de Artículo (Texto)
 * @param medidaStr Medida del articulo (Texto)
 * @param rubroIdStr Id del rubro del Articulo (Texto)
 * @return Puntero al Artículo
 */

eArticulo* articulo_newParametrosTxt(char *idStr, char *articuloStr,char *medidaStr, char *precioStr, char *rubroIdStr);


/**
 *
 * Escribe los parámetros de un Artículo
 * @param id Id de Articulo
 * @param articulo Nombre de Articulo
 * @param medida Medida del articulo
 * @param precio Precio del articulo
 * @param rubroId Id del rubro del articulo
 * @return Puntero al Artículo
 */

eArticulo* articulo_newParametros(int id, char *articulo, char *medida, float precio,int rubroId);


/**
 * Libera el espacio en memoria correspondiente al Artículo
 * @param this Puntero a espacio en memoria a liberar
 * @return 0 Éxito -1 Error
 */
int articulo_delete(eArticulo *this);


/**
 * Asigna ID a un Artículo
 * @param this Puntero al Artículo
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */

int articulo_setId(eArticulo *this, int id);




/**
 * Asigna ID a un Artículo, recibido por texto
 * @param this Puntero a empleado
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */
int articulo_setIdTxt(eArticulo *this, char *id);



/**
 * Obtiene id de un Artículo
 * @param this Puntero a Artículo
 * @param id Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */
int articulo_getId(eArticulo* this,int* id);


/**
 * Asigna nombre de Artículo a un Artículo
 * @param this Puntero al Artículo
 * @param articulo Nombre de Artículo a asignar
 * @return 0 Éxito -1 Error
 */

int articulo_setArticulo(eArticulo *this, char *articulo);



/**
 * Obtiene nombre de un Artículo
 * @param this Puntero al Artículo
 * @param articulo Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */

int articulo_getArticulo(eArticulo *this, char *articulo);


/**
 * Asigna medida a un Artículo
 * @param this Puntero al Artículo
 * @param medida medida a asignar
 * @return 0 Éxito -1 Error
 */

int articulo_setMedida(eArticulo *this, char *medida);



/**
 * Obtiene medida de un Artículo
 * @param this Puntero al Artículo
 * @param medida Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */

int articulo_getMedida(eArticulo *this, char *medida);


/**
 * Asigna precio a un artículo
 * @param this Puntero a empleado
 * @param precio Precio a asignar
 * @return 0 Éxito -1 Error
 */

int articulo_setPrecio(eArticulo *this, float precio);


/**
 * Asigna precio a un Artículo, recibido como texto
 * @param this Puntero al Artículo
 * @param precio Precio a asignar (texto)
 * @return 0 Éxito -1 Error
 */
int articulo_setPrecioTxt(eArticulo *this, char *precio);

/**
 * Obtiene precio de un artículo
 * @param this Puntero al Artículo
 * @param precio Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */
int articulo_getPrecio(eArticulo *this, float *precio);

/**
 * Asigna Id de rubro a un Artículo
 * @param this Puntero al Artículo
 * @param rubroId Id de Rubro a Asignar
 * @return 0 Éxito -1 Error
 */
int articulo_setRubroId(eArticulo *this, int rubroId);

/**
 * Asigna Id de rubro a un Artículo, recibido como texto
 * @param this Puntero al Artículo
 * @param rubroId Id de Rubro a Asignar
 * @return 0 Éxito -1 Error
 */
int articulo_setRubroIdTxt(eArticulo *this, char *rubroId);

/**
 * Obtiene Id de Rubro de un Artñiculo
 * @param this Puntero al Artículo
 * @param rubroId Puntero a Resultado obtenido
 * @return 0 Éxito -1 Error
 */
int articulo_getRubroId(eArticulo *this, int *rubroId);

/**
 * Recibe el numero de Id de Rubro y devuelve su Descripción
 * @param rubroId RubroId a recibir
 * @param rubroString Descripción del rubro a devolver
 * @return 0 Éxito -1 Error
 */
int articulo_rubroToString(int rubroId, char *rubroString);


/**
 * Imprime todos los datos de un Artículo
 * @param this Puntero al Artículo
 * @return 0 Éxito -1 Error
 */

int articulo_print(eArticulo *this);



/**
 * Compara alfabéticamente los nombres entre dos Artículos
 * @param elementA Artículo A
 * @param elementB Artículo B
 * @return 0 Error 1 Artículo B anterior alfabéticamente -1 Artículo A anterior alfabeticamente
 */
int articulo_compareByName(void *elementA, void *elementB);

/**
 * Aplica descuento al precio de un Artículo en caso que corresponda
 * y lo imprime por pantalla
 * @param Element Puntero al artículo
 */
void articulo_setFinalPrice(void* Element);

/**
 * Verifica si el Artículo pertenece al Rubro Id 1
 * @param Element Puntero al Elemento(Artículo)
 * @return 1 PERTENECE 0 NO PERTENECE -1 ERROR (puntero Nulo)
 */
int articulo_rubroUno(void *Element);

/**
 * Verifica si el precio del Artículo es mayor a 100
 * @param Element Puntero al Elemento(Artículo)
 * @return 1 PERTENECE 0 NO PERTENECE -1 ERROR (puntero Nulo)
 */
int articulo_mayorCien(void *Element);





#endif // employee_H_INCLUDED
