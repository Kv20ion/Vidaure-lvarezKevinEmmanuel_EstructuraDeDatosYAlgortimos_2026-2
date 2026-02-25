/*Tarea 1: Ejercicio 2
El siguiente código realiza la función de almacenar las calificaciones de un grupo de 20 alumnos en un arreglo, calcular el promedio 
correspondiente a cada uno y el promedio general del grupo mediante la implementación del "paso por referencia".

El programa consta de tres funciones. Una para que el usuario ingrese la calificaciones de cada alumno, otra para calcular el promedio de
cada alumno y una última función para calcular el promedio de todo el grupo.
*/

//Declaración de biblioteca stdio.h y constantes para la longitud del arreglo
#include<stdio.h>
#define N 10
#define C 7

//Declaración de las funciones a emplear
void llenar(double*);
void promedio(double*, double*);
void promedio_grupo(double*);
void limpiarBuffer();

//Función principal "main"
int main(){

    //Declaración de los arreglos para las calificaciones de los alumnos, sus promedios
    double calificaciones[N][C], promedios[N];

    //Llamada de las funciones
    llenar(&calificaciones[0][0]);
    promedio(&calificaciones[0][0], promedios);
    promedio_grupo(promedios);

    return 0;
}

//Función para limpiar el buffer usando scanf
void limpiarBuffer()
{
    scanf("%*[^\n]");  // descarta todo hasta el salto de línea
    scanf("%*c");      // consume el '\n'
}

//Función para el llenado del arreglo de calificaciones
void llenar(double *arr){

    double calificacion;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < C; j++)
        {
            printf("Ingrese la calificación número %d del alumno %d (0-10): ", j+1, i+1);

            while (1)
            {
                if (scanf("%lf", &calificacion) != 1)
                {
                    printf("Entrada inválida. Intente nuevamente: ");
                    limpiarBuffer();
                }
                else if (calificacion < 0 || calificacion > 10)
                {
                    printf("La calificación debe estar entre 0 y 10. Intente nuevamente: ");
                    limpiarBuffer();
                }
                else
                {
                    *(arr + i*C + j) = calificacion;
                    limpiarBuffer();
                    break;
                }
            }
        }
    } 
}

//Función para el cálculo del promedio de cada alumno y su impresión
void promedio(double *arr,double *arr2){

    double suma;

    for (int i = 0; i < N; i++)
    {
        suma = 0;

        for (int j = 0; j < C; j++)
        {
            suma += *(arr + i*C + j);
        }

        *(arr2 + i) = suma / C;
    }

    for (int i = 0; i < N; i++)
    {
        printf("\nEl promedio del alumno %d es: %.2lf", i+1, *(arr2+i));
    }
}

//Función para el cálculo del promedio de todo el grupo y su impresión
void promedio_grupo(double *arr2){

    double suma = 0, promedio_general;

    for (int i = 0; i < N; i++)
    {
        suma += *(arr2 + i);
    }

    promedio_general = suma / N;
    
    printf("\nEl promedio general del grupo es: %.2lf\n", promedio_general);
}
