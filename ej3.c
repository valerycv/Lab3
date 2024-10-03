#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define DEFAULT_SIZE 5

// Función que encuentra el tamaño del cuadrado más grande
int findLargestSquare(int matrix[][MAX_SIZE], int n) {
    int largest = 0;
    int dp[MAX_SIZE][MAX_SIZE] = {0};

    // Inicializa la primera fila y columna de la matriz auxiliar
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = matrix[i][j];
            } else if (matrix[i][j] == 1) {
                dp[i][j] = 1 + ((dp[i-1][j] < dp[i][j-1]) ? 
                               (dp[i-1][j] < dp[i-1][j-1] ? dp[i-1][j] : dp[i-1][j-1]) 
                               : (dp[i][j-1] < dp[i-1][j-1] ? dp[i][j-1] : dp[i-1][j-1]));
            }
            if (dp[i][j] > largest) {
                largest = dp[i][j];
            }
        }
    }
    return largest;
}

// Función que llena la matriz de manera aleatoria con 0 y 1
void fillMatrixRandomly(int matrix[][MAX_SIZE], int n) {
    srand(time(0));  // SE inicializa la semilla del generador aleatorio
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 2;  // Genera un número entre 0 y 1
        }
    }
}

// Función que imprime la matriz
void printMatrix(int matrix[][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    printf("Ingrese el numero de filas de la matriz nxn: ");
    scanf("%d", &n);

    // Se revisa que el número ingresado sea válido
    if (n < 1 || n > 10) {
        printf("Tamaño no válido. Se utilizará el tamaño por defecto: %d\n", DEFAULT_SIZE);
        n = DEFAULT_SIZE;
    }

    // Se comĺeta la matriz de manera aleatoria
    fillMatrixRandomly(matrix, n);

    // Imprime la matriz generada
    printf("La matriz utilizada corresponde a:\n");
    printMatrix(matrix, n);

    // Encuentra el tamaño del cuadrado más grande
    int largestSquare = findLargestSquare(matrix, n);
    printf("El tamano del cuadrado mas grande de unos es: %dx%d.\n", largestSquare, largestSquare);

    return 0;
}

