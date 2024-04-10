/* 5) Faça um programa que leia um valor inteiro N não negativo. Se o valor de
N for inválido, o usuário deverá digitar outro até que ele seja válido (ou seja,
positivo). Em seguida, leia um vetor V contendo N posições de inteiros, em que
cada valor deverá ser maior ou igual a 2. Esse vetor deverá ser alocado
dinamicamente. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *V = NULL,
         N = -1;

    while (N <= 0) {
        printf("Informe um tamanho para o vetor de numeros inteiros: ");
        scanf("%d", &N);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    V = calloc(N, sizeof *V);

    if (V == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    printf("\nInforme os valores do vetor (maiores ou iguais a 2):\n\n");

    for (int i = 0; i < N; i++) {
        printf("[%d]: ", i);
        scanf("%d", &V[i]);

        if (V[i] < 2) {
            printf("\nValor invalido, insira outro valor.\n\n");
            i--;
        }
    }

    printf("\nVetor final:\n\n");

    for (int i = 0; i < N; i++) {
        printf("%d ", V[i]);
    }

    free(V);
    V = NULL;

    return 0;
}
