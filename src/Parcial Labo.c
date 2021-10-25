/*
 ============================================================================
 Name        : Parcial 1 Laboratorio.c
 Author      : Maggiori, Gianni
 DNI         : 94.270.046
 Copyright   : Your copyright notice
 Description : Parcial numero 1 laboratorio, primera parte
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include "clientes.h"
#include "funciones.h"
#include "pedidos.h"
#include "informes.h"
#include "localidad.h"
#define TAM 100
#define TAM2 1000

int main(void)
{
	setbuf(stdout,NULL);
	int opcion;
	int contadorId=1;
	int idBorrar;
	int idBuscar;
	int confirmarBorrar;
	int contadorDeClientes=0;
	int contadorIdRecoleccion=1;
	int buscadorIdRecoleccion;
	char buscadorLocalidad[100];
	Cliente unCliente;
	Cliente listaClientes[TAM];
	Localidad unaLocalidad;
	Localidad listaLocalidad[TAM];
	Pedido unPedido;
	Pedido listaPedidos[TAM2];
	ClientesEnCero(listaClientes, TAM);
	PedidosEnCero(listaPedidos, TAM2);

	do
	{
		printf("\t\t=================================================\n");
		printf("\t\tADMINISTRACION DE RECOLECCION Y MANEJO DE BASURA:\n");
		printf("\t\t=================================================\n\n");
		printf("\t\t==========================================\n");
		printf("\t\tSELECCIONE UNA DE LAS SIGUIENTES OPCIONES:\n");
		printf("\t\t==========================================\n");
		printf("\n\n1-ALTA CLIENTE\n2-MODIFICAR DATOS CLIENTE\n3-BAJA CLIENTE\n4-GENERAR PEDIDO DE RECOLECCION\n5-PROCESAR RESIDUOS\n6-MOSTRAR CLIENTES\n7-MOSTRAR PEDIDOS PENDIENTES\n8-MOSTRAR PEDIDOS PROCESADOS\n9-MOSTRAR PEDIDOS PENDIENTES POR LOCALIDAD\n10-MOSTRAR CANT DE KILOS DE POLIPROPILENO RECICLADO POR CLIENTE (PROMEDIO)\n11-IMPRIMIR EL CLIENTE CON MAYOR CANTIDAD DE PEDIDOS PENDIENTES\n12-IMPRIMIR EL CLIENTE CON MAYOR CANTIDAD DE PEDIDOS COMPLETADOS\n13-IMPRIMIR EL CLIENTE CON MAS PEDIDOS\n14-SALIR");

		switch(opcion)
		{
			case 1:
				unCliente=CargarUnCliente();
				unaLocalidad=CargarLocalidad(contadorId);
				CargarListaLocalidades(listaLocalidad, TAM, contadorId);
				CargarClientes(listaClientes, TAM, contadorId, unCliente.nombre, unCliente.cuit, unaLocalidad.localidad, unaLocalidad.direccion);
				contadorId++;
				contadorDeClientes++;
				MostrarListaClientes(listaClientes, TAM);
			break;
			case 2:
				if(contadorDeClientes>0)
				{
					MostrarListaClientes(listaClientes, TAM);
					ModificarClientes(listaClientes, TAM);
				}
				else
				{
					printf("\n\nAun no se ingresaron clientes!\n");
				}
			break;
			case 3:
				if(contadorDeClientes>0)
				{
					MostrarListaClientes(listaClientes, TAM);
					idBorrar=PedirEntero("Ingrese el ID que desea borrar: ", "\nERROR\nReingrese el ID que desea borrar: ");
					confirmarBorrar=PedirOpcion("\nSi esta seguro que desea borrar ese ID ingrese 1, de lo contrario ingrese 2\n", 1, 2);
					if(confirmarBorrar==1)
					{
						BorrarCliente(listaClientes, TAM, idBorrar);
						contadorDeClientes--;
					}
				}
				else
				{
					printf("\n\nAun no se ingresaron clientes!");
				}
			break;
			case 4:
				if(contadorDeClientes>0)
				{
					MostrarListaClientes(listaClientes, TAM);
					idBuscar=PedirEntero("\nIngrese el ID que desea buscar: ", "\nERROR\n. Reingrese el ID que desea buscar: ");
					if(EncontrarClientePorId(listaClientes, TAM, idBuscar)!=-1)
					{
						unPedido=CargarUnPedido();
						CargarListaPedidos(listaPedidos, TAM2, contadorIdRecoleccion, unPedido.cantidadKilos, unPedido.estado, idBuscar);
						contadorIdRecoleccion++;
					}
					else
					{
						printf("\n\nNo se encontro el ID buscado, reintente\n");
					}
				}
				else
				{
					printf("\n\nAun no se ingreso ningun cliente!\n");
				}
			break;
			case 5:
				if(contadorIdRecoleccion>0)
				{
					MostrarListaPedidos(listaPedidos, TAM2);
					buscadorIdRecoleccion=PedirEntero("\nSeleccione el ID del pedido: ", "\nERROR\n");
					if(EncontrarPedidoPorId(listaPedidos, TAM2, buscadorIdRecoleccion)!=-1)
					{
						ProcesarPlastico(listaPedidos, TAM2, buscadorIdRecoleccion);
					}
				}
				else
				{
					printf("\nNo se ingreso ningun pedido aun\n");
				}
			break;
			case 6:
				if(contadorDeClientes>0)
				{
					MostrarClientesConPedidosPendientes(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nNo se encontraron clientes ingresados!\n");
				}
			break;
			case 7:
				if(contadorDeClientes>0)
				{
					MostrarPedidosPendientesConDatos(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!\n");
				}
			break;
			case 8:
				if(contadorDeClientes>0)
				{
					MostrarPedidosCompletados(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
			break;
			case 9:
				if(contadorDeClientes>0)
				{
					MostrarListaPedidos(listaPedidos, TAM2);
					PedirCadena(buscadorLocalidad, "\nIngrese la localidad que quiere buscar: ", "\nERROR\n Reingrese la localidad: ");
					MostrarPedidosPorLocalidad(listaPedidos, TAM2, listaClientes, TAM, buscadorLocalidad);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
			break;
			case 10:
				if(contadorDeClientes>0)
				{
					Promedio(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
			break;
			case 11:
				if(contadorDeClientes>0)
				{
					ClienteConMasPedidosPendientes(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
				break;
			case 12:
				if(contadorDeClientes>0)
				{
					ClienteConMasPedidosCompletados(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
				break;
			case 13:
				if(contadorDeClientes>0)
				{
					ClienteConMayorCantidadDePedidos(listaClientes, TAM, listaPedidos, TAM2);
				}
				else
				{
					printf("\nAun no se ingreso ningun cliente!");
				}
				break;
		}
		opcion=PedirOpcion("\n\nQue accion desea realizar?\n", 1, 14);
	}while(opcion!=14);
	return EXIT_SUCCESS;
}
