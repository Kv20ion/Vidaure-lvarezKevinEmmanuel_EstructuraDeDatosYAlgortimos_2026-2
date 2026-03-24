/*
 * PRACTICA 6: Estrucutra de Datos y Algoritmos
 *
 * Cola Doble
 *En C, una cola doble (o deque, double-ended queue) 
 es una estructura de datos lineal que permite insertar y eliminar 
 elementos por ambos extremos: el frente (front) y el final (rear).
 * 
 *
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 * Última modificación: 24 de marzo del 2026
 *
 */

#include <stdlib.h>
#include "ColaDoble.h"

// Inicializar cola
int cola_doble_init(ColaDoble *c) {
    if (!c) return 0;

    c->head = NULL;
    c->tail = NULL;
    c->tam = 0;

    return 1;
}

// Verificar si existe ID
int cola_doble_id_existe(ColaDoble *c, int id) {
    if (!c || c->tam == 0) return 0;

    Nodo *temp = c->head;

    while (temp != NULL) {
        if (temp->dato.numProcess == id)
            return 1;
        temp = temp->sig;
    }

    return 0;
}

// Encolar al final
int encolarFinal(ColaDoble *c, Proceso p) {
    if (!c) return 0;

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) return 0;

    nuevo->dato = p;
    nuevo->sig = NULL;
    nuevo->ant = c->tail;

    if (c->tam == 0) {
        c->head = nuevo;
        c->tail = nuevo;
    } else {
        c->tail->sig = nuevo;
        c->tail = nuevo;
    }

    c->tam++;
    return 1;
}

// Encolar al inicio
int encolarInicio(ColaDoble *c, Proceso p) {
    if (!c) return 0;

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo) return 0;

    nuevo->dato = p;
    nuevo->ant = NULL;
    nuevo->sig = c->head;

    if (c->head != NULL)
        c->head->ant = nuevo;
    else
        c->tail = nuevo;

    c->head = nuevo;
    c->tam++;
    return 1;
}

// Desencolar del inicio
int desencolarInicio(ColaDoble *c, Proceso *salida) {
    if (!c || c->tam == 0) return 0;

    Nodo *eliminar = c->head;

    if (salida) *salida = eliminar->dato;

    if (c->tam == 1) {
        c->head = NULL;
        c->tail = NULL;
    } else {
        c->head = c->head->sig;
        c->head->ant = NULL;
    }

    free(eliminar);
    c->tam--;

    return 1;
}

// Desencolar del final
int desencolarFinal(ColaDoble *c, Proceso *salida) {
    if (!c || c->tam == 0) return 0;

    Nodo *eliminar = c->tail;

    if (salida) *salida = eliminar->dato;

    if (c->tam == 1) {
        c->head = NULL;
        c->tail = NULL;
    } else {
        c->tail = c->tail->ant;
        c->tail->sig = NULL;
    }

    free(eliminar);
    c->tam--;

    return 1;
}

// Liberar memoria
void cola_doble_destroy(ColaDoble *c) {
    Proceso aux;
    while (desencolarInicio(c, &aux));
}
