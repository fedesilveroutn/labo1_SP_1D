/*
 ============================================================================
 Name        : SP_Labo1_SilveroFedericoElias.c
 Author      : Federico Elías Silvero
 Version     : 1
 Copyright   : Your copyright notice
 Description : Segundo parcial Laboratorio 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "perritos.h"
#include "LinkedList.h"

int main(void) {
	setbuf(stdout, NULL);

	LinkedList* pListaPerros = ll_newLinkedList();

	//PARA LEER Y GUARDAR DINAMICAMENTE EN LINKEDLIST
	perro_load("src\\perritos.csv", pListaPerros);

	//PARA LISTAR
	perro_listar(pListaPerros);



	return 0;
}





