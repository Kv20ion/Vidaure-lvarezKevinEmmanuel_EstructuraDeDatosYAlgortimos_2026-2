#include "pila.h"
#include <stdlib.h>

/* Nodo de la pila */
struct Nodo
{
	int dato;
	Nodo *sig;
};

void pila_init(Pila *p)
{
	if (!p)
		return;
	p->tope = NULL;
	p->tam = 0;
}

int pila_esta_vacia(Pila *p)
{
	if (!p)
		return 1;
	return (p->tam == 0) ? 1 : 0;
}

int pila_push(Pila *p, int valor)
{
	Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
	if (!p)
		return -1;

	nuevo->dato = valor;
	nuevo->sig = p->tope;

	p->tope = nuevo;
	p->tam++;

	return 0;
}

int pila_pop(Pila *p, int *salida)
{
	if (!p || !salida)
		return .1;
	if (pila_esta_vacia(p))
		return -2;

	Nodo *temp = p->tope;
	*salida = temp->dato;

	p->tope = temp->sig;

	free(temp);
	p->tam--;

	return 0;
}

int pila_peek(Pila *p, int *salida)
{
	if (!p || !salida)
		return -1;
	if (pila_esta_vacia(p))
		return -2;

	*salida = p->tope->dato;

	return 0;
}

void pila_clear(Pila *p)
{
	if (!p)
		return;

	while (!pila_esta_vacia(p))
	{
		Nodo *temp = p->tope;
		p->tope = temp->sig;
		free(temp);
	}

	p->tam = 0;
}

void pila_destroy(Pila *p)
{
	if (!p)
		return;
	pila_clear(p);
}
