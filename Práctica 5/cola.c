/*
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 */

#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

// Estructura para almacenar los elementos
struct Nodo {
    ElementoCola dato;
    Nodo *sig;
};

// Función para inicializar la cola
void inicializar(Cola *c) {
    c->frente = NULL;
    c->final = NULL;
    c->tam = 0;
}

// Función para encolar
void encolar(Cola *c, ElementoCola v) {
    Nodo *nuevo = (Nodo*) malloc(sizeof(Nodo)); // Uso de memoria dinámica para gestionar Nodos
    if (nuevo == NULL) return; // Error de memoria
    nuevo->dato = v;
    nuevo->sig = NULL;

    if (c->final == NULL) { // Cola vacía
        c->frente = nuevo;
        c->final = nuevo;
    } else {
        c->final->sig = nuevo;
        c->final = nuevo;
    }
    c->tam++;
}

// Función para desencolar
int desencolar(Cola *c, ElementoCola *salida) {
    if (c->frente == NULL) return 0; // Cola vacía

    Nodo *aux = c->frente;
    *salida = aux->dato;
    c->frente = aux->sig;

    if (c->frente == NULL) {
        c->final = NULL;
    }
    free(aux);
    c->tam--;
    return 1; // Éxito
}

// Función cola vacía
int colaVacia(Cola *c) {
    return c->frente == NULL;
}

// Función para el tamaño de la cola
int colaTamanio(Cola *c) {
    return c ? c->tam : 0;
}

// Función para limpiar la cola
void limpiarCola(Cola *c) {
    if (!c) return;
    Nodo *it = c->frente;
    while (it) {
        Nodo *sig = it->sig;
        free(it);
        it = sig;
    }
    c->frente = NULL;
    c->final = NULL;
    c->tam = 0;
}

// Función para destruir la cola
void destruirCola(Cola *c) {
    limpiarCola(c); // Limpia la cola, din datos no hay cola
}

// Función para encontrar el elemento al frente de la cola
int colaFrente(Cola *c, ElementoCola *salida) {
    if (c->frente == NULL) return 0;
    *salida = c->frente->dato;
    return 1;
}
