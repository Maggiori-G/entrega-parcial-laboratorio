/*
 * NEXO.C
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */


#include "informes.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>


/// @brief busca en ambos arrays (pedidos y clientes) y encuentra cuantos pedidos en estado pendiente tiene cada cliente y los imprime
///
/// @param listaCliente es el array de lista de cliente
/// @param len es el tamaño del array de clientes
/// @param listaPedidos es el array de lista de pedidos
/// @param lenDos es el tamaño del array de pedidos
/// @return retorna 0
int MostrarClientesConPedidosPendientes(Cliente* listaCliente, int len, Pedido* listaPedidos, int lenDos)
{
	int contadorClientesPendientes=0;
	int retorno=0;
	printf("\n\nID\tNombre\t\t\tCuit\t\tLocalidad\t\tDireccion\t\tCantidad de Pedidos Pendientes\n");
	for(int i=0;i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lenDos;j++)
			{
				if(listaCliente[i].id==listaPedidos[j].idCliente&&listaPedidos[j].estado==0)
				{
					contadorClientesPendientes++;
				}
			}
			printf("%-7i %-23s %-15s %-23s %-23s %i\n",listaCliente[i].id, listaCliente[i].nombre,listaCliente[i].cuit,listaCliente[i].localidad,listaCliente[i].direccion,contadorClientesPendientes);
			contadorClientesPendientes=0;
		}
	}
	return retorno;
}
/// @brief busca en ambos arrays por pedidos que esten con estado pendiente y que cliente es el que tiene esos pedidos en estado pendiente y los imprime
///
/// @param listaCliente es el array de lista de cliente
/// @param len es el tamaño del array de clientes
/// @param listaPedidos es el array de lista de pedidos
/// @param lenDos es el tamaño del array de pedidos
/// @return retorna 0 si no encontro nada y 1 si pudo encontrar algo y lo imprimio
int MostrarPedidosPendientesConDatos(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos)
{
	int retorno=0;
	printf("\n\nCUIT\t\tDIRECCION\t\tCantidad de kilos para procesar\n");
	for(int i=0;i<lendos;i++)
	{
		if(listaPedidos[i].estado==0&&listaPedidos[i].bandera==0)
		{
			for(int j=0;j<len;j++)
			{
				if(listaCliente[j].bandera==0&&listaPedidos[i].idCliente==listaCliente[j].id)
				{
					printf("%-15s %-23s %.2f\n",listaCliente[j].cuit, listaCliente[j].direccion, listaPedidos[i].cantidadKilos);
					retorno=1;
					break;
				}
			}
		}
	}
	return retorno;
}
/// @brief busca en ambos arrays por clientes que tengan pedidos en estado completado y los imprime
///
/// @param listaCliente es el array de lista de cliente
/// @param len es el tamaño del array de clientes
/// @param listaPedidos es el array de lista de pedidos
/// @param lenDos es el tamaño del array de pedidos
/// @return retorna 0 no encontro nada y 1 si encontro
int MostrarPedidosCompletados(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos)
{
	int retorno=0;
	printf("\nCUIT\t\tDIRECCION\t\tCANTIDAD HDPE RECICLADO    CANTIDAD LDPE RECICLADO    CANTIDAD PP RECICLADO\n");
	for(int i=0; i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lendos;j++)
			{
				if(listaPedidos[j].idCliente==listaCliente[i].id&&listaPedidos[j].estado==1&&listaPedidos[j].bandera==0)
				{
					printf("\n%-15s %-23s %-26.2f %-26.2f %.2f",listaCliente[i].cuit,listaCliente[i].direccion,listaPedidos[j].HDPE,listaPedidos[j].LDPE,listaPedidos[j].PP);
					retorno=1;
				}
			}
		}
	}
	return retorno;
}
/// @brief el usuario ingresa una localidad por string y se busca en ambas listas por pedidos pendientes en la localidad ingresada y si los encuentra los cuenta
/// y los imprime
/// @param listaCliente es el array de lista de cliente
/// @param len es el tamaño del array de clientes
/// @param listaPedidos es el array de lista de pedidos
/// @param lenDos es el tamaño del array de pedidos
/// @param buscadorLocalidad es ingresado por el usuario para buscar en la lista de clientes por coincidencias
/// @return retorna 0 si no hubo coincidencias y 1 si las hubo
int MostrarPedidosPorLocalidad(Pedido* listaPedidos, int lendos, Cliente* listaCliente, int len, char buscadorLocalidad[])
{
	int retorno=0;
	int contadorPedidosPorLocalidad=0;
	for(int i=0;i<lendos;i++)
	{
		if(listaPedidos[i].bandera==0&&listaPedidos[i].estado==0)
		{
			for(int j=0;j<len;j++)
			{
				if(strcmp(listaCliente[i].localidad,buscadorLocalidad)==0)
				{
					contadorPedidosPorLocalidad++;
					retorno=1;
					break;
				}
			}
		}
	}
	printf("\nEn la localidad %s hay %i pedido en estado pendiente\n",buscadorLocalidad,contadorPedidosPorLocalidad);
	return retorno;
}
/// @brief busca en ambos arrays por clientes que esten cargados, y tengan pedidos completados, si los encuentra acumula la cantidad de polipropileno y la cantidad
/// de pedidos que tenga ese cliente completados y hace el promedio de cantidad de kilos reciclados
/// @param listaCliente es el array de lista de cliente
/// @param len es el tamaño del array de clientes
/// @param listaPedidos es el array de lista de pedidos
/// @param lenDos es el tamaño del array de pedidos
/// @return retorna 0 si hubo algun problema y 1 si pudo calcular e imprimir el promedio
int Promedio(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos)
{
	int retorno=0;
	float acumuladorPP=0;
	int contadorDePedidos=0;
	float promedio;
	printf("\n\nCLIENTE\t\tPROMEDIO DE KILOS DE POLIPROPILENO\n");
	for(int i=0;i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lendos;j++)
			{
				if(listaCliente[i].id==listaPedidos[j].idCliente&&listaPedidos[j].estado==1)
				{
					contadorDePedidos++;
					acumuladorPP+=listaPedidos[j].PP;
				}
			}
			if(contadorDePedidos>0)
			{
				promedio=acumuladorPP/contadorDePedidos;
				retorno=1;
				printf("%-15s %.2f\n",listaCliente[i].nombre,promedio);
			}
			contadorDePedidos=0;
			acumuladorPP=0;
		}
	}
	return retorno;
}
int ClienteConMasPedidosPendientes(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos)
{
	int contadorPedidosPendiente=0;
	for(int i=0;i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lendos;j++)
			{
				if(listaCliente[i].id==listaPedidos[j].idCliente&&listaPedidos[j].estado==0)
				{
					contadorPedidosPendiente++;
					printf("El cliente %s es el que mas pedidos pendientes tiene con %i cantidad",listaCliente[i].nombre,contadorPedidosPendiente);
				}
			}
		}
		break;
	}

	return 0;
}
int ClienteConMasPedidosCompletados(Cliente* listaCliente,int len, Pedido* listaPedidos, int lendos)
{
	int contadorPedidosCompletados=0;
	for(int i=0;i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lendos;j++)
			{
				if(listaCliente[i].id==listaPedidos[j].idCliente&&listaPedidos[j].estado==1)
				{
					contadorPedidosCompletados++;
					printf("El cliente %s es el que mas pedidos completados tiene con %i cantidad",listaCliente[i].nombre,contadorPedidosCompletados);
				}
			}
		}
		break;
	}
	return 0;
}
int ClienteConMayorCantidadDePedidos(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos)
{
	int contadorClientesMasPedidos=0;
	for(int i=0;i<len;i++)
	{
		if(listaCliente[i].bandera==0)
		{
			for(int j=0;j<lendos;j++)
			{
				if(listaCliente[i].id==listaPedidos[j].idCliente&&(listaPedidos[j].estado==0||listaPedidos[j].estado==1))
				{
					contadorClientesMasPedidos++;
					printf("El cliente %s es el que mayor cantidad de pedidos tiene con %i cantidad",listaCliente[i].nombre,contadorClientesMasPedidos);
				}
			}
		}
		break;
	}
	return 0;
}















