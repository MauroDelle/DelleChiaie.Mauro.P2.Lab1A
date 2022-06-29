/*
 * peliculas.c
 *
 *  Created on: 29 jun. 2022
 *      Author: delle
 */

#include "peliculas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"

void eliminarPeli(eMovie* pelicula)
{
    free(pelicula);
}


int peliSetId(eMovie* pelicula, int id)
{
    int todoOk=0;

    if(pelicula != NULL && id>0)
    {
        pelicula->id_peli = id;

        todoOk=1;
    }
    return todoOk;
}

int peliSetTitulo(eMovie* pelicula, char* titulo)
{
    int todoOk=0;
    if(pelicula != NULL && titulo!=NULL)
    {
        if(strlen(titulo)<30 && strlen(titulo)>1)
        {
            strcpy(pelicula->titulo, titulo);
            todoOk=1;
        }
    }
    return todoOk;
}


int peliSetGenero(eMovie* pelicula, char* genero)
{
    int todoOk=0;
    if(pelicula != NULL && genero!=NULL)
    {
        if(strlen(genero)<30 && strlen(genero)>1)
        {
            strcpy(pelicula->genero, genero);
            todoOk=1;
        }
    }
    return todoOk;
}


int peliSetRating(eMovie* pelicula, float rating)
{
    int todoOk=0;
    if(pelicula != NULL && rating>=1 && rating<=10)
    {
    	pelicula->rating = rating;
    	todoOk=1;
    }
    return todoOk;
}

int peliGetId(eMovie* pelicula, int* pId)
{
    int todoOk=0;

    if(pelicula != NULL && pId != NULL)
    {
        *pId = pelicula->id_peli;

        todoOk=1;
    }
    return todoOk;
}

int peliGetTitulo(eMovie* pelicula, char* pTituloPeli)
{
    int todoOk=0;
    if(pelicula != NULL && pTituloPeli!=NULL)
    {
        strcpy(pTituloPeli, pelicula->titulo);
        todoOk=1;
    }
    return todoOk;
}


int peliGetGenero(eMovie* pelicula, char* pGeneroPeli)
{
    int todoOk=0;
    if(pelicula != NULL && pGeneroPeli!=NULL)
    {
        strcpy(pGeneroPeli, pelicula->genero);
        todoOk=1;
    }
    return todoOk;
}


int peliGetRating(eMovie* pelicula, float* pRating)
{
    int todoOk=0;

    if(pelicula != NULL && pRating != NULL)
    {
        *pRating = pelicula->rating;

        todoOk=1;
    }
    return todoOk;
}

void* calcularratingPeli(void* element)
{
	eMovie* nuevaPeliConRating=NULL;
	float rating;
	int maximo = 10;
	int minimo = 1;

	if(element!=NULL)
    {
		nuevaPeliConRating = (eMovie*) element;

        if(nuevaPeliConRating != NULL)
        {
            //"Formula": rand() % (maximo -  minimo + 1)  + minimo / max;

            //calculo el rating de la peli
        	rating = rand() % (maximo - minimo + 1)  + minimo / 10;

            //asigno los valores
            peliSetRating(nuevaPeliConRating, rating);
        }

    }
    return nuevaPeliConRating;
}

eMovie* new_PeliParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr)
{
    eMovie* nuevaPeli;

    nuevaPeli = new_Peli();

    if(nuevaPeli != NULL)
    {
        if(!(peliSetId(nuevaPeli, atoi(idStr))
        && peliSetTitulo(nuevaPeli, tituloStr)
        && peliSetGenero(nuevaPeli, generoStr)
        && peliSetRating(nuevaPeli, atoi(ratingStr))))
        {
        	eliminarPeli(nuevaPeli);
        	nuevaPeli = NULL;
        }
    }
    return nuevaPeli;
}


eMovie* new_Peli()
{
	eMovie* nuevaPeli=NULL;

    nuevaPeli = (eMovie*) malloc(sizeof (eMovie));

    if(nuevaPeli != NULL)
    {
        peliSetId(nuevaPeli, 0);
        peliSetTitulo(nuevaPeli, "-");
        peliSetGenero(nuevaPeli, "-");
        peliSetRating(nuevaPeli, 0);

    }
    return nuevaPeli;
}


void mostrarUnaPeli(eMovie* pelicula)
{
    int id;
    char titulo[30];
    char genero[30];
    float rating;

	if(pelicula != NULL )
	{
		peliGetId(pelicula, &id);
		peliGetTitulo(pelicula, titulo);
		peliGetGenero(pelicula, genero);
		peliGetRating(pelicula, &rating);

		printf(" %-10d %-30s %-30s %1f \n",id, titulo, genero, rating);
	}
}




int filtroPeliculasDrama(void* pElement)
{
    int retorno=0;
    char generoDrama[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoDrama);

        if(!strcmp(generoDrama, "Drama"))
        {
            retorno=1;
        }

    }

    return retorno;
}


int filtroPeliculasComedia(void* pElement)
{
    int retorno=0;
    char generoComedia[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoComedia);

        if(!strcmp(generoComedia, "Comedy"))
        {
            retorno=1;
        }

    }

    return retorno;
}



int filtroPeliculasTerror(void* pElement)
{
    int retorno=0;
    char generoHorror[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoHorror);

        if(!strcmp(generoHorror, "Terror"))
        {
            retorno=1;
        }

    }

    return retorno;
}


int filtroPeliculasAccion(void* pElement)
{
    int retorno=0;
    char generoAction[30];

    eMovie* auxPeli = NULL;

    if(pElement!=NULL)
    {
        auxPeli = (eMovie*) pElement;
        peliGetGenero(auxPeli, generoAction);

        if(!strcmp(generoAction, "Accion"))
        {
            retorno=1;
        }

    }

    return retorno;
}

/*
int pelis_compararPelis(void* peliUno, void* peliDos)
{
	int retorno=0;
	int ratingUno;
	int ratingDos;
	char auxNombreUno[30];
	char auxNombreDos[30];

	eMovie* primerPeli;
	eMovie* segundaPeli;

	primerPeli = (eMovie*) peliUno;
	segundaPeli = (eMovie*) peliDos;

	if(primerPeli != NULL && segundaPeli != NULL)
	{
		peliGetRating(primerPeli, &ratingUno);
		peliGetRating(segundaPeli, &ratingDos);
        peliGetGenero(primerPeli, auxNombreUno);
        peliGetGenero(segundaPeli, auxNombreDos);

		if(strcmp(auxNombreUno, auxNombreDos)<0)
		{
			retorno=1;
		}

	}
	return retorno;
}
*/
