/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "input.h"
#include "LinkedList.h"
#include "controller.h"



/* NOTA AL PROFESOR: El programa me funciona en CodeBlocks pero en Eclipse me esta dando problemas. No hay warnings ni errores,
 * pero simplemente no funciona, no me acordaba si uds aceptaba los trabajos en CB, asi que lo pase a Eclipse y ahora tengo este inconveniente;
 *
 *
 *
 *
 *
 *
 *		PUNTO 1: HECHO
 *		PUNTO 2: HECHO
 *		PUNTO 3: HECHO
 *		PUNTO 5: HECHO
 *		PUNTO 7: HECHO
 *
 *		PUNTO 4: NO HECHO
 *		PUNTO 6: NO HECHO
*/




int main(void) {

	setbuf(stdout,NULL);

	srand(time(NULL));

	char salir = 'n';
	char direc[40];

	LinkedList* listaDePelis  = ll_newLinkedList();

	do{

		switch(Menu())
		{
		case 1:

			controller_cargarArchivo(listaDePelis);

			break;
		case 2:

			controller_listarPelis(listaDePelis);

					break;
		case 3:

		    controller_mapPeli(listaDePelis);

					break;
		case 4:
					break;
		case 5:

			controller_filterPeliGenero(listaDePelis);

					break;
		case 6:
			break;
		case 7:

			printf("Nombre del archivo que quiere guardar\n");
			fflush(stdin);
			gets(direc);

			controller_guardarListaTexto(direc, listaDePelis);


					break;
		case 8:

			validarCaracter(&salir, "Esta seguro que desea salir? s/n?: ", "Respuesta invalida. 's' para salir. 'n' para cancelar la salida: ", 's', 'n');

			if(salir=='s')
			                {

			                   ll_deleteLinkedList(listaDePelis);
			                    printf("Salida exitosa!\n");
			                }
			                else
			                {
			                    printf("Se ha cancelado la salida\n");
			                }

					break;

		default:
			printf("Opcion Invalida!\n");
			break;


		}




	}while(salir == 'n');





	return EXIT_SUCCESS;
}
