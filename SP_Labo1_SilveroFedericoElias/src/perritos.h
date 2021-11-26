
#ifndef PERRITOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define PERRITOS_H_

typedef struct
{
	int id;
	char nombre[21];
	float peso;
	int edad;
	char raza[21];

}ePerro;


//CONSTRUCTORES
ePerro* perro_new();
ePerro* perro_newParam(char* id, char* nombre, char* peso, char* edad, char* raza);

//SETTER
int perro_setId (ePerro* this, char* id);
int perro_setNombre(ePerro* this, char* nombre);
int perro_setPeso (ePerro* this, char* peso);
int perro_setEdad (ePerro* this, char* edad);
int perro_setRaza(ePerro* this, char* raza);

//PARSER
int perro_parser(FILE* pFile , LinkedList* pListaPerritos);

//LEER Y GUARDAR EN LINKEDLIST
int perro_load(char* path , LinkedList* pListaPerros);


//LISTAR PERROS
int perro_listar(LinkedList* pListaPerros);


#endif /* PERRITOS_H_ */
