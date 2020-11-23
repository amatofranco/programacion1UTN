#include "Articulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static int isValidNumber(char *string, int length);

static int isValidName(char *string, int length);

static int isAlphanumeric(char *string, int length);




/**
 * Valida que la cadena recibida sea un número
 * @param string Cadena a analizar
 * @param length largo de la cadena
 * @return 0 Éxito -1 Error
 */
static int isValidNumber(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && (string[i] == '+' || string[i] == '-')) {

				continue;
			}

			if (string[i] < '0' || string[i] > '9') {

				ret = 0;

				break;

			}
		}
	}
	return ret;

}


/**
 * Valida que la cadena ingresada sea un nombre
 * @param string Cadena a analizar
 * @param length Largo de la cadena
 * @return 0 Éxito -1 Error
 */
static int isValidName(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i == 0 && string[i] >= 'A' && string[i] <= 'Z') {

				continue;
			}

			if (i != 0 && (string[i] == '-' || string[i] == ' ')) {

				continue;
			}

			if (string[i] < 'a' || string[i] > 'z') {

				ret = 0;

				break;

			}

		}
	}

	return ret;

}

static int isAlphanumeric(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (i != 0 && string[i] == ' ') {

				continue;
			}

			if ((string[i] < '0' || string[i] > '9')
					&& (string[i] < 'A' || string[i] > 'Z')
					&& (string[i] < 'a' || string[i] > 'z')) {

				ret = 0;
				break;
			}
		}

	}

	return ret;

}

/**
 * Guarda espacio en memoria correspondiente a un empleado
 * y lo asigna a un puntero
 * @return Puntero al empleado
 */


eArticulo* articulo_new(void) {

	eArticulo *auxP = NULL;

	auxP = (eArticulo*) malloc(sizeof(eArticulo));

	return auxP;

}

/**
 *
 * Escribe los parámetros de un Artículo, recibidos por texto
 * @param idStr Id de Artículo
 * @param articulo Nombre de Artículo
 * @param medidaStr Medida del articulo
 * @param rubroIdStr Id del rubro del Articulo
 * @return
 */


eArticulo* articulo_newParametrosTxt(char *idStr, char *articuloStr,
		char *medidaStr, char *precioStr, char *rubroIdStr) {

	eArticulo *this = NULL;

	this = articulo_new();

	if (this != NULL && idStr != NULL && articuloStr != NULL
			&& medidaStr != NULL && rubroIdStr != NULL) {

		if (articulo_setIdTxt(this, idStr) == -1
				|| articulo_setArticulo(this, articuloStr) == -1
				|| articulo_setMedida(this, medidaStr) == -1
				|| articulo_setRubroIdTxt(this, rubroIdStr) == -1
				|| articulo_setPrecioTxt(this, precioStr) == -1) {

			printf("Se borró id %s %s\n", idStr, articuloStr);

			articulo_delete(this);

			this = NULL;

		}

	}

	return this;
}

/**
 *
 * Escribe los parámetros de un empleado
 * @param id Id de empleado
 * @param nombre Nombre de empleado
 * @param horasTrabajadas Horas trabajadas del empleado
 * @param sueldo Sueldo del empleado
 * @return
 */

eArticulo* articulo_newParametros(int id, char *articulo, char *medida, float precio,
		int rubroId) {

	eArticulo *this = NULL;

	this = articulo_new();

	if (this != NULL && articulo != NULL && medida >= 0 && rubroId) {

		if (articulo_setId(this, id) == -1
				|| articulo_setArticulo(this, articulo) == -1
				|| articulo_setMedida(this, medida) == -1
				|| articulo_setRubroId(this, rubroId) == -1
			    || articulo_setPrecio(this, precio) == -1)  {

			articulo_delete(this);

			this = NULL;

		}

	}

	return this;
}

/**
 * Libera el espacio en memoria correspondiente al empleado
 * @param this Puntero a espacio en memoria a liberar
 * @return 0 Éxito -1 Error
 */

int articulo_delete(eArticulo *this) {

	int ret = -1;

	if (this != NULL) {

		free(this);

		ret = 0;

	}

	return ret;

}

/**
 * Asigna ID a un empleado
 * @param this Puntero a empleado
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */

int articulo_setId(eArticulo *this, int id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		this->id = id;

		ret = 0;

	}

	return ret;

}


/**
 * Asigna ID a un empleado, recibido por texto
 * @param this Puntero a empleado
 * @param id Id a asignar
 * @return 0 Éxito -1 Error
 */


int articulo_setIdTxt(eArticulo *this, char *id) {

	int ret = -1;

	if (this != NULL && id != NULL) {

		if (isValidNumber(id, MAX_ID)) {

			this->id = atoi(id);

			ret = 0;

		}

	}

	return ret;

}


/**
 * Obtiene id de un empleado
 * @param this Puntero a empleado
 * @param id Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int articulo_getId(eArticulo *this, int *id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		*id = this->id;

		ret = 0;

	}

	return ret;
}


/**
 * Asigna nombre a un empleado
 * @param this Puntero a empleado
 * @param id Nombre a asignar
 * @return 0 Éxito -1 Error
 */


int articulo_setArticulo(eArticulo *this, char *articulo) {

	int ret = -1;

	if (this != NULL && articulo != NULL) {

		if (isValidName(articulo, MAX_ARTICULO)) {//VALIDAR TEXTO

			strncpy(this->articulo, articulo, MAX_ARTICULO);

			ret = 0;

		}

	}

	return ret;
}

