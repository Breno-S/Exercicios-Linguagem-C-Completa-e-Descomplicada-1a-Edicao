/* 14) Crie uma função recursiva que retorne o menor elemento em um vetor. */

#include <stdio.h>

#define SIZE 10

int menor_elemento(int *array, size_t tamanho, int menor) {
    if (*array < menor) {
        menor = *array;
    }

    if (tamanho == 1) {
        return menor;
    }
    
    menor_elemento(array+1, tamanho-1, menor);
}

int main() {
    int vetor[SIZE] = { 0 };

    printf("Informe %d valores inteiros para preencher o vetor\n\n", SIZE);

    for (size_t i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf(
        "Menor elemento do array: %d",
        menor_elemento(vetor, SIZE, vetor[0])
    );

    return 0;
}
