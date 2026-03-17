// Librerias a usar
#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

// Estructura de Nodo
struct Nodo {
  int dato;
  Nodo *sig;
};

// Funcion para inicializar la estrucutra
void inicializar(Cola *c) {
  c -> frente = NULL;
  c -> final = NULL;
  c -> tam = 0;
}

// Funcion para encolar
void encolar(Cola *c, int v) {
  Nodo* nuevo = (Nodo*) malloc(sizeof(Nodo)); // Memoria dinamica
  nuevo -> dato = v;
  if (nuevo == NULL) return; // Manejo del error
  nuevo -> dato = v;
  nuevo -> sig = NULL;

  if (c -> final == NULL) { // Cola vacia
    c -> frente = nuevo;
    c -> final = nuevo;
  }
  else {
    c -> final -> sig = nuevo;
    c -> final = nuevo;
  }
  c -> tam++;
}

// Funcion para desencolar
int desencolar(Cola *c) {
  int valor = 0;

  // Verificar si la cola ya esta vacia
  if (c -> frente == NULL) {
    exit(EXIT_FAILURE); // Sale del programa con ERROR
  }

  Nodo *aux = c -> frente;
  valor = aux -> dato;
  c -> frente = aux -> sig;

  // Verifica que se hayan recorrido los valores
  if (c -> frente == NULL) {
    c -> final = NULL;
  }
  free(aux); // Libera memoria

  c -> tam--; // Variable tam hace un decremento
  return valor;
}

// Funcion para verificar si la cola esta vacia
int colaVacia(Cola *c) {
  return c -> frente == NULL;
}

// Funcion para devolver el tamanio de la cola
int colaTamanio(Cola *c) {
  return c ? c -> tam : 0;
}

// Funcion para limpiar los datos de la cola
void limpiarCola(Cola *c) {
    if (!c) return;

    Nodo *it = c->frente;
    while (it) {
        Nodo *sig = it->sig;
        free(it);
        it = sig;
    }

    c->frente = NULL;
    c->final  = NULL;
    c->tam    = 0;
}

// Destruir la cola (solo la limpia, sin datos no hay cola)
void destruirCola(Cola *c) {
    limpiarCola(c);
}

// Funcion para mostrar el ultimo elemento
int colaFrente(Cola *c) {
  if (c -> frente == NULL) {
    exit(EXIT_FAILURE); // Si la cola esta vacia sale con ERROR
  }
  return c -> frente -> dato; // Regresa el elemento al frente
}
