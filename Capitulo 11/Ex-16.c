/* 16) Escreva uma função que receba como parâmetro uma matriz A contendo N
linhas e N colunas, e um vetor B de tamanho N. A função deve retornar o ponteiro
para um vetor C de tamanho N alocado dinamicamente, em que C é o produto da
matriz A pelo vetor B. */

/*
O programa basicamente faz a multiplicação de uma matriz quadrada por uma matriz
coluna. O retorno da função é um array, mesmo assim resolvi mostrar o resultado
na vertical.
*/

#include <stdio.h>
#include <stdlib.h>

int *produto_matriz_vetor(int *A, int *B, size_t N) {
    int *C = malloc(sizeof *C * N),
         soma = 0;

    if (C != NULL) {

        // i = linha da matriz
        for (size_t i = 0; i < N; i++) {
            soma = 0;

            // j = coluna da matriz, elemento do array
            for (size_t j = 0; j < N; j++) {
                soma += A[i * N + j] * B[j];
            }

            C[i] = soma;
        }
    }

    return C;
}

int main() {
    int **matriz = NULL,
         *vetor = NULL,
         *produto = NULL,
         tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho dos matriz quadrada e do vetor: ");
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

    // Alocação do vetor
    if ((vetor = calloc(tamanho, sizeof *vetor)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
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

    printf("\nInforme os valores do vetor:\n\n");

    for (int i = 0; i < tamanho; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while((c = getchar()) != '\n' && c != EOF) {}
    }

    if ((produto = produto_matriz_vetor(*matriz, vetor, tamanho)) == NULL) {
        printf("Erro ao calcular o produto");
        return 2;
    }

    printf("\nProduto da multiplicacao do matriz pelo vetor:\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", produto[i]);
    }

    free(matriz[0]);
    free(matriz);

    matriz = NULL;

    free(vetor);
    vetor = NULL;

    free(produto);
    produto = NULL;

    return 0;
}
