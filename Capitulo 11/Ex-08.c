/* 8) Escreva uma função que receba um valor inteiro positivo N por parâmetro e
retorne o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for
negativo ou igual a zero, um ponteiro nulo deverá ser retornado. */

#include <stdio.h>
#include <stdlib.h>

int *heap_vetor_int(int N) {
    int *ptr = NULL;

    if (N > 0) {
        ptr = calloc(N, sizeof *ptr);
    }

    return ptr;
}

int main() {
    int *vetor = NULL,
         tamanho = 0;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    vetor = heap_vetor_int(tamanho);

    if (vetor == NULL) {
        printf("\nErro: memoria insuficiente");
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
