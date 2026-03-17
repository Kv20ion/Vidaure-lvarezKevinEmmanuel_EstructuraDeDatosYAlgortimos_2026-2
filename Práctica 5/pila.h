/*
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 */

#ifndef PILA_H
#define PILA_H

// Estructura del dato a almacenar
typedef struct {
    int valor;
    char descripcion[100];
} ElementoPila;

typedef struct Nodo Nodo;

typedef struct Pila {
    Nodo *tope;
    int tam;
} Pila;

// Inicialización de las funciones
void pila_init(Pila *p);
int  pila_esta_vacia(Pila *p);

int  pila_push(Pila *p, ElementoPila valor);
int  pila_pop(Pila *p, ElementoPila *salida);
int  pila_peek(Pila *p, ElementoPila *salida);

void pila_clear(Pila *p);
void pila_destroy(Pila *p);

#endif
