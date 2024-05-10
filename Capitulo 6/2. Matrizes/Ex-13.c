/* 13) Faça um programa que leia uma matriz de tamanho 5 × 5. Calcule e imprima
a soma dos elementos dessa matriz que não pertencem à diagonal principal nem à
diagonal secundária. */

#include <stdio.h>

#define TAMANHO 5

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

            if (i == j || i + j == TAMANHO-1) {
                continue;
            }

            soma += matriz[i][j];
        }
    }

    printf("\nSoma dos valores que nao pertencem a nenhuma diagonal: %d\n", soma);

    return 0;
}
