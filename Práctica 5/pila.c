/*
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 */

#include "pila.h"
#include <stdlib.h>

// Estructura para almacenar datos de la PILA
struct Nodo {
    ElementoPila dato;
    Nodo *sig;
};

// Función para inicializar la pila
void pila_init(Pila *p) {
    if (!p) return;
    p->tope = NULL;
    p->tam = 0;
}

// Función para mostrar si la pila está vacía
int pila_esta_vacia(Pila *p) {
    return (!p || p->tam == 0) ? 1 : 0;
}

// Función push para meter elementos a la pila
int pila_push(Pila *p, ElementoPila valor) {
    if (!p) return 0;
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo));
    if (!nuevo) return 0;
    nuevo->dato = valor;
    nuevo->sig = p->tope;
    p->tope = nuevo;
    p->tam++;
    return 1;
}

// Función para eliminar y devolver el elemento superior
int pila_pop(Pila *p, ElementoPila *salida) {
    if (!p || p->tam == 0) return 0;
    Nodo *aux = p->tope;
    *salida = aux->dato;
    p->tope = aux->sig;
    free(aux);
    p->tam--;
    return 1;
}

// Función para devolver el elemento superior sin eliminarlo
int pila_peek(Pila *p, ElementoPila *salida) {
    if (!p || p->tam == 0) return 0;
    *salida = p->tope->dato;
    return 1;
}

// Función para limpiar la pila
void pila_clear(Pila *p) {
    if (!p) return;
    Nodo *actual = p->tope;
    while (actual) {
        Nodo *sig = actual->sig;
        free(actual);
        actual = sig;
    }
    p->tope = NULL;
    p->tam = 0;
}

// Función para destruir la pila
void pila_destroy(Pila *p) {
    pila_clear(p); // Solo limpia la pila, sin datos no hay pila
}
