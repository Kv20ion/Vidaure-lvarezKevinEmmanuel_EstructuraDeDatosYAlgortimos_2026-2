/*
 * ESTRUCTURA DE DATOS Y ALGORITMOS I
 *
 * PRACTICA 3: HOSPITAL
 *
 * OBJETIVO:
 * El siguiente programa corresponde a la práctica 3
 * de la materia EDA I. El tema que se aborda es el
 * de estructuras en el lenguaje de programación C.
 * Con el fin de poner en práctica los conocimientos
 * adquiridos, se diseñará un programa que con la
 * ayuda de las estructuras, pueda hacer la gestión
 * de los datos de un hospital. Los datos abordan:
 *
 * - Datos del hospital
 * - Datos de los pacientes
 * - Datos de los doctores
 *
 * BRIGADA 1:
 * - CASTELAN SIERRA GAEL
 * - ESPINOSA SALVADOR ROMAN
 * - MALDONADO MARTINEZ ERICK FERNANDO
 * - VIDAURE ÁLVAREZ KEVIN EMMANUEL
 *
 */

// Bibliotecas a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estructura Hospital
typedef struct hospital
{
    char nombre[30];
    char direccion[40];
} hospital;

// Estructura Doctor
typedef struct doctor
{
    char nombre[30];
    int edad;
    char especializacion[40];
    int num_trabajador;
    hospital Hospital;
} doctor;

// Estructura Paciente
typedef struct paciente
{
    char nombre[30];
    int edad;
    char especializacion[40];
    hospital Hospital;
    int num_paciente;
    int num_doctor;
} paciente;

// Declaración de funciones
void llenar_hospital(hospital *Hospital);
void llenar_doctor(doctor *Doctor);
void llenar_paciente(paciente *Paciente, doctor Doctor, hospital Hospital);

