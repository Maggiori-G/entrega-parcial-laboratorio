/*
 * CLIENTES.C
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "clientes.h"
#include "funciones.h"
#include "localidad.h"

/// @brief Esta funcion coloca la posicion "bandera" del array de clientes en 1 para indicar que estan vacias
///
/// @param lista Es el puntero del array de lista de clientes
/// @param len es el tamaño del array
/// @return retorna -1 si hubo algun error, y 0 si pudo poner todas las posiciones de bandera en 1
int ClientesEnCero(Cliente* lista, int len)
{
	int retorno=-1;
	if(lista!=NULL||(len>0&&len<100))
	{
		for(int i=0;i<len;i++)
		{
			lista[i].bandera=1;
		}
		retorno=0;
	}
	return retorno;
}
/// @brief La funcion no recibe nada, genera un cliente solo con los datos que el usuario ingresa y los devuelve
///
/// @return retorna 1 cliente solo para cargar el array de lista de clientes
Cliente CargarUnCliente()
{
	Cliente unCliente;
	PedirCadena(unCliente.nombre, "\n\nIngrese el nombre de la empresa: ", "\nError, Reingrese el nombre de la empresa: ");
	Pedir(unCliente.cuit, "Ingrese el cuit de la empresa: ", 15);
	return unCliente;
}
/// @brief Esta funcion carga el array de lista de clientes
///
/// @param lista Es el array de lista de clientes
/// @param len Es el tamaño del array lista clientes
/// @param id Id del cliente
/// @param nombre Nombre del cliente
/// @param cuit Cuit del cliente
/// @param localidad Localidad del cliente
/// @param direccion Direccion del cliente
/// @return Retorna -1 si hubo algun problema y no se pudo cargar el array, sino retorna 0
int CargarClientes(Cliente* lista, int len, int id, char nombre[], char cuit[], char localidad[], char direccion[])
{
	int retorno=-1;

	for(int i=0;i<len;i++)
	{
		if(lista[i].bandera==1)
		{
			lista[i].id=id;
			strcpy(lista[i].nombre,nombre);
			strcpy(lista[i].cuit,cuit);
			//strcpy(lista[i].localidad,localidad);
			//strcpy(lista[i].direccion,direccion);
			lista[i].bandera=0;
			break;
		}
		retorno=0;
	}

	return retorno;
}
/// @brief Imprime por pantalla 1 cliente para despues usarlo en un for
///
/// @param unCliente Recibe la estructura de 1 cliente para imprimir por pantalla
/// @return Retorna 0
int MostrarCliente(Cliente unCliente)
{
	int retorno=0;
	printf("%i\t %-25s %-20s %-23s %s\n",unCliente.id, unCliente.nombre, unCliente.cuit, unCliente.localidad, unCliente.direccion);
	return retorno;
}
/// @brief Recorre el array lista de clientes en busca de clientes cargados (que tengan la bandera en 0) y llama a la funcion MostrarCliente en la posicion de i para mostrar la lista entera
///
/// @param lista Es el array de lista de clientes
/// @param len Es el tamaño del array lista clientes
/// @return retorna 1 si hubo algun problema, y 0 si pudo imprimir algo
int MostrarListaClientes(Cliente* lista, int len)
{
	int retorno=1;
	printf("\nID\t NOMBRE\t\t\t   CUIT\t\t\tLOCALIDAD\t\tDIRECCION\n");
	for(int i=0;i<len;i++)
	{
		if(lista[i].bandera==0)
		{
			MostrarCliente(lista[i]);
			retorno=0;
		}
	}
	return retorno;
}
/// @brief Busca en la lista de clientes un id especifico
///
/// @param lista es el array lista de clientes
/// @param len es el tamaño del array lista clientes
/// @param id es el id que el usuario quiere buscar
/// @return retorna -1 si no lo encontro, y retorna la posicion de i si hubo match del id que se busca y algun id de la lista
int EncontrarClientePorId(Cliente* lista, int len, int id)
{
	int i;
	int retorno=-1;
	for(i=0;i<len;i++)
	{
		if(lista[i].bandera==0&&lista[i].id==id)
		{
			retorno=i;
		}
	}
	return retorno;
}
/// @brief Modifica Clientes dentro del array lista clientes
///
/// @param lista es el array de la lista de clientes
/// @param len es el tamaño del array lista clientes
/// @return Retorna 1
int ModificarClientes(Cliente* lista, int len)
{
	int retorno=1;
	char cadena[100];
	int opcion;
	int buscadorDeId;
	int posicion;
	buscadorDeId=PedirEntero("Ingrese el ID que desea buscar: \n", "ERROR\n Reingrese el ID que desea buscar: ");
	posicion=EncontrarClientePorId(lista, len, buscadorDeId);
	do
	{
		opcion=PedirOpcion("Ingrese el campo que desea modificar.\n1-Modificar direccion\n2-Modificar localidad\n", 1, 3);
		switch(opcion)
		{
			case 1:
				Pedir(cadena, "Ingrese la direccion a modificar: \n", len);
				strcpy(lista[posicion].direccion,cadena);
			break;
			case 2:
				Pedir(cadena, "Ingrese la localidad a modificar: \n", len);
				strcpy(lista[posicion].localidad,cadena);
			break;

		}

	}while(opcion!=3);
	return retorno;
}
/// @brief Encuentra y "borra" un cliente de la lista (lo que hace es cambiar la bandera de 0 que es cargado a 1 que es vacio
///
/// @param lista Es el array lista de clientes
/// @param len es el tamaño del array lista clientes
/// @param id es el id que el usuario quiere borrar
/// @return retorna 0 si no pudo borrarlo, y 1 si pudo borrarlo
int BorrarCliente(Cliente* lista, int len, int id)
{
	int retorno=0;
	for(int i=0;i<len;i++)
	{
		if(lista[i].id==id&&lista[i].bandera==0)
		{
			lista[i].bandera=1;
			retorno=1;
			break;
		}
	}
	return retorno;
}
