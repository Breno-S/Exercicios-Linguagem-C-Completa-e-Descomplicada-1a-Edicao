/* 3) Faça um programa que declare uma matriz de tamanho 5 × 5. Preencha com 1
a diagonal principal e com 0 os demais elementos. Ao final, escreva a matriz
obtida na tela. */

#include <stdio.h>

/*
O macro abaixo possibilita alterar o tamanho da matriz com mais praticidade,
sem quebrar a funcionalidade do código.
*/

#define TAMANHO 5

int main() {
    int matriz[TAMANHO][TAMANHO];

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            if (i == j) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