// Llenar hospital
void llenar_hospital(hospital *Hospital)
{
    int valido, i;

    // Nombre del hospital (solo letras y espacios)
    do
    {
        valido = 1;
        printf("\nIngrese el nombre del Hospital: ");
        fgets(Hospital->nombre, sizeof(Hospital->nombre), stdin);
        Hospital->nombre[strcspn(Hospital->nombre, "\n")] = '\0';

        if (strlen(Hospital->nombre) == 0)
            valido = 0;

        for (i = 0; i < strlen(Hospital->nombre); i++)
        {
            if (!((Hospital->nombre[i] >= 'A' && Hospital->nombre[i] <= 'Z') ||
                  (Hospital->nombre[i] >= 'a' && Hospital->nombre[i] <= 'z') ||
                  Hospital->nombre[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras y espacios.\n");

    } while (!valido);

    // Dirección del hospital (letras, números y espacios)
    do
    {
        valido = 1;
        printf("Ingrese la direccion del hospital: ");
        fgets(Hospital->direccion, sizeof(Hospital->direccion), stdin);
        Hospital->direccion[strcspn(Hospital->direccion, "\n")] = '\0';

        if (strlen(Hospital->direccion) == 0)
            valido = 0;

        for (i = 0; i < strlen(Hospital->direccion); i++)
        {
            if (!((Hospital->direccion[i] >= 'A' && Hospital->direccion[i] <= 'Z') ||
                  (Hospital->direccion[i] >= 'a' && Hospital->direccion[i] <= 'z') ||
                  (Hospital->direccion[i] >= '0' && Hospital->direccion[i] <= '9') ||
                  Hospital->direccion[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras, numeros y espacios.\n");

    } while (!valido);
}

// Llenar doctor
void llenar_doctor(doctor *Doctor)
{
    // Variables a utilizar
    int disponible, valido, i;

    // Nombre (solo letras y espacios)
    do
    {
        valido = 1;
        printf("\nIngresa el nombre del doctor: ");
        fgets(Doctor->nombre, sizeof(Doctor->nombre), stdin);
        Doctor->nombre[strcspn(Doctor->nombre, "\n")] = '\0';

        if (strlen(Doctor->nombre) == 0)
            valido = 0;

        for (i = 0; i < strlen(Doctor->nombre); i++)
        {
            if (!((Doctor->nombre[i] >= 'A' && Doctor->nombre[i] <= 'Z') ||
                  (Doctor->nombre[i] >= 'a' && Doctor->nombre[i] <= 'z') ||
                  Doctor->nombre[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras y espacios.\n");

    } while (!valido);

    // Edad (solo números positivos)
    do
    {
        printf("Ingresa la edad del doctor: ");
        valido = scanf("%d", &Doctor->edad);
        while (getchar() != '\n'); // limpiar buffer

        if (valido != 1 || Doctor->edad <= 0)
            printf("Error: Ingresa una edad valida.\n");

    } while (valido != 1 || Doctor->edad <= 0);

    // Especialización (solo letras y espacios)
    do
    {
        valido = 1;
        printf("Ingresa la especializacion: ");
        fgets(Doctor->especializacion, sizeof(Doctor->especializacion), stdin);
        Doctor->especializacion[strcspn(Doctor->especializacion, "\n")] = '\0';

        if (strlen(Doctor->especializacion) == 0)
            valido = 0;

        for (i = 0; i < strlen(Doctor->especializacion); i++)
        {
            if (!((Doctor->especializacion[i] >= 'A' && Doctor->especializacion[i] <= 'Z') ||
                  (Doctor->especializacion[i] >= 'a' && Doctor->especializacion[i] <= 'z') ||
                  Doctor->especializacion[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras y espacios.\n");

    } while (!valido);

    // Numeros de doctor disponibles
    print("---- Numeros de trabajador disponible ----\n");
    for (int i = 0; i < 3; i++)
    {
        srand(time(NULL));
        disponible = rand() % 111 + 100;
        disponible += i;
        printf("Numero %d disponible: %d\n", i + 1, disponible);
    }

    // Número de trabajador (solo positivo)
    do
    {
        printf("Ingresa el numero de trabajador: ");
        valido = scanf("%d", &Doctor->num_trabajador);
        while (getchar() != '\n');

        if (valido != 1 || Doctor->num_trabajador <= 0)
            printf("Error: Numero invalido.\n");

    } while (valido != 1 || Doctor->num_trabajador <= 0);
}

// Llenar paciente
void llenar_paciente(paciente *Paciente, doctor Doctor, hospital Hospital)
{
    int valido, i;

    // Nombre (solo letras y espacios)
    do
    {
        valido = 1;
        printf("\nIngresa el nombre del paciente: ");
        fgets(Paciente->nombre, sizeof(Paciente->nombre), stdin);
        Paciente->nombre[strcspn(Paciente->nombre, "\n")] = '\0';

        if (strlen(Paciente->nombre) == 0)
            valido = 0;

        for (i = 0; i < strlen(Paciente->nombre); i++)
        {
            if (!((Paciente->nombre[i] >= 'A' && Paciente->nombre[i] <= 'Z') ||
                  (Paciente->nombre[i] >= 'a' && Paciente->nombre[i] <= 'z') ||
                  Paciente->nombre[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras y espacios.\n");

    } while (!valido);

    // Edad (solo números positivos)
    do
    {
        printf("Ingresa la edad del paciente: ");
        valido = scanf("%d", &Paciente->edad);
        while (getchar() != '\n');

        if (valido != 1 || Paciente->edad <= 0)
            printf("Error: Ingresa una edad valida.\n");

    } while (valido != 1 || Paciente->edad <= 0);

    // Especialización requerida (solo letras y espacios)
    do
    {
        valido = 1;
        printf("Ingresa la especializacion requerida: ");
        fgets(Paciente->especializacion, sizeof(Paciente->especializacion), stdin);
        Paciente->especializacion[strcspn(Paciente->especializacion, "\n")] = '\0';

        if (strlen(Paciente->especializacion) == 0)
            valido = 0;

        for (i = 0; i < strlen(Paciente->especializacion); i++)
        {
            if (!((Paciente->especializacion[i] >= 'A' && Paciente->especializacion[i] <= 'Z') ||
                  (Paciente->especializacion[i] >= 'a' && Paciente->especializacion[i] <= 'z') ||
                  Paciente->especializacion[i] == ' '))
            {
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("Error: Solo letras y espacios.\n");

    } while (!valido);

    // Número de paciente (positivo)
    do
    {
        printf("Ingresa el numero de paciente: ");
        valido = scanf("%d", &Paciente->num_paciente);
        while (getchar() != '\n');

        if (valido != 1 || Paciente->num_paciente <= 0)
            printf("Error: Numero invalido.\n");

    } while (valido != 1 || Paciente->num_paciente <= 0);

    // Asignar automáticamente el número de doctor y el hospital
    Paciente->num_doctor = Doctor.num_trabajador;
    Paciente->Hospital = Hospital;
}

// Main
int main()
{
    hospital Hospital;
    doctor Doctor;
    paciente Paciente;

    int opcion = 0, blindaje = 0;
    int opcion1 = 0, blindaje1 = 0;

    do
    {
        printf("\n--- MENU PRINCIPAL ---\n");
        printf("1.- Ingresar Datos\n");
        printf("2.- Visualizar Datos\n");
        printf("3.- Salir\n");
        printf("Ingrese una opcion: ");
        blindaje = scanf("%i", &opcion);
        while (getchar() != '\n'); // Limpiar buffer

        if (blindaje != 1 || opcion < 1 || opcion > 3)
        {
            printf("ERROR. OPCION NO VALIDA.\n");
            continue;
        }

        switch (opcion)
        {
            case 1: // Agregar datos (submenú)
                do
                {
                    printf("\n--- SUBMENU ---\n");
                    printf("1.- Agregar datos del hospital\n");
                    printf("2.- Agregar datos del doctor\n");
                    printf("3.- Agregar datos del paciente\n");
                    printf("4.- Salir al menu principal\n");
                    printf("Ingrese una opcion: ");
                    blindaje1 = scanf("%i", &opcion1);
                    while (getchar() != '\n');

                    if (blindaje1 != 1 || opcion1 < 1 || opcion1 > 4)
                    {
                        printf("ERROR. OPCION NO VALIDA.\n");
                        continue;
                    }

                    switch (opcion1)
                    {
                        case 1:
                            llenar_hospital(&Hospital);
                            break;
                        case 2:
                            llenar_doctor(&Doctor);
                            break;
                        case 3:
                            llenar_paciente(&Paciente, Doctor, Hospital);
                            break;
                        case 4:
                            // Salir del submenú
                            break;
                        default:
                            printf("ERROR. OPCION NO VALIDA.\n");
                            break;
                    }
                } while (opcion1 != 4);
                break;

            case 2: // Visualizar datos
                printf("\n\n--- DATOS REGISTRADOS ---\n");
                printf("\nHospital: %s", Hospital.nombre);
                printf("\nDireccion: %s", Hospital.direccion);

                printf("\n\nDoctor: %s", Doctor.nombre);
                printf("\nEdad: %d", Doctor.edad);
                printf("\nEspecializacion: %s", Doctor.especializacion);
                printf("\nNumero trabajador: %d", Doctor.num_trabajador);

                printf("\n\nPaciente: %s", Paciente.nombre);
                printf("\nEdad: %d", Paciente.edad);
                printf("\nEspecializacion requerida: %s", Paciente.especializacion);
                printf("\nNumero paciente: %d", Paciente.num_paciente);
                printf("\nDoctor asignado: %d\n", Paciente.num_doctor);
                break;

            case 3: // Salir del programa
                opcion = 3; // Para que el bucle termine
                break;

            default:
                printf("ERROR. OPCION NO VALIDA.\n");
                break;
        }
    } while (opcion != 3);

    return 0;
}
