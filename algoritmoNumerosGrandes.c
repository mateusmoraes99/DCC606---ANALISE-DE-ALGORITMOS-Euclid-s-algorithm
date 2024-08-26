#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gmp.h> // Biblioteca GMP

// Algoritmo de Euclides recursivo usando GMP
void mdcRecursive(mpz_t result, const mpz_t a, const mpz_t b) {
    if (mpz_cmp_ui(b, 0) == 0) {
        mpz_set(result, a);
        return;
    }
    mpz_t temp;
    mpz_init(temp);
    mpz_mod(temp, a, b);
    mdcRecursive(result, b, temp);
    mpz_clear(temp);
}

// Algoritmo de Euclides iterativo usando GMP
void mdcIterative(mpz_t result, mpz_t a, mpz_t b) {
    mpz_t r;
    mpz_init(r);
    while (mpz_cmp_ui(b, 0) != 0) {
        mpz_mod(r, a, b);
        mpz_set(a, b);
        mpz_set(b, r);
    }
    mpz_set(result, a);
    mpz_clear(r);
}

// Algoritmo de Stein (Binary GCD Algorithm) usando GMP
void gcdStein(mpz_t result, const mpz_t a, const mpz_t b) {
    if (mpz_cmp(a, b) == 0) {
        mpz_set(result, a);
        return;
    }
    if (mpz_cmp_ui(a, 0) == 0) {
        mpz_set(result, b);
        return;
    }
    if (mpz_cmp_ui(b, 0) == 0) {
        mpz_set(result, a);
        return;
    }

    mpz_t a_shifted, b_shifted;
    mpz_init(a_shifted);
    mpz_init(b_shifted);

    if (mpz_even_p(a) && mpz_even_p(b)) {
        mpz_fdiv_q_2exp(a_shifted, a, 1);
        mpz_fdiv_q_2exp(b_shifted, b, 1);
        gcdStein(result, a_shifted, b_shifted);
        mpz_mul_2exp(result, result, 1);
    } else if (mpz_even_p(a)) {
        mpz_fdiv_q_2exp(a_shifted, a, 1);
        gcdStein(result, a_shifted, b);
    } else if (mpz_even_p(b)) {
        mpz_fdiv_q_2exp(b_shifted, b, 1);
        gcdStein(result, a, b_shifted);
    } else if (mpz_cmp(a, b) > 0) {
        mpz_sub(a_shifted, a, b);
        mpz_fdiv_q_2exp(a_shifted, a_shifted, 1);
        gcdStein(result, a_shifted, b);
    } else {
        mpz_sub(b_shifted, b, a);
        mpz_fdiv_q_2exp(b_shifted, b_shifted, 1);
        gcdStein(result, a, b_shifted);
    }

    mpz_clear(a_shifted);
    mpz_clear(b_shifted);
}

int main() {
    mpz_t a, b, resultRecursive, resultIterative, resultStein;
    mpz_inits(a, b, resultRecursive, resultIterative, resultStein, NULL);
    char choice;

    do {
        printf("Digite dois numeros inteiros para calcular o MDC (separados por espaco): ");
        gmp_scanf("%Zd %Zd", a, b);

        clock_t start, end;
        double timeRecursive, timeIterative, timeStein;

        // Medindo o tempo do Algoritmo de Euclides Recursivo
        start = clock();
        mdcRecursive(resultRecursive, a, b);
        end = clock();
        timeRecursive = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medindo o tempo do Algoritmo de Euclides Iterativo
        start = clock();
        mdcIterative(resultIterative, a, b);
        end = clock();
        timeIterative = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Medindo o tempo do Algoritmo de Stein
        start = clock();
        gcdStein(resultStein, a, b);
        end = clock();
        timeStein = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("Resultados para os numeros fornecidos:\n");
        gmp_printf("MDC Recursivo: %Zd, Tempo: %f segundos\n", resultRecursive, timeRecursive);
        gmp_printf("MDC Iterativo: %Zd, Tempo: %f segundos\n", resultIterative, timeIterative);
        gmp_printf("MDC Stein: %Zd, Tempo: %f segundos\n", resultStein, timeStein);

        printf("\nDeseja calcular o MDC para outros numeros? (s/n): ");
        scanf(" %c", &choice);

    } while (choice == 's' || choice == 'S');

    printf("Programa encerrado.\n");

    // Liberando memória alocada para números grandes
    mpz_clears(a, b, resultRecursive, resultIterative, resultStein, NULL);
    return 0;
}
