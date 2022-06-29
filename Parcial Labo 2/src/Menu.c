/*
 * Menu.c
 *
 *  Created on: 27 jun. 2022
 *      Author: delle
 */

#include "Menu.h"

int Menu(void)
{
	   int opcion;
	    system("cls");

	    printf("------------------------------------------------------------------------------------------------------------------------\n");
	    printf("                                    ***   Menu de opciones  ***             \n");
	    printf("------------------------------------------------------------------------------------------------------------------------\n");
	    printf("1- Cargar archivo\n");
	    printf("2- Imprimir lista\n");
	    printf("3- Asignar rating\n");
	    printf("4- Asignar Genero\n");
	    printf("5- Filtrar por Genero\n");
	    printf("6- Ordenar peliculas\n");
	    printf("7- Guardar Peliculas\n");
	    printf("8- Salir\n");

	    printf("Ingrese opcion: ");
	    fflush(stdin);
	    scanf("%d", &opcion);

	    return opcion;
}


int menuDos(void)
{
    int opcion;
    system("cls");

    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("                                    ***   Menu de opciones  ***             \n");
    printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("1- Filtrar por: Terror \n");
    printf("2- Filtrar por: Drama  \n");
    printf("3- Filtrar por: Acción  \n");
    printf("4- Filtrar por: Comedia  \n");
    printf("5- Salir\n");

    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;



}
