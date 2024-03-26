/* 5) Crie uma função recursiva que retorne a soma dos elementos de um vetor de
inteiros. */

/*
A função que escrevi utiliza notação de ponteiro, pois acredito que uma vez que
você entende o que esta sendo feito com os endereços de memória, esta notação
fica bem mais intuitiva (pelo menos neste exercício). No final do arquivo,
também coloquei a versão com notação de array, caso ainda não esteja
familiarizado com este conceito.
*/

#include <stdio.h>

#define SIZE 10

long long soma_array(int *array, size_t tamanho) {
    if (tamanho == 1) {
        return *array;
    }

    return *array + soma_array(array+1, tamanho-1);
}

int main() {
    int vetor[SIZE] = { 0 };

    printf("Informe os valores para o vetor de %d inteiros:\n\n", SIZE);

    for (size_t i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nSoma dos valores do array: %d", soma_array(vetor, 10));

    return 0;
}

/******************************************************************************
 *                             NOTAÇÃO DE ARRAY                               *
 ******************************************************************************/

/* 

long long soma_array(int array[], size_t tamanho) {
    if (tamanho == 1) {
        return array[0];
    }

    return array[0] + soma_array(&array[1], tamanho-1);
}

*/
