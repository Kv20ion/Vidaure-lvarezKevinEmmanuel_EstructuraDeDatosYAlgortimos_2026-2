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
// Inicialización de las bibliotecas y referencias
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "ColaDoble.h"
#include "ColaDoble.c"

// Función para crear un proceso aleatorio
Proceso generarProcesoAleatorio(ColaDoble *q) {
    Proceso p;
    sprintf(p.nombre, "Proc_%d", rand() % 100);
    
    int id;
    do {
        id = 1000 + (rand() % 9000); // 4 dígitos
    } while (cola_doble_id_existe(q, id));
    
    p.numProcess = id;
    p.ramRequerida = (float)(rand() % 320) / 10.0;
    return p;
}

// Mostrar proceso
void mostrarProceso(Proceso p, char *accion) {
    printf("[%s] Proceso: %-8s | ID: %d | RAM: %.2f GB\n", 
           accion, p.nombre, p.numProcess, p.ramRequerida);
}

int main() {
    srand(time(NULL));

    ColaDoble q;
    int cap;

    printf("Capacidad de la cola de procesos: ");
    scanf("%d", &cap);

    if (!cola_doble_init(&q)) return 1;

    //  Llenado inicial
    printf("\n--- CARGANDO PROCESOS INICIALES ---\n");
    while (q.tam < cap) {
        Proceso nuevo = generarProcesoAleatorio(&q);
        encolarFinal(&q, nuevo);  //  entra al final
        mostrarProceso(nuevo, "ENCOLADO");
    }

    //  Ciclo de procesamiento
    char op;
    do {
        printf("\n-----------------------------------\n");

        Proceso p;
        if (desencolarInicio(&q, &p)) {  //  sale del inicio 
            mostrarProceso(p, "DESENCOLADO");

            printf("¿Desea insertar otro proceso? (s/n): ");
            scanf(" %c", &op);

            if (op == 's' || op == 'S') {
                Proceso nuevo = generarProcesoAleatorio(&q);
                encolarFinal(&q, nuevo);   
                // encolarInicio(&q, nuevo); // prioridad

                mostrarProceso(nuevo, "ENCOLADO");
            }

        } else {
            printf("No hay más procesos en la cola.\n");
            break;
        }

    } while (q.tam > 0);

    printf("\nSaliendo de la cola de procesos\n");
    cola_doble_destroy(&q);//se libera la memoria

    return 0;
}
