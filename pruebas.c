#include "src/sala.h"
#include "src/objeto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pruebas_creacion_objetos() {

    printf("\nPRUEBAS DE CREACION DE OBJETOS:\n\n");

    printf("No puedo crear un objeto a partir de un string NULL: ");
    printf("%s\n", objeto_crear_desde_string(NULL) == NULL ? "Pasa" : "Fail");

    printf("No puedo crear un objeto a partir de un string vacío: ");
    printf("%s\n", objeto_crear_desde_string("") == NULL ? "Pasa" : "Fail");

    printf("'a;b' no es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("a;b") == NULL ? "Pasa" : "Fail");

    printf("'a;;b' no es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("a;;b") == NULL ? "Pasa" : "Fail");

    printf("'a;b;c' no es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("a;b;c") == NULL ? "Pasa" : "Fail");

    printf("'a;;true' no es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("a;;true") == NULL ? "Pasa" : "Fail");

    printf("';b;false' no es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string(";b;false") == NULL ? "Pasa" : "Fail");

    printf("'nombre;desc;true' es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("nombre;desc;true") != NULL ? "Pasa" : "Fail");

    printf("El nombre del objeto es 'nombre': ");
    printf("%s\n", !strcmp(objeto_crear_desde_string("nombre;desc;true")->nombre, "nombre") ? "Pasa" : "Fail");

    printf("La descripcion del objeto es 'desc': ");
    printf("%s\n", !strcmp(objeto_crear_desde_string("nombre;desc;true")->descripcion, "desc") ? "Pasa" : "Fail");

    printf("El objeto es asible: ");
    printf("%s\n", objeto_crear_desde_string("nombre;desc;true")->es_asible ? "Pasa" : "Fail");

    printf("'A;Be;false/n' es un string objeto válido: ");
    printf("%s\n", objeto_crear_desde_string("A;Be;false\n") != NULL ? "Pasa" : "Fail");

    printf("El nombre del objeto es 'A': ");
    printf("%s\n", !strcmp(objeto_crear_desde_string("A;Be;false\n")->nombre, "A") ? "Pasa" : "Fail");

    printf("La descripcion del objeto es 'Be': ");
    printf("%s\n", !strcmp(objeto_crear_desde_string("A;Be;false\n")->descripcion, "Be") ? "Pasa" : "Fail");

    printf("El objeto es asible: ");
    printf("%s\n", !objeto_crear_desde_string("A;Be;false\n")->es_asible ? "Pasa" : "Fail");

    return 0;
}

int pruebas_vector_nombres() {

    printf("\nPRUEBAS DEL VECTOR DE NOMBRES:\n\n");

    printf("No puedo obtener los nombres de objetos de una sala NULL: ");
    printf("%s\n", sala_obtener_nombre_objetos(NULL, 0) == NULL ? "Pasa" : "Fail");

    printf("La cantidad es -1 luego de invocar a la función: ");
    printf("%s\n", sala_obtener_nombre_objetos(NULL, 0) == -1 ? "Pasa" : "Fail");

    printf("Puedo pedir el vector de nombres a la sala pasando cantidad NULL: ");
    printf("%s\n", sala_obtener_nombre_objetos(NULL, NULL) == NULL ? "Pasa" : "Fail");

    return 0;
}

int main ( int argc, char *argv[])
{

    pruebas_creacion_objetos();



    return 0;
}