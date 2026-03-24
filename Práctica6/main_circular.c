//Inicialización de las bibliotecas y referencias a otros archivos a emplear
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "ColaCircular.h"
#include "ColaCircular.c"

// Función para crear un proceso aleatorio
Proceso generarProcesoAleatorio(ColaCircular *q) {
    Proceso p;
    sprintf(p.nombre, "Proc_%d", rand() % 100);
    
    int id;
    do {
        id = 1000 + (rand() % 9000); // 4 dígitos
    } while (cola_circ_id_existe(q, id));
    
    p.numProcess = id;
    p.ramRequerida = (float)(rand() % 320) / 10.0; // RAM 0.0 a 32.0 GB
    return p;
}

//Función para imprimir la información 
void mostrarProceso(Proceso p, char *accion) {
    printf("[%s] Proceso: %-8s | ID: %d | RAM: %.2f GB\n", 
           accion, p.nombre, p.numProcess, p.ramRequerida);
}

int main() {
    srand(time(NULL));
    ColaCircular q;
    int cap;

    printf("Capacidad de la cola de procesos: ");
    scanf("%d", &cap);

    if (!cola_circ_init(&q, cap)) return 1;

    // Llenado inicial
    printf("\n--- CARGANDO PROCESOS INICIALES ---\n");
    while (q.tam < q.capacidad) {
        Proceso nuevo = generarProcesoAleatorio(&q);
        cola_circ_encolar(&q, nuevo);
        mostrarProceso(nuevo, "ENCOLADO");
    }

    // Ciclo de procesamiento
    char op;
    do {
        printf("\n-----------------------------------\n");
        Proceso p;
        if (cola_circ_desencolar(&q, &p)) {
            mostrarProceso(p, "DESENCOLADO");
            
            if (q.tam < q.capacidad) {
                printf("¿Desea agregar otro proceso? (s/n): ");
                scanf(" %c", &op);
                if (op == 's' || op == 'S') {
                    Proceso nuevo = generarProcesoAleatorio(&q);
                    cola_circ_encolar(&q, nuevo);
                    mostrarProceso(nuevo, "ENCOLADO");
                }
            }
        } else {
            printf("No hay más procesos en la cola.\n");
            break;
        }
    } while (q.tam > 0);

    printf("\nSaliendo de la cola de procesos\n");
    cola_circ_destroy(&q);
    return 0;
}
