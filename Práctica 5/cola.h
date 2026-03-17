#ifndef COLA_H
#define COLA_H

typedef struct Nodo Nodo;

typedef struct Cola { // Cola FIFO
  Nodo *frente; // Cabeza, el primer elemento
  Nodo *final; // Cola, el ultimo elemento
  int tam; // Tamanio de la cola
} Cola;

void inicializar(Cola *c);
void encolar(Cola *c, int v);
int desencolar(Cola *c);
int colaVacia(Cola *c);
int colaTamanio(Cola *c);
void limpiarCola(Cola *c);
void destruirCola(Cola *c);
int colaFrente(Cola *c);

#endif // COLA_H
