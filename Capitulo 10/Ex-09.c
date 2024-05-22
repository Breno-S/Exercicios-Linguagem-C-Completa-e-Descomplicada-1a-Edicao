/* 9) Crie uma função que receba como parâmetro um vetor e o imprima. Não
utilize índices para percorrer o vetor, apenas aritmética de ponteiros. */

#include <stdio.h>

void print_array(int *array, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) {
        printf("%d ", *(array + i));
    }
}

int main() {
    int vetor[10] = {0, 1, 1, 2, 3, 5, 8 , 13, 21, 34};

    print_array(vetor, 10);

    printf("\n");

    return 0;
}
