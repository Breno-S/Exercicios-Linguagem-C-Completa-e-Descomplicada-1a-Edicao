/* 15) Faça um programa que leia uma matriz A de tamanho 5 × 5. Em seguida,
calcule e imprima a matriz B, sendo que B = A². */

#include <stdio.h>

#define TAMANHO 5

int main() {
    int A[TAMANHO][TAMANHO] = { 0 },
        B[TAMANHO][TAMANHO] = { 0 },
        sum = 0;

    printf(
        "Preencha a matriz %dx%d "
        "(Dica: separe as colunas com espacos e as linhas com ENTERS):\n\n",
        TAMANHO,
        TAMANHO
    );

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // i informa a linha
    for (int i = 0; i < TAMANHO; i++) {

        // j informa a coluna, sum reseta a cada iteração
        for (int j = 0; j < TAMANHO; j++, sum = 0) {

            // k informa a posição dos elementos, na linha e na coluna
            for (int k = 0; k < TAMANHO; k++) {
                sum += A[i][k] * A[k][j];
            }

            B[i][j] = sum;
        }
    }

    printf("\n");

    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d\t", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
