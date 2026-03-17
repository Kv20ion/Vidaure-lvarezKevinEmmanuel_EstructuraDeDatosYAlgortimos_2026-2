/*
 * PRACTICA 5: Estrucutra de Datos y Algoritmos
 *
 * Implementación de la COLA
 *
 * Una cola es una estructura de datos lineal que sigue el principio FIFO (First In, First Out),
 * lo que implica que el primer elemento en entrar es también el primero en salir. Funciona
 * como una fila común de personas esperando su turno.
 *
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 * Última modificación: 16 de marzo del 2026
 *
 */

#include <stdio.h>
#include "cola.h"

int main() {
    Cola c;
    inicializar(&c);
    int opcion, n, blindaje;
    ElementoCola elem;

    printf("=== COLAS ===\n");

    // Ingreso inicial de N nodos
    printf("INGRESE CUANTOS ELEMENTOS DESEA ENCOLAR AL INICIO: ");
    blindaje = scanf("%d", &n);
    while (getchar() != '\n'); // Limpiar el buffer
    if (blindaje != 1 || n < 1 || n > 100) { // Blindaje para evitar saturaraciones
      printf("ERROR. SE EXCEDE EL LÍMITE DE NODOS.\n");
      continue;
    }

    for (int i = 0; i < n; i++) {
        printf("Elemento %d:\n", i+1);
        printf("  Número: ");
        scanf("%d", &elem.numero);
        printf("  Texto: ");
        scanf(" %99[^\n]", elem.texto);  // Leer línea con espacios
        encolar(&c, elem);
    }

    do {
        printf("\n=== MENÚ PARA LA COLA ===\n");
        printf("1. Encolar 1 elemento\n");
        printf("2. Encolar N elementos\n");
        printf("3. Desencolar\n");
        printf("4. Ver frente\n");
        printf("5. Ver tamaño\n");
        printf("6. ¿Está vacía?\n");
        printf("7. Salir\n");
        printf("Opción: ");
        blindaje = scanf("%d", &opcion);
        if (blindaje != 1 || opcion < 1 || opcion > 7) { // Blindaje para evitar saturaraciones
          printf("ERROR. OPCIÓN NO VÁLIDA. INTENTE DE NUEVO.\n");
          continue;
        }

        switch (opcion) {
            case 1:
                printf("Número: ");
                scanf("%d", &elem.numero);
                printf("Texto: ");
                scanf(" %99[^\n]", elem.texto);
                encolar(&c, elem);
                printf("Encolado.\n");
                break;
            case 2:
                printf("¿Cuántos elementos? ");
                blindaje = scanf("%d", &n);
                if (blindaje != 1 || n < 1 || n > 100) { // Blindaje para evitar saturaraciones
                  printf("ERROR. SE EXCEDE EL LÍMITE DE NODOS.\n");
                  continue;
                }
                for (int i = 0; i < n; i++) {
                    printf("Elemento %d:\n", i+1);
                    printf("  Número: ");
                    scanf("%d", &elem.numero);
                    printf("  Texto: ");
                    scanf(" %99[^\n]", elem.texto);
                    encolar(&c, elem);
                }
                break;
            case 3:
                if (desencolar(&c, &elem))
                    printf("Desencolado: (%d, \"%s\")\n", elem.numero, elem.texto);
                else
                    printf("Cola vacía.\n");
                break;
            case 4:
                if (colaFrente(&c, &elem))
                    printf("Frente: (%d, \"%s\")\n", elem.numero, elem.texto);
                else
                    printf("Cola vacía.\n");
                break;
            case 5:
                printf("Tamaño = %d\n", colaTamanio(&c));
                break;
            case 6:
                printf(colaVacia(&c) ? "Sí está vacía.\n" : "No está vacía.\n");
                break;
            case 7:
                destruirCola(&c);
                printf("HASTA LUEGO.\n");
                break;
            default:
                printf("ERROR. OPCIÓN NO VÁLIDA. INTENTE DE NUEVO.\n");
        }
    } while (opcion != 7);

    return 0;
}
