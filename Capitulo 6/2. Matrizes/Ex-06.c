/* 6) Leia uma matriz de tamanho 3 × 3. Em seguida, imprima a soma dos valores
contidos em sua diagonal principal. */

#include <stdio.h>

int main() {
    int matriz[3][3] = { 0 },
        soma_diagonal = 0;

    printf("Preencha a matriz 3x3\n\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (i == j) {
                soma_diagonal += matriz[i][j];
            }
        }
    }

    printf("\nSoma dos valores da diagonal principal: %d", soma_diagonal);

    return 0;
}
