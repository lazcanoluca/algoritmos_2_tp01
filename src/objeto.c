#include "objeto.h"
#include "estructuras.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define DELIM ";"

struct objeto *objeto_crear_desde_string(const char *string)
{
	// char nombre[MAX_NOMBRE];
	// char descripcion[MAX_TEXTO];
	if (!string) return NULL;
	char es_asible[6];

	struct objeto *obj = (struct objeto *) malloc(sizeof( struct objeto ));

	int parametros_leidos = sscanf(string, "%[^;];%[^;];%[^\n]\n", obj->nombre, obj->descripcion, es_asible);

	if( parametros_leidos != 3 ) return NULL;

	obj->es_asible = !strcmp( es_asible, "true" ) ? true : false;
	
	// printf("\nOBJETO CREADO:\n");
	// printf("Nombre: %s \n", obj->nombre);
	// printf("Descripción: %s \n", obj->descripcion);
	// printf("Es accesible: %d \n", obj->es_asible);

	return obj;
}
