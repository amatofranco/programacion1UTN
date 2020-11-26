#include "Articulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Valida que la cadena recibida sea un número
 * @param string Cadena a analizar
 * @param length largo de la cadena
 * @return 0 Éxito -1 Error
 */
static int isValidNumber(char *string, int length);

/**
 * Valida que la cadena recibida sean números o letras
 * @param string Cadena a validar
 * @param length Largo de la cadena
 * @return 0 Éxito -1 Error
 */
static int isAlphanumeric(char *string, int length);

static int isValidNumber(char *string, int length) {

	int ret = 1;

	if (string != NULL && length > 0) {

		for (int i = 0; i < length && string[i] != '\0'; i++) {

			if (string[i] == '.') {

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

eArticulo* articulo_new(void) {

	eArticulo *auxP = NULL;

	auxP = (eArticulo*) malloc(sizeof(eArticulo));

	return auxP;

}

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

			printf("No pudo agregarse: Art Id %s: %s\n", idStr, articuloStr);

			articulo_delete(this);

			this = NULL;

		}

	}

	return this;
}

eArticulo* articulo_newParametros(int id, char *articulo, char *medida,
		float precio, int rubroId) {

	eArticulo *this = NULL;

	this = articulo_new();

	if (this != NULL && articulo != NULL && medida >= 0 && rubroId) {

		if (articulo_setId(this, id) == -1
				|| articulo_setArticulo(this, articulo) == -1
				|| articulo_setMedida(this, medida) == -1
				|| articulo_setRubroId(this, rubroId) == -1
				|| articulo_setPrecio(this, precio) == -1) {

			articulo_delete(this);

			this = NULL;

		}

	}

	return this;
}

int articulo_delete(eArticulo *this) {

	int ret = -1;

	if (this != NULL) {

		free(this);

		ret = 0;

	}

	return ret;

}

int articulo_setId(eArticulo *this, int id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		this->id = id;

		ret = 0;

	}

	return ret;

}

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

int articulo_getId(eArticulo *this, int *id) {

	int ret = -1;

	if (this != NULL && id >= 0) {

		*id = this->id;

		ret = 0;

	}

	return ret;
}

int articulo_setArticulo(eArticulo *this, char *articulo) {

	int ret = -1;

	if (this != NULL && articulo != NULL) {

		strncpy(this->articulo, articulo, MAX_ARTICULO);

		ret = 0;

	}

	return ret;
}

int articulo_getArticulo(eArticulo *this, char *articulo) {

	int ret = -1;

	if (this != NULL && articulo != NULL) {

		strncpy(articulo, this->articulo, MAX_ARTICULO);

		ret = 0;

	}

	return ret;
}

int articulo_setMedida(eArticulo *this, char *medida) {

	int ret = -1;

	if (this != NULL && medida != NULL) {

		if (isAlphanumeric(medida, MAX_MEDIDA)) {

			strncpy(this->medida, medida, MAX_MEDIDA);

			ret = 0;

		}

	}

	return ret;
}

int articulo_getMedida(eArticulo *this, char *medida) {

	int ret = -1;

	if (this != NULL && medida != NULL) {

		strncpy(medida, this->medida, MAX_MEDIDA);

		ret = 0;

	}

	return ret;
}

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

int articulo_setRubroIdTxt(eArticulo *this, char *rubroId) {

	int ret = -1;

	int rubroIdAux;

	if (this != NULL && rubroId != NULL) {

		if (isValidNumber(rubroId, 4)) {

			rubroIdAux = atoi(rubroId);

			this->rubroId = rubroIdAux;

			ret = 0;

		}

	}

	return ret;
}

int articulo_getRubroId(eArticulo *this, int *rubroId) {

	int ret = -1;

	if (this != NULL && rubroId != NULL) {

		*rubroId = this->rubroId;

		ret = 0;

	}

	return ret;
}

int articulo_rubroToString(int rubroId, char *rubroString) {

	int ret = -1;

	if (rubroId >= 0 && rubroString != NULL) {

		ret = 0;

		switch (rubroId) {

		case 1:

			strncpy(rubroString, "Cuidado de Ropa", MAX_DESCRIPCION);
			break;

		case 2:

			strncpy(rubroString, "Limpieza y Desinfeccion", MAX_DESCRIPCION);
			break;

		case 3:

			strncpy(rubroString, "Cuidado Personal e Higiene", MAX_DESCRIPCION);
			break;

		case 4:

			strncpy(rubroString, "Cuidado del Automotor", MAX_DESCRIPCION);
			break;
		}

	}
	return ret;

}

int articulo_print(eArticulo *this) {

	int ret = -1;

	int id;

	char articulo[MAX_ARTICULO];

	char medida[MAX_MEDIDA];

	char descripcionRubro[MAX_DESCRIPCION];

	int rubroId;

	float precio;

	if (this != NULL &&

	articulo_getId(this, &id) == 0 &&

	articulo_getArticulo(this, articulo) == 0 &&

	articulo_getMedida(this, medida) == 0 &&

	articulo_getRubroId(this, &rubroId) == 0 &&

	articulo_getPrecio(this, &precio) == 0  &&

	articulo_rubroToString(rubroId,descripcionRubro)==0)


	{

		printf("%10d | %40s  | %10s | %10.2f | %10s\n", id, articulo, medida,
				precio, descripcionRubro);

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
	char nombreB[MAX_ARTICULO];

	if (articulo_getArticulo(articuloA, nombreA) == 0
			&& articulo_getArticulo(articuloB, nombreB) == 0) {

		if (strncmp(nombreA, nombreB, MAX_ARTICULO) > 0) {

			ret = 1;
		}


		if (strncmp(nombreA, nombreB, MAX_ARTICULO) < 0) {

			ret = -1;
		}

	}
	return ret;
}

void articulo_setFinalPrice(void *Element) {

	int rubroIdAux;
	float precioAux;
	int idAux;
	char articuloAux[51];
	int flagArt = 0;
	eArticulo *this = (eArticulo*) Element;

	if (this != NULL) {

		if (articulo_getRubroId(this, &rubroIdAux) == 0
				&& articulo_getPrecio(this, &precioAux) == 0) {

			if (rubroIdAux == 1 && precioAux >= 120) {

				flagArt = 1;

				articulo_setPrecio(this, precioAux * 0.8);

			}

			else if (rubroIdAux == 2 && precioAux <= 200) {

				flagArt = 1;

				articulo_setPrecio(this, precioAux * 0.9);

			}

			if (flagArt) {

				articulo_getId(this, &idAux);

				articulo_getArticulo(this, articuloAux);

				printf("Se modificó Art. Id %d: %s\n", idAux, articuloAux);
			}
		}
	}
}


int articulo_mayorCien(void *Element){

	int ret = -1;

	float precioAux;

	eArticulo* this = (eArticulo*)Element;

	if(Element!=NULL){

		ret = 0;


		if(articulo_getPrecio(this,&precioAux)==0 && precioAux>100){

			articulo_print(this);

			ret = 1;

		}

	}

	return ret;


}



int articulo_rubroUno(void *Element){

	int ret = -1;

	int rubroIdAux;

	eArticulo* this = (eArticulo*)Element;

	if(Element!=NULL){

		ret = 0;


		if(articulo_getRubroId(this,&rubroIdAux)==0 && rubroIdAux==1){

			articulo_print(this);

			ret = 1;

		}

	}

	return ret;


}




