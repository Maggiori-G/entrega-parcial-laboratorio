/*
 * funciones.h
 *
 *  Created on: 19 oct. 2021
 *      Author: tanii
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int PedirOpcion(char mensaje[], int min, int max);
int PedirEntero(char mensaje[], char mensajeError[]);
float PedirFlotante(char mensaje[], char mensajeError[]);
int PedirCadena(char cadena[], char mensaje[], char mensajeError[]);
int Pedir(char cadena[], char mensaje[], int tam);



#endif /* FUNCIONES_H_ */
