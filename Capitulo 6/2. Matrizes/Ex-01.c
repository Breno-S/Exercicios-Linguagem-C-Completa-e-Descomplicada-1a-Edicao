/* 1) Faça um programa que leia uma matriz de tamanho 3 × 3. Imprima na tela o
menor valor contido nessa matriz. */

#include <stdio.h>

int main() {
    int matriz[3][3] = { 0 },
        menor;

    printf("Preencha a matriz 3x3\n\n");

    for (char i = 0; i < 3; i++) {
        for (char j = 0; j < 3; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    menor = matriz[0][0];

    for (char i = 0; i < 3; i++) {
        for (char j = 0; j < 3; j++) {
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }

    printf("\nMenor numero da matriz: %d\n", menor);

    return 0;
}
