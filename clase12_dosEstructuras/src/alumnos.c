#include <stdio.h>
#include <stdlib.h>
#include "carreras.h"

int initCarrera(Pantalla *list, int len) {

	int ret = -1;
	if (list != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			list[i].isEmpty = 1;
		}
		ret = 0;
	}

	return ret;

}

