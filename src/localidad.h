/*
 * localidad.h
 *
 *  Created on: 25 oct. 2021
 *      Author: tanii
 */

#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include "funciones.h"
typedef struct
{
	int idCliente;
	char localidad[100];
	char direccion[100];
}Localidad;

Localidad CargarLocalidad(int idCliente);
int CargarListaLocalidades(Localidad* listaLocalidad, int len, int idCliente);

#endif /* LOCALIDAD_H_ */
