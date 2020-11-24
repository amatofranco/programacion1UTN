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




eArticulo* articulo_new(void);
eArticulo* articulo_newParametrosTxt(char *idStr, char *articuloStr,char *medidaStr, char *precioStr, char *rubroIdStr);
eArticulo* articulo_newParametros(int id, char *articulo, char *medida, float precio,int rubroId);
int articulo_delete(eArticulo *this);

int articulo_setId(eArticulo *this, int id);
int articulo_setIdTxt(eArticulo *this, char *id);
int articulo_getId(eArticulo* this,int* id);

int articulo_setArticulo(eArticulo *this, char *articulo);
int articulo_getArticulo(eArticulo *this, char *articulo);

int articulo_setMedida(eArticulo *this, char *medida);
int articulo_getMedida(eArticulo *this, char *medida);


int articulo_setPrecio(eArticulo *this, float precio);
int articulo_setPrecioTxt(eArticulo *this, char *precio);
int articulo_getPrecio(eArticulo *this, float *precio);


int articulo_setRubroId(eArticulo *this, int rubroId);
int articulo_setRubroIdTxt(eArticulo *this, char *rubroId);
int articulo_getRubroId(eArticulo *this, int *rubroId);

int articulo_print(eArticulo *this);

int articulo_compareByRubroId(void *elementA, void *elementB);
int articulo_compareByName(void *elementA, void *elementB);

void articulo_setFinalPrice(void* Element);




#endif // employee_H_INCLUDED
