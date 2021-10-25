/*
 * PEDIDOS.C
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */
#include "pedidos.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "funciones.h"
/// @brief pone todas "banderas" del array lista de pedidos en 1 para indicar que el espacio esta vacio
///
/// @param lista es el array lista de pedidos
/// @param len es el tamaño de la lista de pedidos
/// @return retorna -1 si hubo algun problema y 0 si pudo cambiar todas las banderas
int PedidosEnCero(Pedido* lista, int len)
{
	int retorno=-1;
	if(lista!=NULL||(len>0&&len<1000))
	{
		for(int i=0;i<len;i++)
		{
			lista[i].bandera=1;
		}
		retorno=0;
	}
	return retorno;
}
/// @brief Carga 1 pedido con los datos que el usuario puede ingresar y pone el estado en pendiente
///
/// @return retorna un dato unPedido
Pedido CargarUnPedido()
{
	Pedido unPedido;
	unPedido.cantidadKilos=PedirFlotante("\nIngrese la cantidad de kilos de plastico para procesar: ", "\nERROR.\n Reingrese la cantidad de kilos de plastico para procesar: ");
	unPedido.estado=pendiente;
	return unPedido;
}
/// @brief carga el array lista de pedidos si la bandera esta en 1
///
/// @param lista es el array de lista de pedidos
/// @param len es el tamaño de la lista de pedidos
/// @param id es el id del pedido
/// @param cantidadKilos es la cantidad de kilos para recolectar
/// @param estado es el estado del pedido
/// @param idCliente es que cliente solicito el pedido
/// @return retorna 1 o 0
int CargarListaPedidos(Pedido* lista, int len, int id, float cantidadKilos, int estado, int idCliente)
{
	int retorno=1;
	for(int i=0;i<len;i++)
	{
		if(lista[i].bandera==1)
		{
			lista[i].id=id;
			lista[i].cantidadKilos=cantidadKilos;
			lista[i].idCliente=idCliente;
			lista[i].estado=estado;
			lista[i].bandera=0;
			break;
			retorno=0;
		}
	}
	return retorno;
}
/// @brief printea un pedido solo
///
/// @param unPedido recibe 1 pedido solo
/// @return retorna 0
int MostrarUnPedido(Pedido unPedido)
{
	int retorno=0;
	printf("%-7i %-7i %-23.2f %i\n",unPedido.id, unPedido.estado, unPedido.cantidadKilos, unPedido.idCliente);
	return retorno;
}
/// @brief recibe la lista de pedidos, el tamaño y llama a "MostrarUnPedido" dentro del for para mostrar la lista entera solo de las posiciones
/// que estan con bandera en 0 que significa pedido cargado
/// @param lista es el array lista de pedidos
/// @param len es el tamaño lista de pedidos
/// @return retorna 0
int MostrarListaPedidos(Pedido* lista, int len)
{
	int retorno=0;
	printf("\n\nID\tESTADO\tKILOS DE PLASTICO\tID DEL CLIENTE\n");
	for(int i=0;i<len;i++)
	{
		if(lista[i].bandera==0)
		{
			MostrarUnPedido(lista[i]);
		}
	}
	return retorno;
}
/// @brief ingresa un id indicado por el usuario y recorre el array de lista de pedidos en busca de ese id
///
/// @param lista es el array de lista de pedidos
/// @param len es el tamaño del array lista de pedidos
/// @param id es el id que va a buscar
/// @return retorna -1 si no lo encontro, y retorna la posicion de i si lo encontro
int EncontrarPedidoPorId(Pedido* lista, int len, int id)
{
	int retorno=-1;
	for(int i=0;i<len;i++)
	{
		if(lista[i].bandera==0&&lista[i].id==id)
		{
			retorno=i;
		}
	}
	return retorno;
}
/// @brief recorre el array lista de pedidos en busca de un id ingresado por el usuario y si lo encuentra procesa los kilos de plastico del pedido en los 3 tipos
/// diferentes de plastico posible
/// @param lista es el array lista de pedidos
/// @param len es el tamaño del array lista de pedidos
/// @param idPedido es el id que ingreso el usuario
/// @return retorna 0
int ProcesarPlastico(Pedido* lista, int len, int idPedido)
{
	int retorno=0;
	int bandera=0;
	float kilosReciclados;
	for(int i=0;i<len;i++)
	{
		if(lista[i].id==idPedido)
		{
			do
			{
				lista[i].HDPE=PedirFlotante("\nCuantos kilos de HDPE se reciclaron?: ", "\nERROR\n Reingrese la cantidad de kilos de HDPE reciclados: ");
				lista[i].LDPE=PedirFlotante("\nCuantos kilos de LDPE se reciclaron?: ", "\nERROR\n Reingrese la cantidad de kilos de LDPE reciclados: ");
				lista[i].PP=PedirFlotante("\nCuantos kilos de PP se reciclaron?: ", "\nERROR\n Reingrese la cantidad de kilos de PP reciclados: ");
				kilosReciclados=lista[i].HDPE+lista[i].LDPE+lista[i].PP;
				lista[i].estado=completado;
				if(kilosReciclados>lista[i].cantidadKilos)
				{
					printf("\nLa cantidad de kilos reciclados supera los kilos ingresados en el pedido, por favor reingrese");
				}
				else
				{
					bandera=1;
					break;
				}
			}while(bandera==0);
		}
	}
	return retorno;
}






















