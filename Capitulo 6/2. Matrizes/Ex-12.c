/* 12) Faça um programa que leia uma matriz de tamanho 6 × 6. Calcule e imprima
a soma dos elementos dessa matriz que estão abaixo da diagonal principal. */

#include <stdio.h>

#define TAMANHO 6

int main() {
    int matriz[TAMANHO][TAMANHO] = { 0 },
        soma = 0;

    printf(
        "Preencha a matriz %dx%d "
        "(Dica: separe as colunas com espacos e as linhas com ENTERS):\n\n",
        TAMANHO,
        TAMANHO
    );

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            scanf("%d", &matriz[i][j]);

            if (i > j) {
                soma += matriz[i][j];
            }
        }
    }

    printf("\nSoma dos valores abaixo da diagonal principal: %d\n", soma);

    return 0;
}
