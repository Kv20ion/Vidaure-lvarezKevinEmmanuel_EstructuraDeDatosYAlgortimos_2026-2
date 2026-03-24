#ifndef COLA_CIRCULAR_PROCESOS_H
#define COLA_CIRCULAR_PROCESOS_H

//Definición de la estructura Proceso
typedef struct {
    //Arreglo de caractéres para guardar el nombre
    char nombre[16];
    //Numero identificador del proceso
    int numProcess;
    //Cantidad de RAM requerida
    float ramRequerida;
} Proceso;

//Definición de la estructura Nodo
typedef struct Nodo {
    //Dato tipo "Proceso que contiene el nodo"
    Proceso dato;
    //Apuntador del nodo que apunta al siguiente en la lista
    struct Nodo *sig;
} Nodo;

//Definición de la estructura de la Cola Circular
typedef struct {
    //2 Nodos: Cabeza y Cola
    Nodo *head;      
    Nodo *tail; 
    //Tamaño y capacidad de la cola circular
    int tam;       
    int capacidad; 
} ColaCircular;

//Declaración de las funciones a emplear
int  cola_circ_init(ColaCircular *c, int capacidad);
int  cola_circ_encolar(ColaCircular *c, Proceso p);
int  cola_circ_desencolar(ColaCircular *c, Proceso *salida);
int  cola_circ_id_existe(ColaCircular *c, int id);
void cola_circ_destroy(ColaCircular *c);

#endif
