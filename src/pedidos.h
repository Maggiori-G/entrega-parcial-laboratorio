/*
 * PEDIDOS.H
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */

#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include "funciones.h"
#define pendiente 0
#define completado 1
typedef struct
{
	int id;
	int bandera;
	int estado;
	float cantidadKilos;
	int idCliente;
	float HDPE;
	float LDPE;
	float PP;

}Pedido;
int PedidosEnCero(Pedido* lista, int len);
Pedido CargarUnPedido();
int CargarListaPedidos(Pedido* lista, int len, int id, float cantidadKilos, int estado, int idCliente);
int MostrarUnPedido(Pedido lista);
int MostrarListaPedidos(Pedido* lista, int len);
int EncontrarPedidoPorId(Pedido* lista, int len, int id);
int ProcesarPlastico(Pedido* lista, int len, int idPedido);

#endif /* PEDIDOS_H_ */
