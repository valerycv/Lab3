#include <stdio.h>

// Función para calcular el factorial
long long int factorial(int n) {
    long long int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Ingrese un número para calcular su factorial: ");
    scanf("%d", &num);

    // Para números negativos
    if (num < 0) {
        printf("El factorial no está definido para números negativos.\n");
    } else if (num > 20) {
        printf("El número es demasiado grande para ser calculado con precisión.\n");
    } else {
        long long int result = factorial(num);
        printf("%d! = %lld\n", num, result);  // 
    }

    return 0;
}

