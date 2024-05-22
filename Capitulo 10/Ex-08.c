/* 8) Crie uma função que receba dois parâmetros: um vetor e um valor do mesmo
tipo do vetor. A função deverá preencher os elementos de vetor com esse valor.
Não utilize índices para percorrer o vetor, apenas aritmética de ponteiros. */

/*
Me dei a liberdade de adicionar o tamanho do array como parâmetro da função.
*/

#include <stdio.h>

void array_fill(int *array, size_t tamanho, int valor) {
    for (size_t i = 0; i < tamanho; i++) {
        *(array + i) = valor;
    }
}

int main() {
    int vetor[10], num = 0;

    printf("Informe um valor para preencher o array: ");
    scanf("%d", &num);

    array_fill(vetor, 10, num);
    
    printf("\nArray = {");

    for (size_t i = 0; i < 9; i++) {
        printf("%d, ", *(vetor + i));
    }

    printf("%d}\n", *(vetor + 9));
    
    return 0;
}
