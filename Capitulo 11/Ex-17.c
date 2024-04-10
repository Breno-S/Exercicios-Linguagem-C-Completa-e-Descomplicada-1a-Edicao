/* 17) Escreva uma função que receba como parâmetro uma matriz A contendo N
linhas e N colunas. A função deve retornar o ponteiro para um vetor B de tamanho
N alocado dinamicamente, em que cada posição de B é a soma dos números daquela
coluna da matriz. */

#include <stdio.h>
#include <stdlib.h>

int *matriz_soma_coluna(int *A, size_t N) {
    int *B = malloc(sizeof *B * N),
         soma = 0;

    if (B != NULL) {

        // i = índice no vetor que será retornado, coluna da matriz
        for (size_t i = 0; i < N; i++) {
            soma = 0;

            //j = linha da matriz
            for (size_t j = 0; j < N; j++) {
                soma += A[j * N + i];
            }

            B[i] = soma;
        }
    }

    return B;
}

int main() {
    int **matriz = NULL,
         *soma_colunas = NULL,
          tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho da matriz quadrada: ");
        scanf("%d", &tamanho);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    // Alocação da matriz
    if ((matriz = calloc(tamanho, sizeof *matriz)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    if ((matriz[0] = calloc(tamanho * tamanho, sizeof **matriz)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    for (int i = 1; i < tamanho; i++) {
        matriz[i] = matriz[0] + i * tamanho;
    }

    printf("\nInforme os valores da matriz:\n\n");

    for (int i = 0; i < tamanho; i++) {

        for (int j = 0; j < tamanho; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    soma_colunas = matriz_soma_coluna(*matriz, tamanho);

    printf("\nResultado da soma das colunas da matriz: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", soma_colunas[i]);
    }

    free(matriz[0]);
    free(matriz);

    matriz = NULL;

    free(soma_colunas);

    soma_colunas = NULL;

    return 0;
}
