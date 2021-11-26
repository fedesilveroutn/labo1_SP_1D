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
			if ( feof (pFile) )
			{
				break;
			}
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

	if (pListaPerros != NULL)
	{
		len = ll_len(pListaPerros);
		printf("\n%-5s %-16s %-10s %-10s %-10s\n", "ID", "NOMBRE", "PESO", "EDAD", "RAZA");
		for (i = 0; i < len + 1; i++ )
		{
			auxPerro = (ePerro*) ll_get(pListaPerros, i);
			printf("\n%-5d %-16s %-10.2f %-10d %-10s", auxPerro->id, auxPerro->nombre, auxPerro->peso, auxPerro->edad, auxPerro->raza );
		}
		ret = 0;
	}

    return ret;
}










