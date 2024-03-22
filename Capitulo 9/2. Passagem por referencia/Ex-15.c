/* 15) Elabore uma função que receba um vetor contendo N valores e retorne por
referência o maior e o menor elemento desse vetor. */

#include <stdio.h>

#define SIZE 10

void maior_menor_array(int *array, size_t tamanho, int *maior, int *menor) {
    *maior = *menor = array[0];

    for (size_t i = 0; i < tamanho; i++) {
        if (array[i] > *maior) {
            *maior = array[i];
            continue;
        }

        if (array[i] < *menor) {
            *menor = array[i];
        }
    }
}

int main() {
    int vetor[SIZE] = { 0 },
        maior_elemento,
        menor_elemento;

    printf("Informe os valores inteiros do vetor de %d posicoes\n\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    maior_menor_array(vetor, SIZE, &maior_elemento, &menor_elemento);

    printf("\nMaior elemento do array: %d", maior_elemento);
    printf("\nMenor elemento do array: %d", menor_elemento);

    return 0;
}
