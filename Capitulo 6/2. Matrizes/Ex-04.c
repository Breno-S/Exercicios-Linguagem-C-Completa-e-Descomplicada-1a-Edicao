/* 4) Leia uma matriz de tamanho 4 × 4. Em seguida, conte e escreva na tela
quantos valores maiores do que 10 ela possui. */

#include <stdio.h>

int main() {
    int matriz[4][4] = { 0 },
        maiores_10 = 0;

    printf("Preencha a matriz 4x4\n\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (matriz[i][j] > 10) {
                maiores_10++;
            }
        }
    }

    printf("\nQuantidade de valores maiores que 10: %d\n", maiores_10);

    return 0;
}
