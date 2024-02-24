/* 14) Faça um programa que calcule o desvio-padrão d de um vetor V contendo n
números em que m é a média desse vetor. Considere n = 10. O vetor v deve ser
lido do teclado. */

/* 
Escolhi o desvio padrão amostral já que estamos lidando com um array de tamanho
10. Para transformar em desvio padrão populacional basta dividir por `tamanho` 
ao invés de `tamanho-1`.
*/

#include <stdio.h>
#include <math.h>

// Tamanho da amostra
#define N 10

int main() {
    double  amostra[N],
            d,  // desvio padrão
            m = 0,  //media
            somatorio_quadrados_desvios = 0;

    printf("Informe a amostra para calcular seu desvio padrao\n\n");

    for (size_t i = 0; i < N; i++) {
        printf("[%d]: ", i);
        scanf("%lf", &amostra[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    // Calcula o valor esperado (que neste caso é a média da amostra)
    for (int i = 0; i < N; i++) {
        m += amostra[i];
    }

    m /= N;

    // Calcula o somatório do quadrado dos desvios
    for (int i = 0; i < N; i++) {
        somatorio_quadrados_desvios += pow(amostra[i] - m, 2);
    }

    // Resultado do desvio padrão amostral (raiz quadrada da variância amostral)
    d = sqrt(somatorio_quadrados_desvios / (N - 1));

    printf("\nDesvio Padrao: %lf ", d);
}
