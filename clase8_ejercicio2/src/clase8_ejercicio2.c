/*
 ============================================================================
MANEJO DE STRINGS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> //Biblioteca para manejo de strings

int main(void) {

	char nombre [11]="Juan"; // 10 caracteres + FINAL DEL STRING (\0)

	strcpy(nombre, "Pepe"); // forma de copiar string (No se puede hacer nombre = "pepe". Una vez que inicializamos el string ya esta

	char auxiliar[11];

	strcpy(auxiliar,nombre); //STRCPY no es segura porque no nos dice nada sobre el limite del string (Desborde de memoria)

	strncpy(auxiliar,nombre,sizeof(auxiliar)); // STRNCPY es la segura porque recibe como parametro el tamaño del string
												// SIZE OF dice la cantidad de bites de la variable (en el caso de char cada uno es un byte)
												// por lo que cuenta tambien el caracter final del string



	printf("%d",strnlen(nombre,sizeof(nombre))); //STRNLEN dice el tamaño "real" del string mas alla del espacio en memoria (se pasa como parametro el espacio total)
												// La version "insegura" (STRLEN) necesita de un /0 para entender el final de la cadena. Por eso en STRNLEN se le pasa el tamaño tota

	strncat(nombre, " Pe",sizeof(nombre));      // Concatenar Strings en C (No existe "Hola" + " Pepe")


	printf("%s",nombre);

	sprintf(nombre, "Cacho"); // Otra forma de modificar string, nos pide el array por parametro y le cambiamos el texto por lo que queramos

	printf("%s",nombre);

	return EXIT_SUCCESS;
}
