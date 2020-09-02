#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int num;
	int cont = 0;
	
	
	printf("Ingrese número 1 \n");
	
	scanf ("%d", &num);
	
	for (int i = 0; i<num; i++){
		
		if (num%i == 0){
		
		cont++;
		
		printf("Divisor: %d", num);
	}
	
		printf("Cantidad de divisores: %d",cont);
	
	
	
	return 0;
}