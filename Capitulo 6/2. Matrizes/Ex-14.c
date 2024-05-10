/* 14) Faça um programa que leia uma matriz de tamanho 5 × 5. Calcule a soma dos
elementos dessa matriz que pertencem à diagonal principal ou secundária. Calcule
também a soma dos elementos que não pertencem a nenhuma das duas diagonais.
Imprima na tela a diferença entre os dois valores. */

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 5

int main() {
    int matriz[TAMANHO][TAMANHO] = { 0 },
        soma_diagonais = 0,
        soma_resto = 0,
        diferenca = 0;

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
                soma_diagonais += matriz[i][j];
            } else {
                soma_resto += matriz[i][j];
            }
        }
    }

    diferenca = abs(soma_diagonais - soma_resto);

    printf(
        "\nDiferenca entre a soma dos valores pertencentes a alguma diagonal "
        "(%d) e a soma daqueles que nao pertencem (%d): %d\n",
        soma_diagonais,
        soma_resto,
        diferenca
    );

    return 0;
}
