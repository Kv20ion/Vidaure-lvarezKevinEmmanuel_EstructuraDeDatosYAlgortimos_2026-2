#include <stdio.h>
#include "pila.h"

int main() {
    Pila p;
    pila_init(&p);
    int opcion, n;
    ElementoPila elem;

    printf("=== PILAS (datos con estructura) ===\n");

    // Ingreso inicial de N nodos
    printf("¿Cuántos elementos desea apilar al inicio? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d:\n", i+1);
        printf("  Valor: ");
        scanf("%d", &elem.valor);
        printf("  Descripción: ");
        scanf(" %99[^\n]", elem.descripcion);
        pila_push(&p, elem);
    }

    do {
        printf("\n--- Menú Pila ---\n");
        printf("1. Apilar 1 elemento\n");
        printf("2. Apilar N elementos\n");
        printf("3. Desapilar\n");
        printf("4. Ver tope\n");
        printf("5. Ver tamaño\n");
        printf("6. ¿Está vacía?\n");
        printf("7. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Valor: ");
                scanf("%d", &elem.valor);
                printf("Descripción: ");
                scanf(" %99[^\n]", elem.descripcion);
                pila_push(&p, elem);
                printf("Apilado.\n");
                break;
            case 2:
                printf("¿Cuántos elementos? ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Elemento %d:\n", i+1);
                    printf("  Valor: ");
                    scanf("%d", &elem.valor);
                    printf("  Descripción: ");
                    scanf(" %99[^\n]", elem.descripcion);
                    pila_push(&p, elem);
                }
                break;
            case 3:
                if (pila_pop(&p, &elem))
                    printf("Desapilado: (%d, \"%s\")\n", elem.valor, elem.descripcion);
                else
                    printf("Pila vacía.\n");
                break;
            case 4:
                if (pila_peek(&p, &elem))
                    printf("Tope: (%d, \"%s\")\n", elem.valor, elem.descripcion);
                else
                    printf("Pila vacía.\n");
                break;
            case 5:
                printf("Tamaño = %d\n", p.tam);
                break;
            case 6:
                printf(pila_esta_vacia(&p) ? "Sí está vacía.\n" : "No está vacía.\n");
                break;
            case 7:
                pila_destroy(&p);
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 7);

    return 0;
}
