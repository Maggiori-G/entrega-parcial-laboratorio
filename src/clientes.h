/*
 * CLIENTES.H
 *
 *  Created on: 22 oct. 2021
 *      Author: tanii
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct
{
	int id;
	char nombre[100];
	char cuit[15];
	char localidad[100];
	char direccion[100];
	int bandera;
}Cliente;
int ClientesEnCero(Cliente* lista, int len);
Cliente CargarUnCliente();
int CargarClientes(Cliente* lista, int len, int id, char nombre[], char cuit[], char localidad[], char direccion[]);
int MostrarCliente(Cliente lista);
int MostrarListaClientes(Cliente* lista, int len);
int ModificarClientes(Cliente* lista, int len);
int EncontrarClientePorId(Cliente* lista, int len, int id);
int BorrarCliente(Cliente* lista, int len, int id);

#endif /* CLIENTES_H_ */
