#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int **MATRIZ;  // Matriz dinamica
    int m, renglon, columna;  // Variables para el tamaño de la matriz y para los ciclos
    int SUMA_PRINCIPAL = 0, SUMA_SECUNDARIA = 0;  // Variables para almacenar las sumas de las diagonales
						  
						  

// Función para mostrar la matriz
void mostrarMatriz(int **MATRIZ, int m) {
    printf("\nMatriz ingresada (%d x %d):\n", m, m); //Tamano matriz
    for (int renglon = 0; renglon < m; renglon++) {  // Recorre las filas
        for (int columna = 0; columna < m; columna++) {  // Recorre las columnas
            printf("%d ", MATRIZ[renglon][columna]);  // Muestra cada valor de la matriz
        }
        printf("\n");  
    }
}

    // Solicitar el tamaño de la matriz
    printf("Introduce el tamaño de la matriz cuadrada: ");
    if (scanf("%d", &m) != 1) {  // Verifica si la entrada es válida
        printf("Error: Entrada inválida.\n");
        return 1;  // Termina el programa si la entrada es inválida
    }

    // Verificar que el tamaño de la matriz sea mayor que 0
    if (m <= 0) {  // Condición para evitar una matriz de tamaño no válido
        printf("Error: El tamaño de la matriz debe ser mayor que 0\n");
        return 1;  // Termina el programa si el tamaño es inválido
    }

    // Asignación dinámica de memoria para la matriz
    MATRIZ = (int **)malloc(m * sizeof(int *));  // Reserva memoria para las filas
    if (MATRIZ == NULL) {  // Verifica si la asignación fue exitosa
        printf("Error: No se pudo asignar memoria para la matriz.\n");
        return 1;  // Termina el programa si no se puede asignar memoria
    }

    for (renglon = 0; renglon < m; renglon++) {  // Asigna memoria para cada fila
        MATRIZ[renglon] = (int *)malloc(m * sizeof(int));  // Reserva memoria para las columnas
        if (MATRIZ[renglon] == NULL) {  // Verifica si la asignación fue exitosa
            printf("Error: No se pudo asignar memoria para la fila %d.\n", renglon);
            return 1;  // Termina el programa si no se puede asignar memoria para una fila
        }
    }

    // Inicialización de la matriz
    printf("Introduce los elementos de la matriz (%d x %d):\n", m, m);  // Solicita los elementos de la matriz
    for (renglon = 0; renglon < m; renglon++) {  // Recorre las filas
        for (columna = 0; columna < m; columna++) {  // Recorre las columnas
            printf("Introduce el elemento [%d][%d]: ", renglon + 1, columna + 1);  // Solicita cada elemento de la matriz
            if (scanf("%d", &MATRIZ[renglon][columna]) != 1) {  // Verifica si la entrada es válida
                printf("Error: Entrada inválida.\n");
                return 1;  // Termina el programa si la entrada es inválida
            }
        }
    }

    // Mostrar la matriz ingresada
    mostrarMatriz(MATRIZ, m);  // 

    // Cálculo de la suma de las diagonales principal y secundaria
    for (renglon = 0; renglon < m; renglon++) {  // Recorre las filas para sumar las diagonales
        SUMA_PRINCIPAL += MATRIZ[renglon][renglon];  // Suma la diagonal principal
        SUMA_SECUNDARIA += MATRIZ[renglon][m - 1 - renglon];  // Suma la diagonal secundaria
    }

    // Mostrar los resultados
    printf("Suma de la diagonal principal: %d\n", SUMA_PRINCIPAL);  
    printf("Suma de la diagonal secundaria: %d\n", SUMA_SECUNDARIA);  

    // Liberar la memoria asignada dinámicamente
    for (renglon = 0; renglon < m; renglon++) {  
        free(MATRIZ[renglon]);
    }
    free(MATRIZ);  

    return 0;  
}

