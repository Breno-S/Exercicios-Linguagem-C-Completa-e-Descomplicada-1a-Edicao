/* 5) Escreva uma função que calcule o desvio-padrão d de um vetor V contendo n
números em que m é a média desse vetor. */

#include <stdio.h>
#include <math.h>

// Tamanho da amostra
#define N 10

double desvio_padrao(double *amostra, size_t tamanho) {
    double  m = 0,
            somatorio_quadrados_desvios = 0;

    // Calcula o valor esperado (que neste caso é a média da amostra)
    for (int i = 0; i < tamanho; i++) {
        m += amostra[i];
    }

    m /= tamanho;

    // Calcula o somatório do quadrado dos desvios
    for (int i = 0; i < tamanho; i++) {
        somatorio_quadrados_desvios += pow(amostra[i] - m, 2);
    }

    // Resultado do desvio padrão amostral (raiz quadrada da variância amostral)
    return sqrt(somatorio_quadrados_desvios / (tamanho - 1));
}

int main() {
    double  amostra[N];

    printf("Informe a amostra para calcular seu desvio padrao\n\n");

    for (size_t i = 0; i < N; i++) {
        printf("[%d]: ", i);
        scanf("%lf", &amostra[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nDesvio Padrao: %lf ", desvio_padrao(amostra, N));
}
