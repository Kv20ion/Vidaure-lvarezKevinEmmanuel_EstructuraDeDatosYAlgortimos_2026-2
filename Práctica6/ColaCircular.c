//Inicialización de las bibliotecas y referencia del archivo a emplear
#include <stdlib.h>
#include <stdio.h>
#include "ColaCircular.h"

//Inicialización de la estructura de cola circular
int cola_circ_init(ColaCircular *c, int capacidad) {
    //Se evalúa que la cola y la capacidad ingresada sean datos válidos
    if (!c || capacidad <= 0) return 0;
    //Los apuntadores de la cabeza y la cola apuntan a NULL
    c->head = NULL;
    c->tail = NULL;
    //El tamaño de la cola al inicializar es 0 y se le asigna la capacidad ingresada 
    c->tam = 0;
    c->capacidad = capacidad;
    return 1;
}

// Funcion que verifica que el ID del proceso no se repita
int cola_circ_id_existe(ColaCircular *c, int id) {
    //Evalúa que la cola ingresada sea 
    if (!c || c->tam == 0) return 0;
    //Un nodo temporal almacena la cabeza de la cola
    Nodo *temp = c->head;
    //El ciclo recorre cada elemento de la cola por medio del nodo temporal y sus elementos consecuentes
    //Compara el ID del proceso con el ID ingresado
    for (int i = 0; i < c->tam; i++) {
        if (temp->dato.numProcess == id) return 1;
        temp = temp->sig;
    }
    return 0;
}

//Funcion para encolar elementos en la cola circular
int cola_circ_encolar(ColaCircular *c, Proceso p) {
    if (!c || c->tam == c->capacidad) return 0;
    /*Se crea un nuevo nodo por medio de la función malloc, la cual aparta 
    la cantidad de memoria requerida para el nodo, después se le asigna el dato
    ingresado*/
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = p;

    /*En caso de que el tamaño de la cola sea 0; la cabeza y la cola apuntan al nuevo
    apuntador*/
    if (c->tam == 0) {
        c->head = nuevo;
        c->tail = nuevo;
        /*El siguiente elemento del nuevo nodo apunta a la cabeza de la cola para conectar 
        circularmente la estructura*/
        nuevo->sig = c->head; // Conexión circular
    } else {
        /*En caso de que la cola ya tenga elementos; a la cola actual se le asigna de siguiente el nuevo nodo.
        A la cola de la estructura se le asigna el nodo nuevo y al siguiente de la cola se le asigna la cabeza
        para mantener la circularidad de la estructura*/
        c->tail->sig = nuevo;
        c->tail = nuevo;
        c->tail->sig = c->head;
    }
    //Aumenta el tamaño de la cola
    c->tam++;
    return 1;
}

//Funcion para desencolar elementos de la cola circular
int cola_circ_desencolar(ColaCircular *c, Proceso *salida) {
    if (!c || c->tam == 0) return 0;
    //Un nodo hace referencia a la cabeza de la cola
    Nodo *eliminar = c->head;
    //Se evaluá s
    if (salida) *salida = eliminar->dato;

    if (c->tam == 1) {
        c->head = NULL;
        c->tail = NULL;
    } else {
        c->head = c->head->sig;
        c->tail->sig = c->head; // Re-conectar el final con el nuevo frente
    }
    //Se libera la memoria ocupada por el nodo eliminado
    free(eliminar);
    //Se reduce el tamaño de la cola
    c->tam--;
    return 1;
}

//Función 
void cola_circ_destroy(ColaCircular *c) {
    Proceso aux;
    while (cola_circ_desencolar(c, &aux));
}
