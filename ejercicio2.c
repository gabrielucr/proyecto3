#include <stdio.h>

int factorial(int n) {
    int i = 1;
    while (n > 0) {
        i = i * n;
        n--; // Corregido: simplemente restar 1 a n
    }
    return i;
}

int main(int argc, char *argv[]) {
    int num;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);  // Leemos el número ingresado por el usuario
    
    int fac = factorial(num);
    printf("¡El factorial de %d es %d!\n", num, fac);  // Mostramos el resultado
    return 0;
}


