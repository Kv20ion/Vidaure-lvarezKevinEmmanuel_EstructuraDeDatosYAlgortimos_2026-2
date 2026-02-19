/*Primer ejercicio de la práctica 1:
    -En el siguiente código se declararán:
        *Arreglos lineales de datos primitivos tales que deberán tener una longitud de entre 7 y 20 espacios
        *Arreglos matriciales de datos primitivos tales que deberán tener una cantidad ya sea de filas o columnas 
        que no sea menor a 3. Además la multiplicación de la cantidad de filas por la cantidad de columnas deberá
        ser menor a 40*/
/*Importación de la biblioteca "stdio.h" para intrucciones básicas de entrada y salida de datos y declaración 
de constantes*/
#include<stdio.h>
#define tam 15
#define filas 6
#define columnas 4

//Declaración de las funciones a emplear
void llenar_enteros_lineales();
void llenar_flotantes_lineales();
void llenar_caracteres_lineales();

void llenar_enteros_matriciales();
void llenar_flotantes_matriciales();
void llenar_caracteres_matriciales();

void imprimir_enteros_lineales();
void imprimir_flotantes_lineales();
void imprimir_caracteres_lineales();

void imprimir_enteros_matriciales();
void imprimir_flotantes_matriciales();
void imprimir_caracteres_matriciales();

//Declaración de la funcion principal "main"
int main(){
    //Declaración de arreglos lineales y matriciales
    int enteros_lineal[tam];
    int enteros_matricial[filas][columnas];
    float flotantes_lineal[tam];
    float flotantes_matricial[filas][columnas];
    char caracteres_lineal[tam];
    char caracteres_matricial[filas][columnas];
    
    //Llenado de arreglos lineales
    llenar_enteros_lineales(enteros_lineal);
    llenar_flotantes_lineales(flotantes_lineal);
    llenar_caracteres_lineales(caracteres_lineal);

    //Llenado de arreglos matriciales
    llenar_enteros_matriciales(enteros_matricial);
    llenar_flotantes_matriciales(flotantes_matricial);
    llenar_caracteres_matriciales(caracteres_matricial);

    //Impresión de arreglos lineales
    imprimir_enteros_lineales(enteros_lineal);
    imprimir_flotantes_lineales(flotantes_lineal);
    imprimir_caracteres_lineales(caracteres_lineal);

    //Impresión de arreglos matriciales
    imprimir_enteros_matriciales(enteros_matricial);
    imprimir_flotantes_matriciales(flotantes_matricial);
    imprimir_caracteres_matriciales(caracteres_matricial);
    return 0;
}

//Función para el llenado del arreglo lineal de enteros
void llenar_enteros_lineales(int arr[]){
    printf("\n LLENADO DE ARREGLO LINEAL DE ENTEROS \n");
    for (int i = 0; i < tam; i++){
        printf("Ingrese un valor para el índice [%d]: ",i);
        scanf("%d",&arr[i]);
    }
}

//Función para el llenado del arreglo lineal de flotantes
void llenar_flotantes_lineales(float arr[]){
    printf("\n LLENADO DE ARREGLO LINEAL DE FLOTANTES \n");
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese un valor para el índice [%d]: ",i);
        scanf("%f",&arr[i]);
    }  
}

//Función para el llenado del arreglo lineal de caracteres
void llenar_caracteres_lineales(char arr[]){
    printf("\n LLENADO DE ARREGLO LINEAL DE CARACTERES \n");
    for (int i = 0; i < tam; i++)
    {
        printf("Ingrese un carácter para el índice [%d]: ",i);
        scanf(" %c",&arr[i]);
    }
    
}


//Función para el llenado del arreglo matricial de enteros
void llenar_enteros_matriciales(int arr[filas][columnas]){
    printf("\n LLENADO DE ARREGLO MATRICIAL DE ENTEROS \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese un valor para el índice [%d][%d]: ",i,j);
            scanf("%d",&arr[i][j]);
        }
        
    }
}

//Función para el llenado del arreglo matricial de flotantes
void llenar_flotantes_matriciales(float arr[filas][columnas]){
    printf("\n LLENADO DE ARREGLO MATRICIAL DE FLOTANTES \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese un valor para el índice [%d][%d]: ",i,j);
            scanf("%f",&arr[i][j]);
        }
        
    }
}

//Función para el llenado del arreglo matricial de caracteres
void llenar_caracteres_matriciales(char arr[filas][columnas]){
    printf("\n LLENADO DE ARREGLO MATRICIAL DE CARACTERES\n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("Ingrese un caracter para el índice [%d][%d]: ",i,j);
            scanf(" %c",&arr[i][j]);
        }
        
    }
}

//Función para la impresión del arreglo lineal de enteros
void imprimir_enteros_lineales(int arr[]){
    printf("\n ARREGLO LINEAL DE ENTEROS \n");
    printf("Indice\tValor\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t%d\n",i,arr[i]);
    }
}

//Función para la impresión del arreglo lineal de flotantes
void imprimir_flotantes_lineales(float arr[]){
    printf("\n ARREGLO LINEAL DE FLOTANTES \n");
    printf("Indice\tValor\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t %.2f\n",i,arr[i]);
    }
}

//Función para la impresión del arreglo lineal de caracteres
void imprimir_caracteres_lineales(char arr[]){
    printf("\n ARREGLO LINEAL DE CARACTERES \n");
    printf("Indice\tCaracter\n");
    for (int i = 0; i < tam; i++)
    {
        printf("%d\t%c\n",i,arr[i]);
    }
    
}

//Función para la impresión del arreglo matrcial de enteros
void imprimir_enteros_matriciales(int arr[filas][columnas]){
    printf("\n ARREGLO MATRICIAL DE ENTEROS \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

//Función para la impresión del arreglo matricial de flotantes
void imprimir_flotantes_matriciales(float arr[filas][columnas]){
    printf("\n ARREGLO MATRICIAL DE FLOTANTES \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%.2f ",arr[i][j]);
        }
        printf("\n");
    }
}

//Función para la impresión del arreglo matricial de caracteres
void imprimir_caracteres_matriciales(char arr[filas][columnas]){
    printf("\n ARREGLO MATRICIAL DE CARACTERES \n");
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            printf("%c ",arr[i][j]);
        }
        printf("\n");
    }
}
