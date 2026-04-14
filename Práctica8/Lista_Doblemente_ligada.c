/*
ESTRUCTURA DE DATOS Y ALGORITMOS I

PRACTICA 8: CODIGO CON LISTA DOBLEMENTE LIGADA CIRCULAR

OBJETIVO:

El siguiente programa corresponde a la practica 3
de la materia EDA I. El tema que se aborda es el
de estructuras en el lenguaje de programacion C.
Con el fin de poner en practica los conocimientos
adquiridos, se disenara un programa que con la
ayuda de las estructuras, y las listas doblemente ligadas pueda hacer la gestion
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
VIDAURE ALVAREZ KEVIN EMMANUEL

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
    struct NodoDoctor *ant;
} NodoDoctor;

typedef struct NodoPaciente {
    paciente dato;
    struct NodoPaciente *sig;
    struct NodoPaciente *ant;
} NodoPaciente;

typedef struct NodoEquipo {
    equipomed dato;
    struct NodoEquipo *sig;
    struct NodoEquipo *ant;
} NodoEquipo;

typedef struct NodoIntendencia {
    intendencia dato;
    struct NodoIntendencia *sig;
    struct NodoIntendencia *ant;
} Nodointendencia;

typedef struct Nodotrabajador {
    trabajador dato;
    struct Nodotrabajador *sig;
    struct Nodotrabajador *ant;
} Nodotrabajador;

typedef struct Nodoespecializacion {
    especializacion dato;
    struct Nodoespecializacion *sig;
    struct Nodoespecializacion *ant;
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

            // intentar convertir a numero
            if(sscanf(buffer, "%d", n) == 1 && *n >= 0){
                return 1; // valido
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

// ==================== VER NODO POR NODO ====================

void verTodoNodoPorNodo(
    NodoDoctor *ld,
    NodoPaciente *lp,
    Nodoespecializacion *les,
    Nodointendencia *li,
    Nodotrabajador *lt,
    NodoEquipo *le,
    hospital h[]
){
    // Punteros actuales para cada categoria (comienzan desde la cabeza)
    NodoDoctor *d_curr = ld;
    NodoPaciente *p_curr = lp;
    Nodoespecializacion *e_curr = les;
    Nodointendencia *i_curr = li;
    Nodotrabajador *t_curr = lt;
    NodoEquipo *eq_curr = le;

    // Determinar la primera categoria no vacia
    int cat = 1;  // 1:Doctor, 2:Paciente, 3:Especializacion, 4:Intendencia, 5:Trabajador, 6:Equipo
    // Funcion auxiliar para saltar categorias vacias
    while (cat <= 6) {
        if (cat == 1 && d_curr) break;
        if (cat == 2 && p_curr) break;
        if (cat == 3 && e_curr) break;
        if (cat == 4 && i_curr) break;
        if (cat == 5 && t_curr) break;
        if (cat == 6 && eq_curr) break;
        cat++;
    }
    if (cat > 6) {
        printf("No hay datos en ninguna categoria.\n");
        return;
    }

    char tecla;
    do {
        printf("\n===============================\n");
        // Mostrar el nodo actual segun la categoria
        switch(cat) {
            case 1: // Doctor
                if (d_curr) {
                    printf("DOCTOR\n");
                    printf("Nombre: %s\n", d_curr->dato.nombre);
                    printf("Hospital: %s\n", h[d_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay doctores en esta categoria.\n");
                }
                break;
            case 2: // Paciente
                if (p_curr) {
                    printf("PACIENTE\n");
                    printf("Nombre: %s\n", p_curr->dato.nombre);
                    printf("Hospital: %s\n", h[p_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay pacientes en esta categoria.\n");
                }
                break;
            case 3: // Especializacion
                if (e_curr) {
                    printf("ESPECIALIZACION\n");
                    printf("Nombre: %s\n", e_curr->dato.nombre);
                    printf("Hospital: %s\n", h[e_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay especializaciones en esta categoria.\n");
                }
                break;
            case 4: // Intendencia
                if (i_curr) {
                    printf("INTENDENCIA\n");
                    printf("Nombre: %s\n", i_curr->dato.nombre);
                    printf("Hospital: %s\n", h[i_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay personal de intendencia en esta categoria.\n");
                }
                break;
            case 5: // Trabajador
                if (t_curr) {
                    printf("TRABAJADOR\n");
                    printf("Numero: %d\n", t_curr->dato.numero);
                    printf("Hospital: %s\n", h[t_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay trabajadores en esta categoria.\n");
                }
                break;
            case 6: // Equipo
                if (eq_curr) {
                    printf("EQUIPO\n");
                    printf("Nombre: %s\n", eq_curr->dato.nombre);
                    printf("Hospital: %s\n", h[eq_curr->dato.idHospital].nombre);
                } else {
                    printf("No hay equipos medicos en esta categoria.\n");
                }
                break;
        }

        printf("\n[ENTER = siguiente nodo | a = anterior nodo | s = sig categoria | b = ant categoria | q = salir]: ");
        tecla = getchar();
        while(getchar() != '\n'); // limpiar buffer

        switch(tecla) {
            case '\n':  // Avanzar al siguiente nodo de la misma categoria
                switch(cat) {
                    case 1: if(d_curr) d_curr = d_curr->sig; break;
                    case 2: if(p_curr) p_curr = p_curr->sig; break;
                    case 3: if(e_curr) e_curr = e_curr->sig; break;
                    case 4: if(i_curr) i_curr = i_curr->sig; break;
                    case 5: if(t_curr) t_curr = t_curr->sig; break;
                    case 6: if(eq_curr) eq_curr = eq_curr->sig; break;
                }
                break;

            case 'a': case 'A': // Retroceder al nodo anterior de la misma categoria
                switch(cat) {
                    case 1: if(d_curr) d_curr = d_curr->ant; break;
                    case 2: if(p_curr) p_curr = p_curr->ant; break;
                    case 3: if(e_curr) e_curr = e_curr->ant; break;
                    case 4: if(i_curr) i_curr = i_curr->ant; break;
                    case 5: if(t_curr) t_curr = t_curr->ant; break;
                    case 6: if(eq_curr) eq_curr = eq_curr->ant; break;
                }
                break;

            case 's': case 'S': // Siguiente categoria (ciclica)
                do {
                    cat = (cat % 6) + 1;
                } while ( (cat == 1 && !d_curr) ||
                          (cat == 2 && !p_curr) ||
                          (cat == 3 && !e_curr) ||
                          (cat == 4 && !i_curr) ||
                          (cat == 5 && !t_curr) ||
                          (cat == 6 && !eq_curr) );
                break;

            case 'b': case 'B': // Categoria anterior (ciclica)
                do {
                    cat = (cat == 1) ? 6 : cat - 1;
                } while ( (cat == 1 && !d_curr) ||
                          (cat == 2 && !p_curr) ||
                          (cat == 3 && !e_curr) ||
                          (cat == 4 && !i_curr) ||
                          (cat == 5 && !t_curr) ||
                          (cat == 6 && !eq_curr) );
                break;
        }
    } while(tecla != 'q' && tecla != 'Q');
}

// ==================== INSERTAR ====================

void insertarDoctor(NodoDoctor **lista, doctor d) {
    NodoDoctor *nuevo = malloc(sizeof(NodoDoctor));
    nuevo->dato = d;
     if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        NodoDoctor *ultimo = (*lista)->ant;

        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

void insertarPaciente(NodoPaciente **lista, paciente p) {
    NodoPaciente *nuevo = malloc(sizeof(NodoPaciente));
    nuevo->dato = p;
    if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        NodoPaciente *ultimo = (*lista)->ant;
        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

void insertarEquipo(NodoEquipo **lista, equipomed e) {
    NodoEquipo *nuevo = malloc(sizeof(NodoEquipo));
    nuevo->dato = e;
     if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        NodoEquipo *ultimo = (*lista)->ant;
        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

void insertarIntendencia(Nodointendencia **lista, intendencia in) {
    Nodointendencia *nuevo = malloc(sizeof(Nodointendencia));
    nuevo->dato = in;
     if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        Nodointendencia *ultimo = (*lista)->ant;
        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

void insertarTrabajador(Nodotrabajador **lista, trabajador t) {
    Nodotrabajador *nuevo = malloc(sizeof(Nodotrabajador));
    nuevo->dato = t;
     if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        Nodotrabajador *ultimo = (*lista)->ant;
        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

void insertarEspecializacion(Nodoespecializacion **lista, especializacion es) {
    Nodoespecializacion *nuevo = malloc(sizeof(Nodoespecializacion));
    nuevo->dato = es;
     if (*lista == NULL) {
        *lista = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        Nodoespecializacion *ultimo = (*lista)->ant;
        nuevo->sig = *lista;
        nuevo->ant = ultimo;

        ultimo->sig = nuevo;
        (*lista)->ant = nuevo;
    }
}

// ==================== VER NODO POR NODO (INDIVIDUAL) ====================

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

       printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
       tecla = getchar();
       while(getchar() != '\n');
       if(tecla == '\n'){
       temp = temp->sig;   // siguiente
       }
       else if(tecla == 'a' || tecla == 'A'){
       temp = temp->ant;   // anterior
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
        
        printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
         while(getchar() != '\n'); // limpiar buffer
         tecla = getchar();

        if(tecla == '\n'){
            temp = temp->sig;
        }
        else if(tecla == 'a' || tecla == 'A'){
            temp = temp->ant;
        }

    } while(tecla != 'q' && tecla != 'Q');
    }


void verEspecializacionesNodo(Nodoespecializacion *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodoespecializacion *temp = lista;
    int i = 1;
    char tecla;
    do {
        printf("\n  [Especializacion #%d]\n", i++);
        printf("  Nombre    : %s\n", temp->dato.nombre);
        printf("  Doctores  : %d\n", temp->dato.cantidaddoc);
        printf("  Pacientes : %d\n", temp->dato.cantidapac);
        printf("  Hospital  : %s\n", h[temp->dato.idHospital].nombre);
        printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
       tecla = getchar();
       while(getchar() != '\n');
       if(tecla == '\n'){
       temp = temp->sig;   // siguiente
       }
       else if(tecla == 'a' || tecla == 'A'){
       temp = temp->ant;   
       }
    } while(tecla != 'q' && tecla != 'Q');
}

void verIntendenciaNodo(Nodointendencia *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodointendencia *temp = lista;
    int i = 1;
    char tecla;
    do {
        printf("\n  [Intendencia #%d]\n", i++);
        printf("  Nombre   : %s\n", temp->dato.nombre);
        printf("  Edad     : %d\n", temp->dato.edad);
        printf("  Numero   : %d\n", temp->dato.numero);
        printf("  Hospital : %s\n", h[temp->dato.idHospital].nombre);
         printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
       tecla = getchar();
       while(getchar() != '\n');
       if(tecla == '\n'){
       temp = temp->sig;   // siguiente
       }
       else if(tecla == 'a' || tecla == 'A'){
       temp = temp->ant;   // doble enlace
       }
    } while(tecla != 'q' && tecla != 'Q');
}

void verTrabajadoresNodo(Nodotrabajador *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    Nodotrabajador *temp = lista;
    char tecla;
    int i = 1;
    do {
        printf("\n  [Trabajador #%d]\n", i++);
        printf("  Numero       : %d\n", temp->dato.numero);
        printf("  Sindicalizado: %s\n", temp->dato.sindicalizado);
        printf("  Hospital     : %s\n", h[temp->dato.idHospital].nombre);
         printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
       tecla = getchar();
       while(getchar() != '\n');
       if(tecla == '\n'){
       temp = temp->sig;   // siguiente
       }
       else if(tecla == 'a' || tecla == 'A'){
       temp = temp->ant;   // doble enlace
       }
    } while(tecla != 'q' && tecla != 'Q');
}

void verEquipoNodo(NodoEquipo *lista, hospital h[]) {
    if (!lista) { printf("  (lista vacia)\n"); return; }
    NodoEquipo *temp = lista;
    int i = 1;
    char tecla;
    do {
        printf("\n  [Equipo #%d]\n", i++);
        printf("  Nombre   : %s\n", temp->dato.nombre);
        printf("  Marca    : %s\n", temp->dato.marca);
        printf("  Modelo   : %s\n", temp->dato.modelo);
        printf("  Hospital : %s\n", h[temp->dato.idHospital].nombre);
         printf("\n[ENTER = siguiente | a = anterior | q = salir]: ");
       tecla = getchar();
       while(getchar() != '\n');
       if(tecla == '\n'){
       temp = temp->sig;   // siguiente
       }
       else if(tecla == 'a' || tecla == 'A'){
       temp = temp->ant;   // doble enlace
       }
    } while(tecla != 'q' && tecla != 'Q');
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
        printf("2. Ver nodo\n");
        printf("3. Ver Nodo por Nodo\n");
        printf("4. Salir\n");
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

                } while(sub != 7);
                break;
              
            case 3:
                limpiarBuffer();
                verTodoNodoPorNodo(ld, lp, les, li, lt, le, h);
                break;
        }

    } while (op != 4);

    return 0;
}
