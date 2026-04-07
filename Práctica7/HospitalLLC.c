/*

ESTRUCTURA DE DATOS Y ALGORITMOS I

PRACTICA 7: CÓDIGO CON LISTA LIGADA CIRCULAR

OBJETIVO:

El siguiente programa corresponde a la práctica 3
de la materia EDA I. El tema que se aborda es el
de estructuras en el lenguaje de programación C.
Con el fin de poner en práctica los conocimientos
adquiridos, se diseñará un programa que con la
ayuda de las estructuras, y la listas ligadas pueda hacer la gestión
de los datos de un hospital. Los datos abordan:

Datos del hospital
Datos de los pacientes
Datos de los doctores
Datos del Equipo Medico
Datos de los Trabajadores
Datos de intendencia
Datos sobre las Especializaciones

BRIGADA 1:

CASTELAN SIERRA GAEL
ESPINOSA SALVADOR ROMAN
MALDONADO MARTINEZ ERICK FERNANDO
VIDAURE ÁLVAREZ KEVIN EMMANUEL

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

// ==================== ESTRUCTURAS ====================

typedef struct hospital {
    char nombre[30];
    char direccion[40];
} hospital;

typedef struct equipomed {
    char nombre[30];
    char marca[30];
    char modelo[30];
    int idHospital;
} equipomed;

typedef struct especializacion {
    char nombre[30];
    int cantidaddoc;
    int cantidapac;
    int idHospital;
} especializacion;

typedef struct doctor {
    char nombre[30];
    int edad;
    char especializacion[40];
    int num_trabajador;
    int idHospital;
} doctor;

typedef struct paciente {
    char nombre[30];
    int edad;
    char especializacion[40];
    int num_paciente;
    int num_doctor;
    int idHospital;
} paciente;

typedef struct intendencia {
    char nombre[30];
    int edad;
    int numero;
    int idHospital;
} intendencia;

typedef struct trabajador {
    int numero;
    char sindicalizado[3];
    int idHospital;
} trabajador;

// ==================== NODOS CIRCULARES ====================

typedef struct NodoDoctor {
    doctor dato;
    struct NodoDoctor *sig;
} NodoDoctor;

typedef struct NodoPaciente {
    paciente dato;
    struct NodoPaciente *sig;
} NodoPaciente;

typedef struct NodoEquipo {
    equipomed dato;
    struct NodoEquipo *sig;
} NodoEquipo;

typedef struct NodoIntendencia {
    intendencia dato;
    struct NodoIntendencia *sig;
} Nodointendencia;

typedef struct Nodotrabajador {
    trabajador dato;
    struct Nodotrabajador *sig;
} Nodotrabajador;

typedef struct Nodoespecializacion {
    especializacion dato;
    struct Nodoespecializacion *sig;
} Nodoespecializacion;

// ==================== UTILIDADES ====================

void limpiarBuffer() {
    while (getchar() != '\n');
}

int leerEntero(int *n){
    int valido;
    char buffer[100];

    do{
        printf(" ");
        if(fgets(buffer, sizeof(buffer), stdin) != NULL){

            // intentar convertir a número
            if(sscanf(buffer, "%d", n) == 1 && *n >= 0){
                return 1; // válido
            }
        }

        printf("Entrada invalida. Ingresa un numero entero positivo.\n");

    }while(1);
}

void pausar() {
    printf("\nPresiona ENTER para continuar...");
    fflush(stdout);

    getchar(); // consume el \n pendiente
    getchar(); // espera el ENTER real
}

void verTodoNodoPorNodo(
    NodoDoctor *ld,
    NodoPaciente *lp,
    Nodoespecializacion *les,
    Nodointendencia *li,
    Nodotrabajador *lt,
    NodoEquipo *le,
    hospital h[]
){
    char tecla;

    // punteros actuales
    NodoDoctor *d = ld;
    NodoPaciente *p = lp;
    Nodoespecializacion *e = les;
    Nodointendencia *i = li;
    Nodotrabajador *t = lt;
    NodoEquipo *eq = le;

    int opcion = 1;

    do{
        printf("\n=========================\n");

        switch(opcion){

            case 1:
                if(d){
                    printf("DOCTOR\n");
                    printf("Nombre: %s\n", d->dato.nombre);
                    printf("Hospital: %s\n", h[d->dato.idHospital].nombre);
                    d = d->sig;
                }else printf("Sin doctores\n");
                break;

            case 2:
                if(p){
                    printf("PACIENTE\n");
                    printf("Nombre: %s\n", p->dato.nombre);
                    printf("Hospital: %s\n", h[p->dato.idHospital].nombre);
                    p = p->sig;
                }else printf("Sin pacientes\n");
                break;

            case 3:
                if(e){
                    printf("ESPECIALIZACION\n");
                    printf("Nombre: %s\n", e->dato.nombre);
                    printf("Hospital: %s\n", h[e->dato.idHospital].nombre);
                    e = e->sig;
                }else printf("Sin especializaciones\n");
                break;

            case 4:
                if(i){
                    printf("INTENDENCIA\n");
                    printf("Nombre: %s\n", i->dato.nombre);
                    printf("Hospital: %s\n", h[i->dato.idHospital].nombre);
                    i = i->sig;
                }else printf("Sin intendencia\n");
                break;

            case 5:
                if(t){
                    printf("TRABAJADOR\n");
                    printf("Numero: %d\n", t->dato.numero);
                    printf("Hospital: %s\n", h[t->dato.idHospital].nombre);
                    t = t->sig;
                }else printf("Sin trabajadores\n");
                break;

            case 6:
                if(eq){
                    printf("EQUIPO\n");
                    printf("Nombre: %s\n", eq->dato.nombre);
                    printf("Hospital: %s\n", h[eq->dato.idHospital].nombre);
                    eq = eq->sig;
                }else printf("Sin equipo\n");
                break;
        }

        printf("\n[ENTER = siguiente | q = salir]: ");
        tecla = getchar();

        while(getchar()!='\n'); // limpiar buffer

        if(tecla == '\n'){
            opcion++;
            if(opcion > 6) opcion = 1; // vuelve al inicio
        }

    }while(tecla != 'q' && tecla != 'Q');
}

// ==================== INSERTAR ====================

void insertarDoctor(NodoDoctor **lista, doctor d) {
    NodoDoctor *nuevo = malloc(sizeof(NodoDoctor));
    nuevo->dato = d;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        NodoDoctor *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

void insertarPaciente(NodoPaciente **lista, paciente p) {
    NodoPaciente *nuevo = malloc(sizeof(NodoPaciente));
    nuevo->dato = p;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        NodoPaciente *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

void insertarEquipo(NodoEquipo **lista, equipomed e) {
    NodoEquipo *nuevo = malloc(sizeof(NodoEquipo));
    nuevo->dato = e;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        NodoEquipo *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

void insertarIntendencia(Nodointendencia **lista, intendencia in) {
    Nodointendencia *nuevo = malloc(sizeof(Nodointendencia));
    nuevo->dato = in;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        Nodointendencia *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

void insertarTrabajador(Nodotrabajador **lista, trabajador t) {
    Nodotrabajador *nuevo = malloc(sizeof(Nodotrabajador));
    nuevo->dato = t;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        Nodotrabajador *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

void insertarEspecializacion(Nodoespecializacion **lista, especializacion es) {
    Nodoespecializacion *nuevo = malloc(sizeof(Nodoespecializacion));
    nuevo->dato = es;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
    } else {
        Nodoespecializacion *temp = *lista;
        while (temp->sig != *lista)
            temp = temp->sig;
        temp->sig = nuevo;
        nuevo->sig = *lista;
    }
}

// ==================== VER NODO POR NODO ====================

void verDoctoresNodo(NodoDoctor *lista, hospital h[]) {
    if (!lista) {
        printf("  (lista vacia)\n");
        return;
    }

    NodoDoctor *temp = lista;
    char tecla;

    do {
        printf("\n--- DOCTOR ---\n");
        printf("Nombre: %s\n", temp->dato.nombre);
        printf("Edad: %d\n", temp->dato.edad);
        printf("Especialidad: %s\n", temp->dato.especializacion);
        printf("Hospital: %s\n", h[temp->dato.idHospital].nombre);

        printf("\n[ENTER = siguiente | q = salir]: ");
        tecla = getchar();
        // limpiar lo extra del buffer
        while(getchar() != '\n');
        if(tecla == '\n'){   // ENTER
            temp = temp->sig;
        }
    } while(tecla != 'q' && tecla != 'Q');
}

void verPacientesNodo(NodoPaciente *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    NodoPaciente *temp = lista;
    int i = 1;
    char tecla;
    do {
        printf("\n  [Paciente #%d]\n", i++);
        printf("  Nombre      : %s\n", temp->dato.nombre);
        printf("  Edad        : %d\n", temp->dato.edad);
        printf("  Especialidad: %s\n", temp->dato.especializacion);
        printf("  Num paciente: %d\n", temp->dato.num_paciente);
        printf("  Num doctor  : %d\n", temp->dato.num_doctor);
        printf("  Hospital    : %s\n", h[temp->dato.idHospital].nombre);
        
        printf("\n[ENTER = siguiente | q = salir]: ");
        tecla = getchar();
        temp = temp->sig;
        if (temp != lista) {
            pausar();
        }
    } while (temp != lista);
}

void verEspecializacionesNodo(Nodoespecializacion *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodoespecializacion *temp = lista;
    int i = 1;
    do {
        printf("\n  [Especializacion #%d]\n", i++);
        printf("  Nombre    : %s\n", temp->dato.nombre);
        printf("  Doctores  : %d\n", temp->dato.cantidaddoc);
        printf("  Pacientes : %d\n", temp->dato.cantidapac);
        printf("  Hospital  : %s\n", h[temp->dato.idHospital].nombre);
        temp = temp->sig;
        if (temp != lista) {
            pausar();
        }
    } while (temp != lista);
}

void verIntendenciaNodo(Nodointendencia *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodointendencia *temp = lista;
    int i = 1;
    do {
        printf("\n  [Intendencia #%d]\n", i++);
        printf("  Nombre   : %s\n", temp->dato.nombre);
        printf("  Edad     : %d\n", temp->dato.edad);
        printf("  Numero   : %d\n", temp->dato.numero);
        printf("  Hospital : %s\n", h[temp->dato.idHospital].nombre);
        temp = temp->sig;
        if (temp != lista) {
            pausar();
        }
    } while (temp != lista);
}

void verTrabajadoresNodo(Nodotrabajador *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodotrabajador *temp = lista;
    int i = 1;
    do {
        printf("\n  [Trabajador #%d]\n", i++);
        printf("  Numero       : %d\n", temp->dato.numero);
        printf("  Sindicalizado: %s\n", temp->dato.sindicalizado);
        printf("  Hospital     : %s\n", h[temp->dato.idHospital].nombre);
        temp = temp->sig;
        if (temp != lista) {
            pausar();
        }
    } while (temp != lista);
}

void verEquipoNodo(NodoEquipo *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    NodoEquipo *temp = lista;
    int i = 1;
    do {
        printf("\n  [Equipo #%d]\n", i++);
        printf("  Nombre   : %s\n", temp->dato.nombre);
        printf("  Marca    : %s\n", temp->dato.marca);
        printf("  Modelo   : %s\n", temp->dato.modelo);
        printf("  Hospital : %s\n", h[temp->dato.idHospital].nombre);
        temp = temp->sig;
        if (temp != lista) {
            pausar();
        }
    } while (temp != lista);
}

// ==================== LLENADO ====================

void llenar_hospital(hospital *h) {
    printf("Nombre hospital: ");
    fgets(h->nombre, 30, stdin);
    h->nombre[strcspn(h->nombre, "\n")] = '\0';

    printf("Direccion: ");
    fgets(h->direccion, 40, stdin);
    h->direccion[strcspn(h->direccion, "\n")] = '\0';
}

void llenar_doctor(doctor *d, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&d->idHospital);

    printf("Nombre: ");
    fgets(d->nombre, 30, stdin);
    d->nombre[strcspn(d->nombre, "\n")] = '\0';

    printf("Edad: ");
    leerEntero(&d->edad);

    printf("Especializacion: ");
    fgets(d->especializacion, 40, stdin);
    d->especializacion[strcspn(d->especializacion, "\n")] = '\0';

    d->num_trabajador = rand() % 900 + 100;
}

void llenar_paciente(paciente *p, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&p->idHospital);

    printf("Nombre: ");
    fgets(p->nombre, 30, stdin);
    p->nombre[strcspn(p->nombre, "\n")] = '\0';

    printf("Edad: ");
    leerEntero(&p->edad);

    printf("Especializacion: ");
    fgets(p->especializacion, 40, stdin);
    p->especializacion[strcspn(p->especializacion, "\n")] = '\0';

    p->num_paciente = rand() % 900 + 100;

    printf("Numero doctor: ");
    leerEntero(&p->num_doctor);
}

void llenar_equipo(equipomed *e, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&e->idHospital);

    printf("Nombre: ");
    fgets(e->nombre, 30, stdin);
    e->nombre[strcspn(e->nombre, "\n")] = '\0';

    printf("Marca: ");
    fgets(e->marca, 30, stdin);
    e->marca[strcspn(e->marca, "\n")] = '\0';

    printf("Modelo: ");
    fgets(e->modelo, 30, stdin);
    e->modelo[strcspn(e->modelo, "\n")] = '\0';
}

void llenar_intendencia(intendencia *in, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&in->idHospital);

    printf("Nombre: ");
    fgets(in->nombre, 30, stdin);
    in->nombre[strcspn(in->nombre, "\n")] = '\0';

    printf("Edad: ");
    leerEntero(&in->edad);

    printf("Numero: ");
    leerEntero(&in->numero);
}

void llenar_especializacion(especializacion *es, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&es->idHospital);

    printf("Nombre de la Especializacion: ");
    fgets(es->nombre, 30, stdin);
    es->nombre[strcspn(es->nombre, "\n")] = '\0';

    printf("Cantidad de doctores: ");
    leerEntero(&es->cantidaddoc);

    printf("Cantidad de pacientes a cargo: ");
    leerEntero(&es->cantidapac);
}

void llenar_trabajador(trabajador *t, int th) {
    printf("ID Hospital (0 a %d): ", th - 1);
    leerEntero(&t->idHospital);

    printf("Numero: ");
    leerEntero(&t->numero);

    printf("Sindicalizado? (si/no): ");
    fgets(t->sindicalizado, 3, stdin);
    t->sindicalizado[strcspn(t->sindicalizado, "\n")] = '\0';
    limpiarBuffer();
}

// ==================== MAIN ====================

int main() {
    srand(time(NULL));

    hospital h[MAX];
    int th = 0;

    NodoDoctor       *ld  = NULL;
    NodoPaciente     *lp  = NULL;
    Nodoespecializacion *les = NULL;
    Nodointendencia  *li  = NULL;
    Nodotrabajador   *lt  = NULL;
    NodoEquipo       *le  = NULL;

    int op, sub;

    do {
        printf("\n1. Ingresar datos\n");
        printf("2. Ver  nodo\n");
        printf("3. Ver Nodo por Nodo\n");
        printf("4.Salir\n");
        printf("Opcion: ");
        leerEntero(&op);

        switch (op) {

            case 1:
                do {
                    printf("\n--- Ingresar datos ---\n");
                    printf("1. Hospital");
                    if (th > 0)
                        printf("  [%d registrado(s)]\n", th);
                    else
                        printf("  <-- empieza aqui\n");

                    if (th == 0) {
                        printf("2. Doctor         (necesita hospital)\n");
                        printf("3. Paciente       (necesita hospital)\n");
                        printf("4. Especializacion(necesita hospital)\n");
                        printf("5. Intendencia    (necesita hospital)\n");
                        printf("6. Trabajadores   (necesita hospital)\n");
                        printf("7. Equipo Medico  (necesita hospital)\n");
                    } else {
                        printf("2. Doctor\n");
                        printf("3. Paciente\n");
                        printf("4. Especializacion\n");
                        printf("5. Intendencia\n");
                        printf("6. Trabajadores\n");
                        printf("7. Equipo Medico\n");
                    }
                    printf("8. Salir\n");
                    printf("Opcion: ");
                    leerEntero(&sub);

                    if (sub >= 2 && sub <= 7 && th == 0) {
                        printf("  Primero registra al menos un hospital (opcion 1).\n");
                        continue;
                    }

                    switch (sub) {
                        case 1:
                            llenar_hospital(&h[th++]);
                            break;

                        case 2: {
                            doctor d;
                            llenar_doctor(&d, th);
                            insertarDoctor(&ld, d);
                        } break;

                        case 3: {
                            paciente p;
                            llenar_paciente(&p, th);
                            insertarPaciente(&lp, p);
                        } break;

                        case 4: {
                            especializacion es;
                            llenar_especializacion(&es, th);
                            insertarEspecializacion(&les, es);
                        } break;

                        case 5: {
                            intendencia in;
                            llenar_intendencia(&in, th);
                            insertarIntendencia(&li, in);
                        } break;

                        case 6: {
                            trabajador t;
                            llenar_trabajador(&t, th);
                            insertarTrabajador(&lt, t);
                        } break;

                        case 7: {
                            equipomed e;
                            llenar_equipo(&e, th);
                            insertarEquipo(&le, e);
                        } break;
                    }

                } while (sub != 8);
                break;

            case 2:
        do{
        printf("\n--- VISUALIZAR ---\n");
        printf("1. Doctores\n");
        printf("2. Pacientes\n");
        printf("3. Especializaciones\n");
        printf("4. Intendencia\n");
        printf("5. Trabajadores\n");
        printf("6. Equipo medico\n");
        printf("7. Salir\n");
        printf("Opcion: ");
        leerEntero(&sub);

        switch(sub){
            case 1:
                printf("\n=== DOCTORES ===\n");
                verDoctoresNodo(ld, h);
                break;

            case 2:
                printf("\n=== PACIENTES ===\n");
                verPacientesNodo(lp, h);
                break;

            case 3:
                printf("\n=== ESPECIALIZACIONES ===\n");
                verEspecializacionesNodo(les, h);
                break;

            case 4:
                printf("\n=== INTENDENCIA ===\n");
                verIntendenciaNodo(li, h);
                break;

            case 5:
                printf("\n=== TRABAJADORES ===\n");
                verTrabajadoresNodo(lt, h);
                break;

            case 6:
                printf("\n=== EQUIPO MEDICO ===\n");
                verEquipoNodo(le, h);
                break;
             }

             }while(sub != 7);
              break;
              
        case 3:
        limpiarBuffer();
        verTodoNodoPorNodo(ld, lp, les, li, lt, le, h);
        break;
        }
        

    } while (op != 4);

    return 0;
}