/**
 * Obtiene nombre de un empleado
 * @param this Puntero a empleado
 * @param nombre Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int articulo_getArticulo(eArticulo *this, char *articulo) {

	int ret = -1;

	if (this != NULL && articulo != NULL) {

		strncpy(articulo, this->articulo, MAX_ARTICULO);

		ret = 0;

	}

	return ret;
}

/**
 * Asigna horas trabajadas a un empleado
 * @param this Puntero a empleado
 * @param horasTrabajadas horas trabajadas a asignar
 * @return 0 Éxito -1 Error
 */



int articulo_setMedida(eArticulo *this, char *medida) {

	int ret = -1;

	if (this != NULL && medida !=NULL) {

		if (isAlphanumeric(medida, MAX_MEDIDA)) {//VALIDAR TEXTO

					strncpy(this->medida, medida, MAX_MEDIDA);

					ret = 0;

				}

	}

	return ret;
}




/**
 * Obtiene horas trabajadas de un empleado
 * @param this Puntero a empleado
 * @param horasTrabajadas Puntero a resultado obtenido
 * @return 0 Éxito -1 Error
 */


int articulo_getMedida(eArticulo *this, char *medida) {

	int ret = -1;

	if (this != NULL && medida != NULL) {

		strncpy(medida, this->medida, MAX_MEDIDA);

		ret = 0;

	}

	return ret;
}


/**
 * Asigna sueldo a un empleado
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */


int articulo_setPrecio(eArticulo *this, float precio) {

	int ret = -1;

	if (this != NULL && precio >= 0) {

		this->precio = precio;

		ret = 0;

	}

	return ret;
}


int articulo_setPrecioTxt(eArticulo *this, char *precio) {

	int ret = -1;

	float precioAux;

	if (this != NULL && precio != NULL) {

		if (isValidNumber(precio, MAX_PRECIO)) {

			precioAux = atof(precio);

			this->precio = precioAux;

			ret = 0;
		}

	}

	return ret;
}


int articulo_getPrecio(eArticulo *this, float *precio) {

	int ret = -1;

	if (this != NULL && precio != NULL) {

		*precio = this->precio;

		ret = 0;

	}

	return ret;
}



int articulo_setRubroId(eArticulo *this, int rubroId) {

	int ret = -1;

	if (this != NULL && rubroId >= 0) {

		this->rubroId = rubroId;
		ret = 0;

	}

	return ret;
}

/**
 * Asigna sueldo a un empleado, recibido desde texto
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */



int articulo_setRubroIdTxt(eArticulo *this, char *rubroId) {

	int ret = -1;

	int rubroIdAux;

	if (this != NULL && rubroId != NULL) {

		if (isValidNumber(rubroId, MAX_PRECIO)) {

			rubroIdAux = atoi(rubroId);

			this->rubroId = rubroIdAux;

			ret = 0;
		}

	}

	return ret;
}


/**
 * Obtiene sueldo de un empleado
 * @param this Puntero a empleado
 * @param sueldo sueldo a asignar
 * @return 0 Éxito -1 Error
 */


int articulo_getRubroId(eArticulo *this, int *rubroId) {

	int ret = -1;

	if (this != NULL && rubroId != NULL) {

		*rubroId = this->rubroId;

		ret = 0;

	}

	return ret;
}

/**
 * Imprime datos de un empleado
 * @param this Puntero a empleado
 * @return 0 Éxito -1 Error
 */



int articulo_print(eArticulo *this) {

	int ret = -1;

	int id;

	char articulo[MAX_ARTICULO];

	char medida[MAX_MEDIDA];

	int rubroId;

	float precio;

	if (this != NULL &&

	articulo_getId(this, &id) == 0 &&

	articulo_getArticulo(this, articulo) == 0 &&

	articulo_getMedida(this, medida) == 0 &&

	articulo_getRubroId(this, &rubroId) == 0 &&

	articulo_getPrecio(this, &precio) == 0)

	{

		printf("%10d | %20s  | %20s | %20.2f | %20d |\n", id,
				articulo, medida, precio, rubroId);

	}

	return ret;

}

/**
 * Compara mayor sueldo entre dos empleados
 * @param elementA Puntero (void) a castear (EmployeeA)
 * @param elementB Puntero (void) a castear (EmployeeB)
 * @return 0 Error 1 Sueldo de Empleado A mayor -1 Sueldo de Empleado B mayor
 */


int articulo_compareByRubroId(void *elementA, void *elementB) {

	int ret = 0;
	eArticulo *articuloA;
	eArticulo *articuloB;
	articuloA = (eArticulo*) elementA;
	articuloB = (eArticulo*) elementB;

	int rubroA;
	int rubroB;

	if (articulo_getRubroId(articuloA, &rubroA) == 0 && articulo_getRubroId(articuloB, &rubroB) == 0) {

		if (rubroA > rubroB) {

			ret = 1;

		}

		if(rubroA < rubroB){

			ret = -1;
		}

	}

	return ret;
}

int articulo_compareByName(void *elementA, void *elementB) {

	int ret = 0;
	eArticulo *articuloA;
	eArticulo *articuloB;
	articuloA = (eArticulo*) elementA;
	articuloB = (eArticulo*) elementB;

	char nombreA[MAX_ARTICULO];
	char nombreB [MAX_ARTICULO];

	if (articulo_getArticulo(articuloA,nombreA)==0 && articulo_getArticulo(articuloB,nombreB)==0){

		if (strncmp(nombreA,nombreB,MAX_ARTICULO)>0){

			ret = 1;
		}

		if (strncmp(nombreA,nombreB,MAX_ARTICULO)<0){

			ret = -1;
		}

	}
	return ret;
}
