#include "estructuras.h"
#include "interaccion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SCOLON ";"
#define COLON ":"

struct accion accion_crear_desde_string( const char *string )
{
	struct accion acc;
	char tipo;
	sscanf(string, "%c:%[^:]:%[^\n]\n", &tipo, acc.objeto, acc.mensaje);

	switch (tipo)
	{
		case 'd':
			acc.tipo = DESCUBRIR_OBJETO;
			break;
		case 'r':
			acc.tipo = REEMPLAZAR_OBJETO;
			break;
		case 'e':
			acc.tipo = ELIMINAR_OBJETO;
			break;
		case 'm':
			acc.tipo = MOSTRAR_MENSAJE;
			break;
		default:
			acc.tipo = ACCION_INVALIDA;
			break;
	};

	return acc;
}

struct interaccion *interaccion_crear_desde_string(const char *string)
{
	if (!string) return NULL;
	
	struct interaccion *inte = malloc(sizeof( struct interaccion ));

	char string_accion[1024];

	int parametros_leidos = sscanf(string, "%[^;];%[^;];%[^;];%[^\n]\n", inte->objeto, inte->verbo, inte->objeto_parametro, string_accion);
	
	if( parametros_leidos != 4 ) return NULL;

	inte->accion = accion_crear_desde_string(string_accion);
	
	printf("\nINTERACCION CREADA:\n");
	printf("Objeto: %s \n", inte->objeto);
	printf("Verbo: %s \n", inte->verbo);
	printf("Objeto parametro: %s \n", inte->objeto_parametro);
	printf("Accion: %s %i -> %s\n", inte->accion.objeto, inte->accion.tipo, inte->accion.mensaje);

	return inte;
}
