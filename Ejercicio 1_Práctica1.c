/*
 * PRACTICA 1 de EDA I: ARREGLOS
 * El objetivo de este programa es comprender el uso
 * de los arreglos para almacenar y manipular información
 * contenida.
 *
 * 12 de febrero del 2026
 *
 * Castelan Sierra Gael
 * Espinosa Salvador Roman
 * Maldonado Martinez Erick Fernando
 * Vidaure Alvarez Kevin Emmanuel
 */

// Declaración de las bibliotecas a emplear
#include <stdio.h>

// Declaración de funciones a emplear
void arreglos_enteros();
void arreglos_flotantes();
void arreglos_caracteres();

// Función principal: main
void main() {
	// Variables
	int caso = 0;
	
	// Menu de seleccion	
	do {
		printf("=== BIENVENIDO ===\n");
		printf("1. EJEMPLOS DE ARREGLOS CON ENTEROS\n");
		printf("2. EJEMPLOS DE ARREGLOS CON FLOTANTES\n");
		printf("3. EJEMPLOS DE ARREGLOS CON CARACTERES\n");
		printf("4. SALIR\n");
		printf("INGRESE SU OPCION: ");
		scanf(" %d", &caso);	

		switch(caso) {
			// ARREGLOS ENTEROS
			case 1:
				arreglos_enteros();
				break;
			// ARREGLOS FLOTANTES
			case 2:
				arreglos_flotantes();
				break;
			// ARREGLOS CON CARACTERES
			case 3:
				arreglos_caracteres();
				break;
			// SALIR
			case 4:
				printf("HASTA LUEGO\n");
				break;

			default:
				printf("ERROR. VUELVA A INTENTAR\n");
				break;
		}

	} while (caso != 4);

}

// Creación de las funciones a emplear

// ARREGLOS ENTEROS
void arreglos_enteros() {

	// Variables
	int enteros_uno[7] = {0}; // Arreglo Lineal
	int enteros_dos[2][5] = {0}; // Arreglo Matricial
	int enteros_tres[3][3][3] = {0}; // Arreglo tridimencional

	// ARREGLO LINEAL
	//
	// Llenar arreglo
	printf("=== EJEMPLO DE ARREGLO LINEAL ===\n");
	printf("ARREGLO DE 1x7\n");
	printf("INGRESE ENTEROS PARA LLENAR EL ARREGLO:\n");
	
	for(int i = 0; i < 7; i++) {
		printf("\tArreglo[%d]: ", i);
		scanf("%d", &enteros_uno[i]);
	}
	
	// Mostrar arreglo
	printf("DATOS QUE SE INGRESARON:\n");

	for(int i = 0; i < 7; i++) {
		printf("%d\t", enteros_uno[i]);
	}

	// ARREGLO MATRICIAL
	//
	// Llenar arreglo
	printf("\n=== EJEMPLO DE ARREGLO MATRICIAL ===\n");
	printf("ARREGLO DE 2x5\n");
	printf("INGRESE ENTEROS PARA LLENAR EL ARREGLO\n");
	
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("\tArreglo[%d][%d]: ", i, j);
			scanf("%d", &enteros_dos[i][j]);
		}
	}

	// Mostrar el arreglo
	printf("DATOS QUE SE INGRESARON:\n");

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%d\t", enteros_dos[i][j]);
		}
		printf("\n");
	}

}

// ARREGLOS FLOTANTES
void arreglos_flotantes() {
	// Variables
	float flotantes_uno[7] = {0}; // Arreglo Lineal
	float flotantes_dos[2][5] = {0}; // Arreglo Matricial

	// ARREGLO LINEAL
	//
	// Llenar arreglo
	printf("=== EJEMPLO DE ARREGLO LINEAL ===\n");
	printf("ARREGLO DE 1x7\n");
	printf("INGRESE REALES PARA LLENAR EL ARREGLO:\n");

	for(int i = 0; i < 7; i++) {
		printf("\tArreglo[%d]: ", i);
		scanf("%f", &flotantes_uno[i]);
	}

	// Mostrar el arreglo
	printf("DATOS QUE SE INGRESARON:\n");
	
	for(int i = 0; i < 7; i++) {
		printf("%f\t", flotantes_uno[i]);
	}

	// ARREGLO MATRICIAL
	//
	// Llenar arreglo
	printf("=== EJEMPLO DE ARREGLO MATRICIAL ===\n");
	printf("ARREGLO DE 2x5");
	printf("INGRESE REALES PARA LLENAR EL ARREGLO\n");

	for(int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			printf("\tArreglo[%d][%d]: ", i, j);
			scanf("%f", &flotantes_dos[i][j]);
		}
	}

	// Mostrar el arreglo
	printf("DATOS QUE SE INGRESARON:\n");

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%f\t", flotantes_dos[i][j]);
		}
		printf("\n");
	}
}

// ARREGLOS CON CARACTERES
void arreglos_caracteres() {
	// Variables
	char caracteres_uno[7] = {0};
	char caracteres_dos[2][5] = {0};

	// ARREGLO LINEAL
	//
	// Llenar arreglo
	printf("=== EJEMPLO DE ARREGLO LINEAL ===\n");
	printf("ARREGLO DE 1x7\n");
	printf("Ingrese SOLAMENTE UN CARACTER para llenar el arreglo:\n");
	
	for(int i = 0; i < 7; i++) {
		printf("\tArreglo[%d]: ", i);
		scanf(" %c", &caracteres_uno[i]);
	}

	// Mostrar el arreglo
	printf("DATOS QUE SE INGRESARON:\n");

	for(int i = 0; i < 7; i++) {
		printf("%c\t", caracteres_uno[i]);
	}

	// ARREGLO MATRICIAL
	//
	// Llenar arreglo
	printf("\n=== EJEMPLO DE ARREGLO MATRICIAL ===\n");
	printf("ARREGLO DE 2x5\n");
	printf("Ingrese SOLAMENTE UN CARACTER para llenar el arreglo:\n");

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("\tArreglo[%d][%d]: ", i, j);
			scanf(" %c", &caracteres_dos[i][j]);
		}
	}

	// Mostrar el arreglo
	printf("DATOS QUE SE INGRESARON:\n");

	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%c\t", caracteres_dos[i][j]);
		}
		printf("\n");
	}
}
