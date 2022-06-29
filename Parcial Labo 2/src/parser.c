/*
 * parser.c
 *
 *  Created on: 28 jun. 2022
 *      Author: delle
 */


#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "peliculas.h"

int parser_PeliText(FILE* pFile, LinkedList* pArrayListaPelis)
{
    int todoOk=0;
    char id [10];
    char titulo[30];
    char genero[30];
    char rating[5];

	eMovie* peli = NULL;

	if(pFile!=NULL && pArrayListaPelis!=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, titulo, genero, rating);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]", id, titulo, genero, rating)==4)
			{
				peli=new_PeliParametros(id, titulo, genero, rating);

				if(peli!=NULL)
				{
					if(ll_add(pArrayListaPelis, peli)==-1)
					{
						eliminarPeli(peli);
						break;
					}
					else
					{
						todoOk=1;
					}
				}
			}
			else
			{
				break;
			}
		}
		while(!feof(pFile));
	}
	return todoOk;
}
