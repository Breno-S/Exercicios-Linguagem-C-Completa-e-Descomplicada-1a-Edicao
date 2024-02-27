/* 2) Faça um programa que leia uma matriz de tamanho 4 × 4. Imprima na tela o
maior valor contido nessa matriz e a sua localização (linha e coluna). */

#include <stdio.h>

int main() {
    int     matriz[4][4] = { 0 },
            maior;
    
    char    maior_i,
            maior_j;

    printf("Preencha a matriz 4x4\n\n");

    for (char i = 0; i < 4; i++) {
        for (char j = 0; j < 4; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    maior = matriz[0][0];

    for (char i = 0; i < 4; i++) {
        for (char j = 0; j < 4; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
                maior_i = i;
                maior_j = j;
            }
        }
    }

    printf(
        "\nMaior numero da matriz: %d\n"
        "\nPosicao: [%d][%d]",
        maior,
        maior_i,
        maior_j
    );

    return 0;
}
