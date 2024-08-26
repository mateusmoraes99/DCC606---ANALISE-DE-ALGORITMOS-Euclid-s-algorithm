# DCC606---ANALISE-DE-ALGORITMOS-Euclid-s-algorithm

# Algoritmos de Cálculo do Máximo Divisor Comum (MDC)

## Descrição
Este projeto inclui uma implementação em C de três algoritmos para calcular o Máximo Divisor Comum (MDC) de dois números inteiros. O código fornece uma comparação entre o Algoritmo de Euclides Recursivo, o Algoritmo de Euclides Iterativo e o Algoritmo de Stein (Binary GCD) em termos de tempo de execução. As medições são realizadas para diferentes pares de valores, e o tempo médio de execução de cada algoritmo é exibido.

## Algoritmos Implementados

### Algoritmo de Euclides Recursivo

#### Função: mdcRecursive(int a, int b)
   Descrição: Calcula o MDC utilizando o método recursivo do Algoritmo de Euclides. Se b é 0, o MDC é a. Caso contrário, a 
   função é chamada recursivamente com b e o resto da divisão de a por b.

    int mdcRecursive(int a, int b) {
        if (b == 0) return a;
        return mdcRecursive(b, a % b);
    }
### Algoritmo de Euclides Iterativo

  Função: mdcIterative(int a, int b)
  Descrição: Calcula o MDC utilizando o método iterativo do Algoritmo de Euclides. O processo continua até que b se torne 0, momento em que a contém o MDC.

    int mdcIterative(int a, int b) {
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
### Algoritmo de Stein (Binary GCD)

   Função: gcdStein(int a, int b)
   Descrição: Calcula o MDC utilizando o Algoritmo de Stein, que é baseado em operações bit a bit. A função trata diferentes 
   casos baseados na paridade dos números a e b, e continua o cálculo até que a e b sejam iguais ou um deles seja 0.

    int gcdStein(int a, int b) {
        if (a == b) return a;
        if (a == 0) return b;
        if (b == 0) return a;
        if (~a & 1) {
            if (b & 1) return gcdStein(a >> 1, b);
            else return gcdStein(a >> 1, b >> 1) << 1;
       }
        if (~b & 1) return gcdStein(a, b >> 1);
        if (a > b) return gcdStein((a - b) >> 1, b);
        return gcdStein((b - a) >> 1, a);
    }
## Medição do Tempo de Execução
   O código mede o tempo de execução de cada algoritmo utilizando a biblioteca time.h. Para cada par de valores de entrada, 
   cada algoritmo é executado várias vezes (5 vezes por padrão) e o tempo médio é calculado.

## Estrutura do Código
  ### Declaração das Entradas
   Um array de pares de inteiros é definido para testar os algoritmos.

  ### Medição do Tempo
   O tempo de início e fim é registrado para cada execução dos algoritmos, e o tempo total é acumulado para calcular a média.

### Impressão dos Resultados
O tempo médio de execução para cada algoritmo é impresso para cada par de valores.

Execução
Para compilar e executar o código, siga os seguintes passos:

## Compilar
    gcc -o algoritmoCompletoTerminal algoritmoCompletoTerminal.c

## Executar
    ./algoritmoCompletoTerminal

O programa exibirá o tempo médio de execução de cada algoritmo para os pares de valores fornecidos.
### obs 
para funcinnalidade do arquivo algoritmoMelhorado.c necessario intalação da sequinte biblioteca no terminal linux.
     
            sudo apt-get update
            sudo apt-get install libgmp-dev
 Para instalar e usar GMP no Windows, o processo é um pouco diferente:
 Use o MinGW-w64 ou MSYS2:
 Se você estiver usando o MinGW-w64 ou MSYS2, pode instalar a GMP através do pacman.
 Instale o MSYS2 a partir do site oficial.
 Abra o terminal MSYS2 e execute:


    pacman -S mingw-w64-x86_64-gmp           
