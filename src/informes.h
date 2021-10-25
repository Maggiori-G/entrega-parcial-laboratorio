/*
 * NEXO.H
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "clientes.h"
#include "funciones.h"
#include "pedidos.h"

int MostrarClientesConPedidosPendientes(Cliente* listaCliente, int len, Pedido* listaPedidos, int lenDos);
int MostrarPedidosPendientesConDatos(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos);
int MostrarPedidosCompletados(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos);
int MostrarPedidosPorLocalidad(Pedido* listaPedidos, int lendos, Cliente* listaCliente, int len, char buscadorLocalidad[]);
int Promedio(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos);
int ClienteConMasPedidosPendientes(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos);
int ClienteConMasPedidosCompletados(Cliente* listaCliente,int len, Pedido* listaPedidos, int lendos);
int ClienteConMayorCantidadDePedidos(Cliente* listaCliente, int len, Pedido* listaPedidos, int lendos);

#endif /* INFORMES_H_ */
