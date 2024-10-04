#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4  // Puedes cambiar este valor para matrices de diferentes tamaños

// Función para encontrar la secuencia más larga de 1s consecutivos en la matriz
int MayorLinea(int matriz[SIZE][SIZE]) {
    int masLarga = 0; // Para almacenar la secuencia más larga de 1s
    int actual = 0;   // Contador de 1s consecutivos

    for (int i = 0; i < SIZE; i++) {  // recorrer filas
        for (int j = 0; j < SIZE; j++) {  // recorrer columnas
            if (matriz[i][j] == 1) {
                actual++;  // incrementar contador si encontramos un 1
            } else {
                masLarga = (actual > masLarga) ? actual : masLarga;  // actualizar la secuencia más larga
                actual = 0;  // reiniciar el contador si encontramos un 0
            }
        }
        
        // Si el último elemento de la fila es 0, reiniciar el contador
        if (matriz[i][SIZE - 1] == 0) {
            masLarga = (actual > masLarga) ? actual : masLarga;
            actual = 0;  // Reiniciar el contador si termina en 0
        }
    }

    // Asegurarse de que la última secuencia se cuente
    masLarga = (actual > masLarga) ? actual : masLarga;

    return masLarga;
}

// Función para llenar la matriz de manera aleatoria con 0s y 1s
void llenarMatrizAleatoriamente(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matriz[i][j] = rand() % 2;  // Llenar con 0 o 1 aleatoriamente
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(int matriz[SIZE][SIZE]) {
    printf("La matriz utilizada corresponde a:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matriz[SIZE][SIZE];

    // Inicializar la semilla para números aleatorios
    srand(time(0));

    // Llenar la matriz de manera aleatoria
    llenarMatrizAleatoriamente(matriz);

    // Imprimir la matriz generada
    imprimirMatriz(matriz);

    // Encontrar la secuencia más larga de 1s consecutivos
    int mayorLinea = MayorLinea(matriz);

    // Imprimir el resultado
    printf("El tamaño de la secuencia de 1s más grande es: %d\n", mayorLinea);

    return 0;
}

