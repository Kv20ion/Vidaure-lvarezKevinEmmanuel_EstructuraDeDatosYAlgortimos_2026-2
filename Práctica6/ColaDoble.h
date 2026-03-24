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

#ifndef COLA_DOBLE_H
#define COLA_DOBLE_H

// Estructura del proceso (igual que ya usas)
typedef struct {
    char nombre[50];
    int numProcess;
    float ramRequerida;
} Proceso;
// Nodo doble
typedef struct Nodo {
    Proceso dato;
    struct Nodo *sig;
    struct Nodo *ant;
} Nodo;

// Cola doble
typedef struct {
    Nodo *head;
    Nodo *tail;
    int tam;
} ColaDoble;

// Funciones
int cola_doble_init(ColaDoble *c);

int encolarInicio(ColaDoble *c, Proceso p);
int encolarFinal(ColaDoble *c, Proceso p);

int desencolarInicio(ColaDoble *c, Proceso *salida);
int desencolarFinal(ColaDoble *c, Proceso *salida);

int cola_doble_id_existe(ColaDoble *c, int id);

void cola_doble_destroy(ColaDoble *c);

#endif
