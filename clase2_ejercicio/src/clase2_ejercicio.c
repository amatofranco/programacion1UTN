/*

 1)De 5  personas que ingresan al hospital se deben tomar y
 validar los siguientes datos.
 la inicial , temperatura, sexo y edad.
 a)informar la cantidad de personas de cada sexo.
 b)la edad promedio en total
 c)la mujer con más temperatura(si la hay)
 pedir datos y mostrar los resultados
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	char inicial;
	int temperatura;
	char sexo;
	int edad;
	int contadorF = 0;
	int contadorM = 0;
	int acumuladorEdad = 0;
	float promedio;
	char mayorTemperatura;
	int flagMaximo = 0;

	for (int i = 0; i < 5; i++) {

		do{

		printf("Ingrese inicial \n");

		fpurge(stdin);

		scanf("%c", &inicial);

		}
		while (! isalpha(inicial));

		do {
			printf("Ingrese temperatura \n");
			fpurge(stdin);
			scanf("%d", &temperatura);
		}
		while (!(temperatura >= 25 && temperatura <= 45));

		do {

			printf("Ingrese sexo \n");

			fpurge(stdin);

			scanf("%c", &sexo);
		}

		while (!(sexo == 'm' || sexo == 'f'));

		do {
			printf("Ingrese edad \n");

			fpurge(stdin);

			scanf("%d", &edad);
		}
		while (!(edad > 0 && edad < 110));

		if (sexo == 'f') {
			contadorF++;
			if (flagMaximo == 0 || temperatura > mayorTemperatura) {
				mayorTemperatura = inicial;
				flagMaximo = 1;
			}

		} else {
			contadorM++;
		}

		acumuladorEdad += edad;
	}

	promedio = acumuladorEdad / 5;

	printf("Cantidad de personas sexo m: %d \n", contadorM);
	printf("Cantidad de personas sexo f: %d \n", contadorF);
	printf("Edad promedio: %.2f \n", promedio);

	if(contadorF !=0){
		printf("Mujer con mayor temperatura: %c", mayorTemperatura);
	}
	else {
		printf("No se registraron mujeres");
	}



}
