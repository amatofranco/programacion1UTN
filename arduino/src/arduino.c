/*
 ============================================================================
 Name        : arduino.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	return EXIT_SUCCESS;
}

void loop() {

	key = keypad.getKey();

	if (key != NO_KEY) {

		if (flagNum) {

			switch (key) {

			case 'A':

				save();

				break;

			case '#':
				reset();

				break;

			case '*':

				checkPassword();

				break;

			case 'B':

				resetPassword();

				break;

			}

		}

		else if (key == '#' || key == 'A' || key == 'B' || key == 'C'
				|| key == 'D') {

			showPassword[j] = key;
			j++;

		}

		Serial.println(showPassword);

		if (key >= '0' && key <= '9') {

			buffer = key - '0';

			flagNum = 1;

			lcd.print('*');

			switch (cont) {

			case 0:

				unidad = buffer;

				break;

			case 1:

				decena = unidad * 10;

				unidad = buffer;

				break;

			case 2:

				centena = decena * 10;

				decena = unidad * 10;

				unidad = buffer;

				break;

			case 3:

				millar = centena * 10;

				centena = decena * 10;

				decena = unidad * 10;

				unidad = buffer;

				break;

			}

			cont++;

			numero = unidad + decena + centena + millar;

		}

	}
}

