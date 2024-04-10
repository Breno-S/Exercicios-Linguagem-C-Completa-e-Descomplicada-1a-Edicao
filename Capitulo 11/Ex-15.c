/* 15) Escreva uma função que receba como parâmetro dois vetores, A e B, de
tamanho N cada. A função deve retornar o ponteiro para um vetor C de tamanho N
alocado dinamicamente, em que C[i] = A[i] * B[i]. */

#include <stdio.h>
#include <stdlib.h>

int *produto_vetores(int *A, int *B, size_t N) {
    int *C = malloc(sizeof *C * N);

    if (C != NULL) {
        while (N-- > 0) {
            C[N] = A[N] * B[N];
        }
    }

    return C;
}

int main() {
    int *vetor1 = NULL,
        *vetor2 = NULL,
        *vetor_produto = NULL,
         tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho dos vetores: ");
        scanf("%d", &tamanho);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    vetor1 = calloc(tamanho, sizeof *vetor1);

    if (vetor1 == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    vetor2 = calloc(tamanho, sizeof *vetor2);

    if (vetor2 == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    printf("\nInforme os valores do vetor A:\n\n");

    for (int i; i < tamanho; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor1[i]);

        int c;
        while((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nInforme os valores do vetor B:\n\n");

    for (int i; i < tamanho; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor2[i]);

        int c;
        while((c = getchar()) != '\n' && c != EOF) {}
    }

    vetor_produto = produto_vetores(vetor1, vetor2, tamanho);

    if (vetor_produto == NULL) {
        printf("\nErro: memoria insuficiente");
    }

    printf("\nA * B = ");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor_produto[i]);
    }

    free(vetor1);
    vetor1 = NULL;

    free(vetor2);
    vetor2 = NULL;

    free(vetor_produto);
    vetor_produto = NULL;

    return 0;
}
