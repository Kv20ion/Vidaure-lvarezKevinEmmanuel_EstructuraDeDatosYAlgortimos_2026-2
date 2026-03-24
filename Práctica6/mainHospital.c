/*
 * ELABORADO POR: BRIGADA #1
 *
 * ESPINOSA SALVADOR ROMAN
 * CASTELÁN SIERRA GAEL
 * MALDONADO MARTÍNEZ ERICK FERNANDO
 * VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 * Este programa implementa una cola circular doblemente enlazada para gestionar pacientes en un hospital.
 * Permite configurar hospital y doctor (simulado), encolar pacientes, desencolarlos (dar de alta),
 * visualizar la cola y salir.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ESTRUCTURAS

// Representa la información del hospital (solo para mostrar, no se usa en la cola)
typedef struct
{
    char nombre[30];
    char direccion[40];
} hospital;

// Representa la información del doctor (se usa para asignar el número de trabajador al paciente)
typedef struct
{
    char nombre[30];
    int edad;
    char especializacion[40];
    int num_trabajador;
} doctor; // Simplificado para el ejemplo

// Representa los datos de un paciente
typedef struct
{
    char nombre[30];
    int edad;
    char especializacion[40];
    int num_paciente;   // Identificador único del paciente
    int num_doctor;     // Número del doctor que lo atiende
} paciente;

// Nodo de la cola circular doblemente enlazada
typedef struct Nodo
{
    paciente dato;          // Información del paciente
    struct Nodo *sig;       // Puntero al siguiente nodo
    struct Nodo *ant;       // Puntero al nodo anterior
} Nodo;

// Estructura que representa la cola (lista circular)
typedef struct
{
    Nodo *head;             // Puntero al primer nodo (frente de la cola)
    int tamano;             // Cantidad actual de elementos
    int capacidad;          // Capacidad máxima permitida
} ColaPacientes;

// FUNCIONES DE LA COLA

// Inicializa la cola: cabeza nula, tamaño 0, y capacidad dada por el usuario
void init_cola(ColaPacientes *c, int cap)
{
    c->head = NULL;
    c->tamano = 0;
    c->capacidad = cap;
}

// Encola un nuevo paciente en la cola circular (se inserta al final)
// Retorna 1 si se pudo encolar, 0 si la cola está llena
int encolar_paciente(ColaPacientes *c, paciente p)
{
    if (c->tamano >= c->capacidad)
        return 0; // Cola llena
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->dato = p;
    if (c->head == NULL)
    {
        // Cola vacía: el nuevo nodo apunta a sí mismo
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
        c->head = nuevo;
    }
    else
    {
        // Cola con al menos un elemento: insertar al final (antes del head)
        Nodo *ultimo = c->head->ant;   // Último nodo actual
        nuevo->sig = c->head;          // El nuevo apunta al frente
        nuevo->ant = ultimo;           // El nuevo apunta al anterior último
        ultimo->sig = nuevo;           // El último anterior apunta al nuevo
        c->head->ant = nuevo;          // El frente apunta al nuevo (ahora es el último)
    }
    c->tamano++;
    return 1;
}

// Desencola al paciente al frente de la cola (lo elimina y libera memoria)
// Retorna 1 si se pudo desencolar, 0 si la cola está vacía
int desencolar_paciente(ColaPacientes *c)
{
    if (c->head == NULL)
        return 0; // Cola vacía
    Nodo *eliminar = c->head;
    if (c->tamano == 1)
    {
        // Solo un elemento: la cola queda vacía
        c->head = NULL;
    }
    else
    {
        // Más de un elemento: se ajustan los punteros para eliminar el frente
        Nodo *ultimo = c->head->ant;   // Último nodo
        Nodo *siguiente = c->head->sig; // Segundo nodo
        ultimo->sig = siguiente;        // El último ahora apunta al segundo
        siguiente->ant = ultimo;        // El segundo apunta al último
        c->head = siguiente;            // El nuevo frente es el segundo
    }
    free(eliminar);
    c->tamano--;
    return 1;
}

// Limpia toda la cola liberando la memoria de cada nodo
void limpiar_todo(ColaPacientes *c)
{
    while (desencolar_paciente(c))
        ; // Desencola hasta que esté vacía
}

// --- MAIN ---
int main()
{
    // Inicialización de variables para evitar basura
    hospital Hospital = {"Sin Nombre", "Sin Direccion"};
    doctor Doctor = {"Sin Nombre", 0, "General", 0};
    ColaPacientes cola;
    int cap;

    // Solicita la capacidad máxima de la cola al usuario
    printf("Capacidad maxima de la cola: ");
    if (scanf("%d", &cap) != 1)
        return 1; // Error de entrada
    init_cola(&cola, cap); // Inicializa la cola con esa capacidad

    int opcion = 0;
    do
    {
        // Menú principal
        printf("\n--- GESTION HOSPITALARIA ---");
        printf("\nPacientes actuales: %d/%d", cola.tamano, cola.capacidad);
        printf("\n1. Configurar Hospital/Doctor\n2. Encolar Paciente\n3. Desencolar\n4. Ver Cola\n5. Salir\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            // Aquí se podrían llamar funciones para llenar los datos del hospital y doctor
            // En este ejemplo es simulado
            printf("Datos configurados (simulado).\n");
            break;
        case 2:
        {
            // Encolar un nuevo paciente (simulación)
            paciente p;
            // Datos de ejemplo (deberían solicitarse al usuario)
            strcpy(p.nombre, "Paciente Prueba");
            p.num_paciente = rand() % 1000; // Número aleatorio
            p.num_doctor = Doctor.num_trabajador; // Asigna el doctor actual

            if (encolar_paciente(&cola, p))
                printf("Paciente encolado correctamente.\n");
            else
                printf("Cola llena, no se puede encolar.\n");
            break;
        }
        case 3:
            // Desencolar (dar de alta) al paciente del frente
            if (desencolar_paciente(&cola))
                printf("Alta dada al paciente.\n");
            else
                printf("Cola vacía, no hay pacientes.\n");
            break;
        case 4:
            // Mostrar todos los pacientes en la cola (desde el frente hasta el final)
            if (cola.head)
            {
                Nodo *t = cola.head;
                printf("Pacientes en cola:\n");
                for (int i = 0; i < cola.tamano; i++)
                {
                    printf("[%d] %s\n", i + 1, t->dato.nombre);
                    t = t->sig;
                }
            }
            else
            {
                printf("Cola vacía.\n");
            }
            break;
        }
    } while (opcion != 5); // Salir cuando opción es 5

    // Liberar toda la memoria de la cola antes de terminar
    limpiar_todo(&cola);
    return 0;
}
