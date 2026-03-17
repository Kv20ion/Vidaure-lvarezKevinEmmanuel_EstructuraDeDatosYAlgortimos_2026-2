#include <stdio.h>
#include "cola.h"

int main(void) {
    Cola c;
    inicializar(&c);

    printf("¿Cola vacía? %d\n", colaVacia(&c));

    /* Encolar algunos valores */
    encolar(&c, 10);
    encolar(&c, 20);
    encolar(&c, 30);
    printf("Tamaño tras encolar: %d\n", colaTamanio(&c));

    /* Consultar el frente (peek) */
    int f = colaFrente(&c);
    printf("Frente actual: %d\n", f);

    /* Desencolar todos */
    while (!colaVacia(&c)) {
        int x = desencolar(&c);
        printf("Desencolado: %d (tam=%d)\n", x, colaTamanio(&c));
    }

    printf("¿Cola vacía al final? %d\n", colaVacia(&c));

    destruirCola(&c);
    return 0;
}
