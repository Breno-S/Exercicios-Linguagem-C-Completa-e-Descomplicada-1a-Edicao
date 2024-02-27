/* 5) Leia uma matriz de tamanho 4 × 4. Em seguida, conte e escreva na tela
quantos valores negativos ela possui. */

#include <stdio.h>

int main() {
    int matriz[4][4] = { 0 },
        qtd_negativos = 0;

    printf("Preencha a matriz 4x4\n\n");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (matriz[i][j] < 0) {
                qtd_negativos++;
            }
        }
    }

    printf("\nQuantidade de valores negativos: %d", qtd_negativos);

    return 0;
}
