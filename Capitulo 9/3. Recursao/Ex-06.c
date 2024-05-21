/* 6) Crie uma função recursiva que retorne a média dos elementos de um vetor de
inteiros. */

#include <stdio.h>

#define SIZE 10

double media_array(int *array, size_t tamanho, size_t tamanho_original) {
    if (tamanho == 1) {
        return (double)(*array) / tamanho_original;
    }

    return (double)(*array) / tamanho_original +
        media_array(array+1, tamanho-1, 10);
}

int main() {
    int vetor[SIZE];

    printf("Informe os valores do array de %d inteiros:\n\n", SIZE);
    for (size_t i = 0; i < 10; i++) {
        printf("[%zu]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nMedia dos valores do array: %f\n", media_array(vetor, 10, 10));

    return 0;
}
