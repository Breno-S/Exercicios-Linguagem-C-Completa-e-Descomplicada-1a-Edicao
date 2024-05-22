/* 4) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido.
Em seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do
usuário e o imprima. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vetor = NULL,
         tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho do vetor: ");
        scanf("%d", &tamanho);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    vetor = malloc(sizeof *vetor * tamanho);

    if (vetor == NULL) {
        printf("\nErro: memoria insuficiente\n");
        return 1;
    }

    printf("\nInforme os valores do vetor:\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nVetor:\n\n");

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}
