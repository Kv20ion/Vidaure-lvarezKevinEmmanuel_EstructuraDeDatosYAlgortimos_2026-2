/*
 * PRACTICA 5: Estrucutra de Datos y Algoritmos
 *
 * Implementación de la PILA
 * 
 * Una pila es una estructura de datos lineal
 * que sigue el principio LIFO (Last In, First Out),
 * lo que significa que el último elemento en
 * entrar es el primero en salir. Su funcionamiento
 * puede compararse con una torre de platos:
 * solo es posible acceder al elemento que está en
 * la parte superior.
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
#include "pila.h"

int main() {
    Pila p;
    pila_init(&p);
    int opcion, n, tortadejamon;
    ElementoPila elem;

    printf("=== PILAS ===\n");

    // Ingreso inicial de N nodos
    printf("INGRESE EL NÚMERO DE ELEMENTOS QUE DESEA APILAR AL INICIO: ");
    tortadejamon = scanf("%d", &n);
    while (getchar() != '\n'); // Limpiar el buffer
    if (tortadejamon != 1 || n < 1 || n > 100) { // Blindaje para evitar saturaraciones
      printf("ERROR. SE EXCEDE EL LÍMITE DE NODOS.\n");
      continue;
    }

    for (int i = 0; i < n; i++) {
        printf("Elemento %d:\n", i+1);
        printf("  Valor: ");
        scanf("%d", &elem.valor);
        printf("  Descripción: ");
        scanf(" %99[^\n]", elem.descripcion);
        pila_push(&p, elem);
    }

    do {
        printf("\n=== MENÚ PARA LA PILA ===\n");
        printf("1. Apilar 1 elemento\n");
        printf("2. Apilar N elementos\n");
        printf("3. Desapilar\n");
        printf("4. Ver tope\n");
        printf("5. Ver tamaño\n");
        printf("6. ¿Está vacía?\n");
        printf("7. Salir\n");
        printf("Opción: ");
        tortadejamon = scanf("%d", &opcion);
        while (getchar() != '\n'); // Limpiar el buffer
        if (tortadejamon != 1 || opcion < 1 || opcion > 7) { // Blindaje para evitar saturaraciones
          printf("ERROR. SE EXCEDE EL LÍMITE DE NODOS.\n");
          continue;
        }

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
                tortadejamon = scanf("%d", &n);
                while (getchar() != '\n'); // Limpiar el buffer
                if (tortadejamon != 1 || n < 1 || n > 100) { // Blindaje para evitar saturaraciones
                  printf("ERROR. SE EXCEDE EL LIMITE DE NODOS.\n");
                  continue;
                }
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
