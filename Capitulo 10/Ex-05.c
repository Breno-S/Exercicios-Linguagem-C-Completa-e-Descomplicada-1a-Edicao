/* 5) Crie um programa que contenha um array de inteiros contendo cinco
elementos. Utilizando apenas aritmética de ponteiros, leia esse array do
teclado e imprima o dobro de cada valor lido. */

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
    
    printf("\n");

    for (size_t i = 0; i < 5; i++) {
        printf("%d ", *(array+i) * 2);
    }

    printf("\n");

    return 0;
}
