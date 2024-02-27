/* 11) Faça um programa que leia uma matriz de tamanho 5 × 5. Calcule e imprima
a soma dos elementos dessa matriz que estão acima da diagonal principal. */

#include <stdio.h>

#define TAMANHO 5

int main() {
    int matriz[5][5] = { 0 },
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

            if (j > i) {
                soma += matriz[i][j];
            }
        }
    }

    printf("\nSoma dos valores acima da diagonal principal: %d", soma);

    return 0;
}
