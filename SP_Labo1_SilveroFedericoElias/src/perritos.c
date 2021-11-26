#include "perritos.h"

ePerro* perro_new()
{
	ePerro* new = NULL;
	new = (ePerro*) malloc (sizeof(ePerro));
	return new;
}


ePerro* perro_newParam(char* id, char* nombre, char* peso, char* edad, char* raza)
{
	ePerro* new;

	new = perro_new();
	if(id != NULL && nombre != NULL && peso != NULL && edad != NULL && raza != NULL && new != NULL)
	{
		perro_setId(new, id);
		perro_setNombre(new, nombre);
		perro_setPeso(new, peso);
		perro_setRaza(new, raza);
		perro_setEdad(new, edad);
	}

	return new;
}



int perro_setId (ePerro* this, char* id)
{
	int ret = 1;
	int auxId;
	if(this != NULL && id != NULL)
	{
		auxId = atoi(id);
		this->id = auxId;
		ret = 0;
	}
	return ret;
}

int perro_setNombre(ePerro* this, char* nombre)
{
	int ret = 1;
	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int perro_setPeso (ePerro* this, char* peso)
{
	int ret = 1;
	float auxPeso;
	if(this != NULL && peso != NULL)
	{
		auxPeso = atof(peso);
		this->peso = auxPeso;
		ret = 0;
	}
	return ret;
}

int perro_setEdad (ePerro* this, char* edad)
{
	int ret = 1;
	int auxEdad;
	if(this != NULL && edad != NULL)
	{
		auxEdad = atoi(edad);
		this->edad = auxEdad;
		ret = 0;
	}
	return ret;
}

int perro_setRaza(ePerro* this, char* raza)
{
	int ret = 1;
	if(this != NULL && raza != NULL)
	{
		strcpy(this->raza, raza);
		ret = 0;
	}
	return ret;
}


int perro_setCantidadComida (ePerro* this, float racion)
{
	int ret = 1;
	if(this != NULL)
	{
		this->cantidadComidaRacion = racion;
		ret = 0;
	}
	return ret;
}








int perro_getId(ePerro* this)
{
	int id = -1;

	if(this != NULL)
	{
		id = this->id;
	}

	return id;
}

int perro_getNombre(ePerro* this, char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}

	return ret;
}


float perro_getPeso(ePerro* this)
{
	float peso = -1;
	if(this != NULL)
	{
		peso = this->peso;
	}

	return peso;
}





int perro_getEdad(ePerro* this)
{
	int edad = -1;
	if(this != NULL)
	{
		edad = this->edad;
	}

	return edad;
}





int perro_getRaza(ePerro* this, char* raza)
{
	int ret = -1;

	if(this != NULL && raza != NULL)
	{
		strcpy(raza, this->raza);
		ret = 0;
	}

	return ret;
}


float perro_getRacion(ePerro* this)
{
	float racion = -1;
	if(this != NULL)
	{
		racion = this->cantidadComidaRacion;
	}

	return racion;
}






/**
 *
 * @param pFile
 * @param pListaPerritos
 * @return 1 si hubo error, 0 si salio bien
 */
int perro_parser(FILE* pFile , LinkedList* pListaPerritos)
{
	char auxId[21];
	char auxNombre[21];
	char auxPeso[21];
	char auxEdad[21];
	char auxRaza[21];

	int ret = 1;
	int i = 0;


	if (pFile != NULL && pListaPerritos != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza);
		while ( !feof(pFile) )
		{
			fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxPeso, auxEdad, auxRaza);
			ePerro* auxPerro = perro_newParam(auxId, auxNombre, auxPeso, auxEdad, auxRaza);
			/*if ( feof (pFile) )
			{
				break;
			}*/
			ll_add(pListaPerritos, auxPerro, i);
			i++;
		}

		ret = 0;
	}

	return ret;
}


int perro_load(char* path , LinkedList* pListaPerros)
{
	FILE* pFile;
	int ret = 1;

	if( path != NULL && pListaPerros != NULL)
	{
		pFile = fopen (path, "r");
		if(pFile != NULL)
		{
			perro_parser(pFile, pListaPerros);
			ret = 0;
		}
	}

	fclose(pFile);
	return ret;
}


int perro_listar(LinkedList* pListaPerros)
{
	ePerro* auxPerro;
	int ret = 1;
	int len;
	int i;

	int auxId;
	int retNombre;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	int retRaza;
	char auxRaza[21];

	if (pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-10s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);

			auxId = perro_getId(auxPerro);
			retNombre = perro_getNombre(auxPerro, auxNombre);
			auxPeso = perro_getPeso(auxPerro);
			auxEdad = perro_getEdad(auxPerro);
			retRaza = perro_getRaza(auxPerro, auxRaza);

			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-10s", auxId, auxNombre, auxPeso, auxEdad, auxRaza );
			}
		}
		ret = 0;
	}

    return ret;
}



int perro_laQueMapea (void* this)
{
	int ret = 1;
	float cantidad;
	ePerro* auxPerro;

	auxPerro = this;

	if(this != NULL)
	{
		cantidad = auxPerro->peso * 23;
		perro_setCantidadComida(this, cantidad);
		ret = 0;
	}

	return ret;
}


int perro_listarConRacion(LinkedList* pListaPerros)
{
	ePerro* auxPerro;
	int ret = 1;
	int len;
	int i;

	int auxId;
	int retNombre;
	char auxNombre[21];
	float auxPeso;
	int auxEdad;
	int retRaza;
	char auxRaza[21];
	float auxRacion;

	if (pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-20s %-20s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA", "RACION");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);

			auxId = perro_getId(auxPerro);
			retNombre = perro_getNombre(auxPerro, auxNombre);
			auxPeso = perro_getPeso(auxPerro);
			auxEdad = perro_getEdad(auxPerro);
			retRaza = perro_getRaza(auxPerro, auxRaza);
			auxRacion = perro_getRacion(auxPerro);

			if(auxId != -1 && retNombre != -1 && auxPeso != -1 && auxEdad != -1 && retRaza != -1)
			{
				printf("\n%-5d %-16s %-10.2f %-10d %-20s %-20.2f", auxId, auxNombre, auxPeso, auxEdad, auxRaza, auxRacion );
			}
		}
		ret = 0;
	}

    return ret;
}



