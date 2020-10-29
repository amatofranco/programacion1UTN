int reparacion_modificar(Reparacion *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char serie[MAX_SERIE];
	int idServicio;
	int fecha;
	int id;

	if (reparacion_emptyArray(array, length)) {

		printf("No se registra ninguna carga \n");
	}

	else if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", 0, 1000, 2) == 0) {

		reparacion_buscarId(array, QTY_REPARACIONES, id, &indice);

		if (indice != -1
				&& utn_getNumero(&opcion,
						"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar SERIE "
								"\n 2-Modificar IDSERVICIO "
								"\n 3-Modificar FECHA ",
								"Opción inválida \n", 1, 3, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getNombre(serie, "Ingrese Código de Serie \n",
						"Nombre Inválido \n", 2) == 0) {

					strncpy(array[indice].serie, serie, sizeof(serie));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getNumero(&idServicio,
						"Ingrese el nuevo idServicio \n ",
						"Número inválido \n", MIN_IDSERV, MAX_IDSERV, 2) == 0) {

					array[indice].idServicio = idServicio;

					ret = 0;

				}
				break;

				/*
			case 3:

				if (utn_getNumero(&fecha,
						"Ingrese FECHA \n ",
						"Número inválido \n", 0, 200000, 2) == 0) {

					array[indice].fecha = fecha;

					ret = 0;

				}
				break;
*/
			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}
	}

	return ret;
}


int servicio_modificar(Servicio *array, int length) {

	int ret = -1;
	int indice = -1;
	int opcion;
	char idError[] = "No existe el Id seleccionado \n";

	char descripcion[MAX_DESCRIPCION];
	float precio;
	int id;

	if (servicio_emptyArray(array, length)) {

		printf("No se registra ninguna carga \n");
	}

	else if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", 0, 1000, 2) == 0) {

		servicio_buscarId(array, QTY_SERVICIOS, id, &indice);

		if (indice != -1
				&& utn_getNumero(&opcion,
						"Ingrese el número correspondiente a la opción: "
								"\n 1-Modificar DESCRIPCION "
								"\n 2-Modificar PRECIO "
								,"Opción inválida \n", 1, 2, 2) == 0) {

			switch (opcion) {

			case 1:

				if (utn_getTexto(descripcion, "Ingrese DESCRIPCION \n",
						"Ingreso invalido \n", 1, MAX_DESCRIPCION, 2) == 0) {

					strncpy(array[indice].descripcion, descripcion, sizeof(descripcion));

					ret = 0;
				}

				break;

			case 2:

				if (utn_getFloat(&precio,
						"Ingrese PRECIO \n ",
						"Número inválido \n", 1, 200000, 2) == 0) {

					array[indice].precio = precio;

					ret = 0;

				}
				break;

			}
		}

		else if (indice == -1) {
			(printf("%s", idError));
		}
	}

	return ret;
}

/**
 * Pide una Pantalla del array a eliminar por id,
 * verifica que existe y pone la bandera Is Empty en 1
 * @param list puntero al array
 * @param len largo del array
 * @return
 */

int reparacion_baja(Reparacion *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_IDREPA, MAX_IDREPA, 2) == 0) {

		reparacion_buscarId(array, QTY_REPARACIONES, id, &indice);

		if (indice != -1
				&& utn_getNumero(&option, "Seleccione: 1 para borrar - "
						"2 para cancelar operación \n", "Opción inválida \n", 1,
						2, 2) == 0 && option == 1) {

			array[indice].isEmpty = 1;

			ret = 0;

		}

		else if (indice == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}


int servicio_baja(Servicio *array, int length) {

	int option = 2; // Cancelar

	int ret = -1;

	int id;

	int indice = -1;

	char cancel[] = "Se canceló la operación \n";

	char idError[] = "No existe el id seleccionado \n";

	if (array != NULL && length > 0
			&& utn_getNumero(&id, "Ingrese el Id a buscar \n",
					"Número inválido \n", MIN_IDSERV, MAX_IDSERV, 2) == 0) {

		servicio_buscarId(array, QTY_SERVICIOS, id, &indice);

		if (indice != -1
				&& utn_getNumero(&option, "Seleccione: 1 para borrar - "
						"2 para cancelar operación \n", "Opción inválida \n", 1,
						2, 2) == 0 && option == 1) {

			array[indice].isEmpty = 1;

			ret = 0;

		}

		else if (indice == -1) {
			printf("%s", idError);
		}

		else if (option != 1) {

			printf("%s", cancel);
		}

	}
	return ret;
}
/**
 * Ordena los elementos del array
 * @param array puntero a array
 * @param largo del array
 * @return 0 Éxito -1 Error
 *
 */
int reparacion_ordenar(Reparacion *array, int length) {

	int ret = -1;
	int orden;
	int flagSwap;
	Reparacion buffer;

	if (array != NULL && length > 0
			&& utn_getNumero(&orden,
					"Seleccione: 1 para Ordenamiento ascendete, "
							"2 para Ordenamiento desdente", "Opción no válida",
					1, 2, 2) == 0) {

		do {

			flagSwap = 0;

			for (int i = 0; i < length - 1; i++) {

				if (orden == 1) {

					if (strncmp(array[i].serie, array[i + 1].serie,
					MAX_NOMBRE) > 0
							|| (strncmp(array[i].serie, array[i + 1].serie,
							MAX_NOMBRE) == 0
									&& array[i].idServicio
											> array[i + 1].idServicio)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}

				else if (orden == 2) {

					if (strncmp(array[i].serie, array[i + 1].serie,
					MAX_NOMBRE) < 0
							|| (strncmp(array[i].serie, array[i + 1].serie,
							MAX_NOMBRE) == 0
									&& array[i].idServicio
											< array[i + 1].idServicio)) {

						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i + 1];
						array[i + 1] = buffer;
					}

				}
			}

			length--;

		} while (flagSwap == 1);

		ret = 0;

	}
	return ret;
}
