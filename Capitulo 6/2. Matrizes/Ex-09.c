/* 9) Faça um programa que permita ao usuário entrar com uma matriz de tamanho 3
× 3 de números inteiros. Em seguida, calcule um vetor contendo três posições, em
que cada posição deverá armazenar a soma dos números de cada coluna da matriz.
Exiba na tela esse array. Por exemplo, a matriz
    5   −8  10
    1   2   15
    25  10  7
deverá gerar o vetor 31 4 32. */

#include <stdio.h>

int main() {
    int matriz[3][3] = { 0 },
        vetor[3] = { 0 };

    printf("Preencha a matriz 3x3\n\n");

    for (char i = 0; i < 3; i++) {
        for (char j = 0; j < 3; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }


    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            vetor[j] += matriz[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
