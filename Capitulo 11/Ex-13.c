/* 13) Escreva um programa que leia um inteiro N e crie uma matriz alocada
dinamicamente contendo N linhas e N colunas. Essa matriz deve conter o valor 0
na diagonal principal, o valor 1 nos elementos acima da diagonal principal e o
valor −1 nos elementos abaixo da diagonal principal. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int **matriz = NULL,
          N = 0;

    while (N <= 0) {
        printf("Informe o tamanho da matriz quadrada: ");
        scanf("%d", &N);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    matriz = malloc(sizeof *matriz * N);

    if (matriz == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    matriz[0] = malloc(sizeof **matriz * N * N);

    if (matriz[0] == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        matriz[i] = matriz[0] + i * N;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                matriz[i][j] = -1;
            } else if (j == i) {
                matriz[i][j] = 0;
            } else {
                matriz[i][j] = 1;
            }
        }
    }

    printf("\nMatriz:\n\n");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", matriz[i][j]);
        }
        printf("\n");
    }

    free(matriz[0]);
    free(matriz);

    matriz = NULL;

    return 0;
}
