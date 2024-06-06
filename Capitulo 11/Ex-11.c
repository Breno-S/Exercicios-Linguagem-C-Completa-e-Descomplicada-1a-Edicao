/* 11) Escreva uma função que receba como parâmetro um valor N e retorne o
ponteiro para uma matriz alocada dinamicamente contendo N linhas e N colunas.
Essa matriz deve conter o valor 1 na diagonal principal e 0 nas demais posições.
*/

#include <stdio.h>
#include <stdlib.h>

// Retorna um ponteiro para um array bidimensional de tamanho NxN.
int **heap_matriz_quad_int(unsigned N);

// Preenche a diagonal principal de uma matriz quadrada com 1 e zera o restante.
void diagonal_principal_fill(int *matriz, unsigned N);

// Libera a memória alocada pela função `heap_matriz_quad_int()`.
void free_matriz(int **matriz);

int main() {
    int **matriz = NULL,
          tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho da matriz quadrada: ");
        scanf("%d", &tamanho);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    matriz = heap_matriz_quad_int(tamanho);

    if (matriz == NULL) {
        printf("\nErro: memoria insuficiente\n");
        return 1;
    }

    printf("\nMatriz:\n\n");

    for (unsigned i = 0; i < tamanho; i++) {
        for (unsigned j = 0; j < tamanho; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    free_matriz(matriz);
    matriz = NULL;

    return 0;
}

int **heap_matriz_quad_int(unsigned N) {
    int **matriz = NULL;

    matriz = malloc(sizeof *matriz * N);

    if (matriz != NULL) {
        matriz[0] = malloc(sizeof **matriz * N * N);

        if (matriz[0] != NULL) {
            for (size_t i = 1; i < N; i++) {
                matriz[i] = matriz[0] + i * N;
            }
        }

        diagonal_principal_fill(*matriz, N);
    }

    return matriz;
}

void diagonal_principal_fill(int *matriz, unsigned N) {
    for (unsigned i = 0; i < N; i++) {
        for (unsigned j = 0; j < N; j++) {
            if (i == j) {
                matriz[i * N + j] = 1;
            } else {
                matriz[i * N + j] = 0;
            }
        }
    }
}

void free_matriz(int **matriz) {
    free(matriz[0]);
    free(matriz);
}