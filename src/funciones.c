/*
 * funciones.c
 *
 *  Created on: 19 oct. 2021
 *      Author: tanii
 */
#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
/// @brief Pide un numero y lo valida entre un minimo y un maximo
///
/// @param Parametrizado en un mensaje de que o para que es el numero
/// @param min numero minimo de validacion
/// @param max numero maximo de validacion
/// @return es el numero validado
int PedirOpcion(char mensaje[], int min, int max)
{
	int opcion;
	printf(mensaje);
	fflush(stdin);
	scanf("%i",&opcion);
	while(opcion<min||opcion>max)
	{
		printf("ERROR\n");
		printf(mensaje);
		fflush(stdin);
		scanf("%i",&opcion);
	}
	return opcion;
}
/// @brief Pide un numero entero y valida que sea un numero entero
///
/// @param mensaje Parametrizado un mensaje para que se imprima cuando se pide el numero
/// @param mensajeError Parametrizado el mensaje de error si no cumple la validacion
/// @return es el numero entero validado
int PedirEntero(char mensaje[], char mensajeError[])
{
	char numero[1000];
	int entero;
	int largo;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((i==0&&numero[i]=='-')||(isdigit(numero[i])==1))
			{
				resultado=1;
			}
			else
			{
				resultado=0;
				printf(mensajeError);
				break;
			}
		}
	}while(resultado==0);
	entero=atoi(numero);
	return entero;
}
/// @brief Pide un numero flotante y valida que sea un numero flotante y no otra cosa como simbolos etc
///
/// @param mensaje Parametrizado un mensaje para que se imprima cuando se pide el numero
/// @param mensajeError Parametrizado el mensaje de error si no cumple la validacion
/// @return Es el numero flotante
float PedirFlotante(char mensaje[], char mensajeError[])
{
	char numero[10000];
	int largo;
	int contadorDePuntos=0;
	float flotante;
	int resultado;
	int i;
	do
	{
		printf(mensaje);
		fflush(stdin);
		gets(numero);
		largo=strlen(numero);
		for(i=0;i<largo;i++)
		{
			if((isdigit(numero[i])==1)||(i==0&&numero[i]=='-')||(i!=0&&numero[i]=='.'))
			{
				resultado=1;
				if(numero[i]=='.')
				{
					contadorDePuntos++;
					if(contadorDePuntos>1)
					{
						resultado=0;
						break;
					}
				}
			}
			else
			{
				resultado=0;
				printf(mensajeError);
				break;
			}
		}
	}while(resultado==0);
	flotante=atof(numero);
	return flotante;
}
/// @brief Pide una cadena de caracteres y valida que no sean digitos
///
/// @param cadena Es la el texto que va a ingresar el usuario
/// @param mensaje Parametrizado el mensaje de para que es la cadena que se pide
/// @param mensajeError Parametrizado un mensaje de error por si el usuario ingresa numeros
/// @return retorna 1 si esta ok sino retorna 0
int PedirCadena(char cadena[], char mensaje[], char mensajeError[])
{
	int retorno=0;
	int largo;
	int bandera=0;
	do
	{
		if(bandera==1)
		{
			printf(mensajeError);
		}
		else
		{
			printf(mensaje);
		}
		fflush(stdin);
		gets(cadena);
		largo=strlen(cadena);
		for(int i=0;i<largo;i++)
		{
			if(isdigit(cadena[i])==1&&cadena[i]!=32)
			{
				bandera=1;
				break;
			}
			else
			{
				bandera=0;
			}
		}
	}while(bandera==1);
	retorno=1;
	return retorno;
}
/// @brief Pide al usuario el ingreso de una cadena de texto pero permite que ingrese lo que quiera y lo saca por "cadena"
///
/// @param cadena es la devolucion del texto ingresado
/// @param mensaje Parametrizado el mensaje para pedir
/// @param tam es el tamaño
/// @return retorna 0
int Pedir(char cadena[], char mensaje[],int tam)
{
	printf(mensaje);
	fflush(stdin);
	fgets(cadena,tam,stdin);
	cadena[strlen(cadena)-1]='\0';

	return 0;
}























