#include "estructuras.h"
#include "sala.h"
#include "objeto.h"
#include "interaccion.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINEA 1024

sala_t *sala_crear_desde_archivos(const char *objetos, const char *interacciones)
{
	FILE *archivo_objetos, *archivo_interacciones;
	char linea[MAX_LINEA];

	archivo_objetos = fopen( objetos, "r" );
	if (archivo_objetos == NULL) return NULL;
	archivo_interacciones = fopen( interacciones, "r");
	if (archivo_interacciones == NULL) return NULL;

	sala_t *sala = malloc(sizeof(sala_t));

	if (sala == NULL){
		free(sala);
		return NULL;
	}

	int tamanio = 0;
	struct objeto **bloque_objeto = NULL;

	//printf("Objetos...\n");

	// carga el vector objetos
	while( fgets( linea, MAX_LINEA, archivo_objetos ) != NULL )
	{
		if (tamanio == 0)
			bloque_objeto = malloc(sizeof(struct objeto *));
		else
			bloque_objeto = realloc(bloque_objeto, (unsigned)(tamanio+1) * sizeof(struct objeto*));

		if (bloque_objeto == NULL){
			free(bloque_objeto);
			return NULL;
		}

		bloque_objeto[tamanio] = objeto_crear_desde_string(linea);
		// printf("%i: %s\n", tamanio, bloque_objeto[tamanio]->nombre);
		tamanio++;
	}
	sala->objetos = bloque_objeto;
	sala->cantidad_objetos = tamanio;

	tamanio = 0;
	struct interaccion **bloque_interaccion = NULL;

	// printf("Interacciones...\n");

	while( fgets( linea, MAX_LINEA, archivo_interacciones ) != NULL )
	{
		if (tamanio == 0)
			bloque_interaccion = malloc(sizeof(struct interaccion *));
		else
			bloque_interaccion = realloc(bloque_interaccion, (unsigned)(tamanio+1) * sizeof(struct interaccion*));

		if (bloque_interaccion == NULL){
			free(bloque_interaccion);
			return NULL;
		}

		bloque_interaccion[tamanio] = interaccion_crear_desde_string(linea);
		//printf("%i: %s\n", tamanio, bloque_interaccion[tamanio]->nombre);
		tamanio++;
	}
	sala->interacciones = bloque_interaccion;
	sala->cantidad_interacciones = tamanio;


	fclose( archivo_objetos );
	fclose( archivo_interacciones );

	if (tamanio == 0) return NULL;

	return sala;
}

char **sala_obtener_nombre_objetos(sala_t *sala, int *cantidad)
{
	if (sala == NULL){
		*cantidad = -1;
		return NULL;
	}

	if (cantidad == NULL) {
		cantidad = malloc(sizeof(int));
	}

	*cantidad = sala->cantidad_objetos;
	// printf("\n\n\nObjetos: %i\n\n\n", *cantidad);
	char **nombres_objetos = malloc( (unsigned) (*cantidad) * ( sizeof(char *) ) );

	if (nombres_objetos == NULL){
		free(nombres_objetos);
		*cantidad = -1;
		return NULL;
	}

	for( int i = 0; i < *cantidad; i++ )
	{
		// if (nombres_objetos == NULL)
		// {
		// 	*cantidad = -1;
		// 	return NULL;
		// }

		nombres_objetos[i] = sala->objetos[i]->nombre;
	}

	return nombres_objetos;
}

bool sala_es_interaccion_valida(sala_t *sala, const char *verbo, const char *objeto1,
				const char *objeto2)
{

	if (sala == NULL || verbo == NULL || objeto1 == NULL || objeto2 == NULL) return NULL;

	for ( int i = 0; i < sala->cantidad_interacciones; i++ )
	{
		if (
			!strcmp(sala->interacciones[i]->verbo, verbo) &&
			!strcmp(sala->interacciones[i]->objeto, objeto1) &&
			!strcmp(sala->interacciones[i]->objeto_parametro, objeto2)
		) return true;
	}
	return false;
}

void sala_destruir(sala_t *sala)
{
	for (int i = 0; i < sala->cantidad_objetos; i++) {
		free(sala->objetos[i]);
	}
	free(sala->objetos);
	for (int i = 0; i < sala->cantidad_interacciones; i++) {
		free(sala->interacciones[i]);
	}
	free(sala->interacciones);

	free(sala);
}
