/* 7) Faça uma função que retorne o ponteiro para um vetor de N elementos
inteiros alocados dinamicamente. O array deve ser preenchido com valores de 0 a
N − 1. */

#include <stdio.h>
#include <stdlib.h>

int *heap_array_int(size_t N) {
    int *array = malloc(sizeof *array * N);

    if (array != NULL) {
        // Preenchimento do array
        while (N-- > 0) {
            array[N] = N;
        }
    }

    return array;
}

int main() {
    int *vetor = NULL,
         tamanho = 0;

    while (tamanho <= 0) {
        printf("Informe o tamanho do vetor: ");
        scanf("%d", &tamanho);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    vetor = heap_array_int(tamanho);

    if (vetor == NULL) {
        printf("\nErro: memoria insuficiente\n");
        return 1;
    }

    printf("\nVetor:\n\n");
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] = %d\n", i, vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return 0;
}
