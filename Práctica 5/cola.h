/*
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 */

#ifndef COLA_H
#define COLA_H

// Estructura de elementos
typedef struct {
    int numero;
    char texto[100]; // Cadena de caracteres
} ElementoCola;

typedef struct Nodo Nodo;

typedef struct Cola { // Cola FIFO
    Nodo *frente; // Primer elemento
    Nodo *final; // Último elemento
    int tam; // Tamaño de la cola
} Cola;

// Inicialización de funciones
void inicializar(Cola *c);
void encolar(Cola *c, ElementoCola v);
int  desencolar(Cola *c, ElementoCola *salida);
int  colaVacia(Cola *c);
int  colaTamanio(Cola *c);
void limpiarCola(Cola *c);
void destruirCola(Cola *c);
int  colaFrente(Cola *c, ElementoCola *salida);

#endif
