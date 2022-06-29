/*
 * controller.h
 *
 *  Created on: 28 jun. 2022
 *      Author: delle
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Menu.h"
#include "peliculas.h"
#include "Validaciones.h"
#include "Input.h"
#include "parser.h"

#endif /* CONTROLLER_H_ */



int controller_cargarArchivo(LinkedList* pArray);
int controller_listarPelis(LinkedList* pArrayListaPelis);
int controller_mapPeli(LinkedList* pArrayListaPelis);
int controller_guardarListaTexto(char* path, LinkedList* pArrayListaPelis);
int controller_filterPeliGenero(LinkedList* pArrayListaPelis);







