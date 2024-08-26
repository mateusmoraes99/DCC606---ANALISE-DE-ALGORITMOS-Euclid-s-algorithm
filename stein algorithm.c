// Mateus Moraes de Moura 2019027100
//Leonardo Carvalho de Matos Silva 2019037591

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Inclui a biblioteca para medir o tempo de execução

// Função para calcular o MDC usando o Algoritmo de Stein (Binary GCD)
int gcdStein(int a, int b) {
    if (a == b)  // Se a e b são iguais, o MDC é a ou b
        return a;
    if (a == 0)  // Se a é 0, o MDC é b
        return b;
    if (b == 0)  // Se b é 0, o MDC é a
        return a;
    if (~a & 1)  // Se a é par
        if (b & 1)  // E b é ímpar
            return gcdStein(a >> 1, b);  // Divide a por 2 e mantém b
        else  // Se a e b são pares
            return gcdStein(a >> 1, b >> 1) << 1;  // Divide ambos por 2 e multiplica o resultado por 2
    if (~b & 1)  // Se a é ímpar e b é par
        return gcdStein(a, b >> 1);  // Mantém a e divide b por 2
    if (a > b)  // Se a é maior que b
        return gcdStein((a - b) >> 1, b);  // Subtrai b de a, divide por 2 e chama recursivamente
    return gcdStein((b - a) >> 1, a);  // Subtrai a de b, divide por 2 e chama recursivamente
}

int main() {
    // Declaração das entradas a serem testadas (pares de valores)
    int inputs[5][2] = {
        {270, 192}, 
        {1071, 462}, 
        {123456, 789012}, 
        {987654, 321098}, 
        {567890, 123456} // Duas novas entradas
    };
    clock_t start, end;  // Variáveis para armazenar o tempo de início e fim da medição
    double timeStein;  // Variável para armazenar o tempo médio de execução
    int numExecutions = 5;  // Número de vezes que cada teste será executado para obter a média

    // Loop para percorrer cada par de entradas
    for (int i = 0; i < 5; i++) {
        int a = inputs[i][0];  // Pega o valor de a do par atual
        int b = inputs[i][1];  // Pega o valor de b do par atual

        // Inicializa o acumulador de tempo para o algoritmo
        double totalTimeStein = 0.0;

        // Executa o algoritmo numExecutions vezes para calcular a média do tempo
        for (int j = 0; j < numExecutions; j++) {
            // Medindo o tempo do Algoritmo de Stein
            start = clock();  // Marca o tempo de início
            gcdStein(a, b);  // Executa o algoritmo
            end = clock();  // Marca o tempo de término
            totalTimeStein += ((double) (end - start)) / CLOCKS_PER_SEC;  // Calcula o tempo gasto e acumula
        }

        // Calcula a média dos tempos
        timeStein = totalTimeStein / numExecutions;

        // Imprime os resultados para o par de entradas atual
        printf("Inputs: (%d, %d)\n", a, b);
        printf("Average Stein Algorithm Time: %0.10f seconds\n", timeStein);
    }

    return 0;  // Indica que o programa terminou com sucesso
}

