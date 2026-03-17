#ifndef PILA_H
#define PILA_H

/* Declaraciones adelantadas */
typedef struct Nodo
{
	int dato;
	struct Nodo *sig;
} Nodo;

typedef struct Pila
{
	Nodo *tope;
	int tam; /* Ahora el tamaño es un entero normal */
} Pila;

/* Funciones */
void pila_init(Pila *p);
int pila_esta_vacia(Pila *p);

int pila_push(Pila *p, int valor);
int pila_pop(Pila *p, int *salida);
int pila_peek(Pila *p, int *salida);

void pila_clear(Pila *p);
void pila_destroy(Pila *p);

#endif
