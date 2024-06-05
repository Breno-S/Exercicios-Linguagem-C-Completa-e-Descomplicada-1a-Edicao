/* 6) Crie um programa que contenha um array contendo cinco elementos inteiros.
Leia esse array do teclado e imprima o endereço das posições contendo valores
pares. */

#include <stdio.h>

int main() {
    int array[5] = { 0 };

    printf("Informe os valores para o array de 5 posicoes\n\n");

    for (int i = 0; i < 5; i++) {
        printf("[%d]: ", i);
        scanf("%d", (array+i));

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nEndereco das posicoes contendo valores pares:\n\n");

    for (int i = 0; i < 5; i++) {
        if (*(array+i) % 2 == 0) {
            printf("%p - [%d]: %d\n", (array+i), i, *(array+i));
        }
    }

    return 0;
}
