// Mateus Moraes de Moura 2019027100
//Leonardo Carvalho de Matos Silva 2019037591

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // Inclui a biblioteca para medir o tempo de execução

// Função para calcular o MDC usando o Algoritmo de Euclides recursivo
int mdcRecursive(int a, int b) {
    if (b == 0) return a;  // Caso base: se b é 0, o MDC é a
    return mdcRecursive(b, a % b);  // Chamada recursiva trocando a e b, e usando o resto de a/b
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
    double timeRecursive;  // Variável para armazenar o tempo médio de execução
    int numExecutions = 5;  // Número de vezes que cada teste será executado para obter a média

    // Loop para percorrer cada par de entradas
    for (int i = 0; i < 5; i++) {
        int a = inputs[i][0];  // Pega o valor de a do par atual
        int b = inputs[i][1];  // Pega o valor de b do par atual

        // Inicializa o acumulador de tempo para o algoritmo
        double totalTimeRecursive = 0.0;

        // Executa o algoritmo numExecutions vezes para calcular a média do tempo
        for (int j = 0; j < numExecutions; j++) {
            // Medindo o tempo do Algoritmo de Euclides Recursivo
            start = clock();  // Marca o tempo de início
            mdcRecursive(a, b);  // Executa o algoritmo
            end = clock();  // Marca o tempo de término
            totalTimeRecursive += ((double) (end - start)) / CLOCKS_PER_SEC;  // Calcula o tempo gasto e acumula
        }

        // Calcula a média dos tempos
        timeRecursive = totalTimeRecursive / numExecutions;

        // Imprime os resultados para o par de entradas atual
        printf("Inputs: (%d, %d)\n", a, b);
        printf("Average Recursive Euclid Time: %0.10f seconds\n", timeRecursive);
    }

    return 0;  // Indica que o programa terminou com sucesso
}
