/* 12) Escreva uma função que receba como parâmetro um vetor contendo N valores
inteiros. Essa função deve retornar, por referência, dois valores: a soma dos
números pares e ímpares. */

#include <stdio.h>

#define SIZE 10

void soma_par_impar(int *array, size_t tamanho, int *par, int *impar) {
    *par = *impar = 0;

    for (size_t i = 0; i < tamanho; i++) {
        if (array[i] % 2 == 0) {
            *par += array[i]; 
        } else {
             *impar += array[i];
        }
    }
}

int main() {
    int vetor[SIZE] = { 0 },
        soma_pares = 0,
        soma_impares = 0;

    printf("Informe os valores inteiros do vetor de %d posicoes\n\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    soma_par_impar(vetor, SIZE, &soma_pares, &soma_impares);

    printf("\nSoma dos valores pares: %d", soma_pares);
    printf("\nSoma dos valores impares: %d", soma_impares);

    return 0;
}
