#include <stdio.h>
#include <stdlib.h>
​
/** \brief Mostrar Opción de Menú
 *
 * \return Devuelve la de opción seleccionada en el Menú
 *
 */
char menu();
​
/** \brief Mostrar mensaje de saludo
 *
 * \return 0 Funcionó correctamente / 1 No funcionó correctamente
 *
 */
int saludar();
​
/** \brief Mostrar mensaje de brindis
 *
 * \param bandera que verificar si se saludó previamente
 * \param flag de control de saludo previo
 * \return 0 Funcionó correctamente / 1 No funcionó correctamente
 *
 */
int brindar(int flagControlSaludar);
​
/** \brief Mostrar mensaje de despedida
 *
 * \param bandera que verifican si se saludó
 * \param bandera que verifican si se brindó
 * \return 0 Funcionó correctamente / 1 No funcionó correctamente
 *
 */
int despedirse(int flagControlSaludar, int flagControlBrindar);
