/*
 * localidad.c
 *
 *  Created on: 25 oct. 2021
 *      Author: tanii
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "localidad.h"
#include "funciones.h"

Localidad CargarLocalidad(int idCliente)
{
	Localidad unaLocalidad;
	unaLocalidad.idCliente=idCliente;
	PedirCadena(unaLocalidad.localidad, "Ingrese la localidad: ", "ERROR, Reingrese la localidad");
	Pedir(unaLocalidad.direccion, "Ingrese la direccion de la empresa: ", 100);
	return unaLocalidad;
}
int CargarListaLocalidades(Localidad* listaLocalidad, int len, int idCliente)
{
	int retorno=0;
	for(int i=0;i<len;i++)
	{
		CargarLocalidad(idCliente);
	}
	return retorno;
}
