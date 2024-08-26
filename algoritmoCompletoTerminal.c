// Mateus Moraes de Moura 2019027100
//Leonardo Carvalho de Matos Silva 2019037591

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Para medir o tempo de execução

// Algoritmo de Euclides recursivo
int mdcRecursive(int a, int b) {
    if (b == 0) return a;
    return mdcRecursive(b, a % b);
}

// Algoritmo de Euclides iterativo
int mdcIterative(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Algoritmo de Stein (Binary GCD Algorithm)
int gcdStein(int a, int b) {
    if (a == b)
        return a;
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (~a & 1) // a é par
        if (b & 1) // b é ímpar
            return gcdStein(a >> 1, b);
        else // a e b são pares
            return gcdStein(a >> 1, b >> 1) << 1;
    if (~b & 1) // a é ímpar e b é par
        return gcdStein(a, b >> 1);
    if (a > b)
        return gcdStein((a - b) >> 1, b);
    return gcdStein((b - a) >> 1, a);
}

int main() {
    int a, b;
    char choice;

    do {
        printf("Digite dois numeros inteiros para calcular o MDC (separados por espaco): ");
        scanf("%d %d", &a, &b);

        clock_t start, end;
        double timeRecursive, timeIterative, timeStein;

        // Medindo o tempo do Algoritmo de Euclides Recursivo
        start = clock();
        int resultRecursive = mdcRecursive(a, b);
        end = clock();
        timeRecursive = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Medindo o tempo do Algoritmo de Euclides Iterativo
        start = clock();
        int resultIterative = mdcIterative(a, b);
        end = clock();
        timeIterative = ((double) (end - start)) / CLOCKS_PER_SEC;

        // Medindo o tempo do Algoritmo de Stein
        start = clock();
        int resultStein = gcdStein(a, b);
        end = clock();
        timeStein = ((double) (end - start)) / CLOCKS_PER_SEC;

        printf("Resultados para (%d, %d):\n", a, b);
        printf("MDC Recursivo: %d, Tempo: %f segundos\n", resultRecursive, timeRecursive);
        printf("MDC Iterativo: %d, Tempo: %f segundos\n", resultIterative, timeIterative);
        printf("MDC Stein: %d, Tempo: %f segundos\n", resultStein, timeStein);

        printf("\nDeseja calcular o MDC para outros numeros? (s/n): ");
        scanf(" %c", &choice);

    } while (choice == 's' || choice == 'S');

    printf("Programa encerrado.\n");
    return 0;
}
