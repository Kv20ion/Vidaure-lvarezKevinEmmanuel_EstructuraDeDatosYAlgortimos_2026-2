/*Tarea 1: Ejercicio 1
El siguiente código emula el funcionamiento de una calculadora de la siguiente manera:
El usuario ingresa 2 números que se almacenan en 2 variables de tipo double, estos serán los valores con los que
se realizarán las operaciones. Estas variables son asignadas a dos apuntadores del mismo tipo double.

Posteriormente se muestra un menú que despliega las operaciones disponibles. El menú se encuentra dentro de un ciclo do-while
de manera que este se imprima hasta que el usuario ingrese la opción específica para salir. Por otro lado, las demás opciones
del menú ejecutan su función correspondiente.

Cada operación matemática es llevada a cabo por una función que recibe en su parametro el valor asociado a cada apuntador, 
realiza su operación matemática correspondiente con los valores recibidos y se imprime el resultado.
*/

//Declaración de la biblioteca a emplear
#include <stdio.h>

//Declaración de las funciones
void suma(double*, double*);
void resta(double*, double*);
void mult(double*, double*);
void div(double*, double*);
void mod(double*, double*);
void divEnt(double*, double*);
void limpiarBuffer();

//Funcion principal "main"
int main()
{
    //Declaración de variables
    char opcion;
    double num1, num2, *aptr1, *aptr2;

    printf("Ingrese los números a operar:\n");

    //Lectura del primer número
    printf("Primer número: ");
    while (scanf("%lf",&num1) != 1)
    {
        printf("Entrada inválida. Intente nuevamente: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    //Lectura del segundo número
    printf("Segundo número: ");
    while (scanf("%lf",&num2) != 1)
    {
        printf("Entrada inválida. Intente nuevamente: ");
        limpiarBuffer();
    }
    limpiarBuffer();

    //Asignación de apuntadores
    aptr1 = &num1;
    aptr2 = &num2;

    //Menú dentro de un ciclo do-while
    do
    {
        printf("\nElija una operación \n");
        printf("a) Suma \n");
        printf("b) Resta \n");
        printf("c) Multiplicación \n");
        printf("d) División \n");
        printf("e) Módulo \n");
        printf("f) División entera \n");
        printf("g) Salir\n");

        //Lectura de la opción
        if (scanf(" %c", &opcion) != 1)
        {
            printf("Entrada inválida.\n");
            limpiarBuffer();
            continue;
        }
        limpiarBuffer();

        switch (opcion)
        {
        case 'a':
        case 'A':
            suma(aptr1, aptr2);
            break;

        case 'b':
        case 'B':
            resta(aptr1, aptr2);
            break;

        case 'c':
        case 'C':
            mult(aptr1, aptr2);
            break;

        case 'd':
        case 'D':
            div(aptr1, aptr2);
            break;

        case 'e':
        case 'E':
            mod(aptr1, aptr2);
            break;

        case 'f':
        case 'F':
            divEnt(aptr1, aptr2);
            break;

        case 'g':
        case 'G':
            printf("Saliendo de la calculadora...\n");
            break;

        default:
            printf("Expresión no válida, ingrese una de las opciones\n");
            break;
        }

    } while (opcion != 'g' && opcion != 'G');

    return 0;
}

//Función para limpiar el buffer usando scanf
void limpiarBuffer()
{
    scanf("%*[^\n]");
    scanf("%*c");
}

//Funcion para la operación suma
void suma(double *aptr1, double *aptr2)
{
    double suma = (*aptr1 + *aptr2);
    printf("\nLa suma de %.2f y %.2f es: %.2f\n", *aptr1, *aptr2, suma);
}

//Función para la operación resta
void resta(double *aptr1,double *aptr2)
{
    double resta = (*aptr1 - *aptr2);
    printf("\nLa resta de %.2f y %.2f es: %.2f\n", *aptr1, *aptr2, resta);
}

//Función para la operación multiplicación
void mult(double *aptr1,double *aptr2)
{
    double mult = ((*aptr1) * (*aptr2));
    printf("\nLa multiplicación de %.2f y %.2f es: %.2f\n", *aptr1, *aptr2, mult);
}

//Función para la operación división
void div(double *aptr1,double *aptr2)
{
    if (*aptr2 == 0)
    {
        printf("Error: No se puede dividir entre cero.\n");
        return;
    }

    double division = (*aptr1 / *aptr2);
    printf("\nLa división de %.2f y %.2f es: %.2f\n", *aptr1, *aptr2, division);
}

//Función para la operación módulo
void mod(double *aptr1, double *aptr2)
{
    int val1 = *aptr1;
    int val2 = *aptr2;

    if (val2 == 0)
    {
        printf("Error: No se puede realizar módulo entre cero.\n");
        return;
    }

    int mod = (val1 % val2);
    printf("El resultado del módulo entre %d y %d es: %d\n", val1, val2, mod);
}

//Función para la operación división entera
void divEnt(double *aptr1,double*aptr2)
{
    int val1 = *aptr1;
    int val2 = *aptr2;

    if (val2 == 0)
    {
        printf("Error: No se puede dividir entre cero.\n");
        return;
    }

    int divEnt = val1 / val2;
    printf("El resultado de la división entera entre %d y %d es: %d\n", val1, val2, divEnt);
}
