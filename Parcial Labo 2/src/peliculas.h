/*
 * peliculas.h
 *
 *  Created on: 29 jun. 2022
 *      Author: delle
 */

#ifndef PELICULAS_H_
#define PELICULAS_H_


typedef struct
{
    int id_peli;
    char titulo[30];
    char genero[30];
    float rating;

}eMovie;


#endif /* PELICULAS_H_ */


eMovie* new_PeliParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);
eMovie* new_Peli();

void eliminarPeli(eMovie* pelicula);

//SETTERS
int peliSetId(eMovie* pelicula, int id);
int peliSetTitulo(eMovie* pelicula, char* titulo);
int peliSetGenero(eMovie* pelicula, char* genero);
int peliSetRating(eMovie* pelicula, float rating);

//GETTERS
int peliGetId(eMovie* pelicula, int* pId);
int peliGetTitulo(eMovie* pelicula, char* pTituloPeli);
int peliGetGenero(eMovie* pelicula, char* pGeneroPeli);
int peliGetRating(eMovie* pelicula, float* pRating);

void* calcularratingPeli(void* element);

//FILTERS
int filtroPeliculasDrama(void* pElement);
int filtroPeliculasComedia(void* pElement);
int filtroPeliculasTerror(void* pElement);
int filtroPeliculasAccion(void* pElement);


void mostrarUnaPeli(eMovie* pelicula);




