/* 6) Crie uma função que receba uma matriz A contendo cinco linhas e cinco
colunas. Calcule na própria matriz A a sua transposta (se B é a matriz
transposta de A, então A[i][j] = B[j][i]). */

#include <stdio.h>

void transpor_matriz(int matriz[5][5]) {
    for (size_t i = 0; i < 5; i++) {
        for (size_t j = i; j < 5; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }
}

int main() {
    int matriz[5][5] = { 0 };

    printf(
        "Informe os valores da matriz 5x5 "
        "(colunas separadas por espacos e linhas por novas linhas):\n\n"
    );

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    transpor_matriz(matriz);

    printf("\nMatriz tranposta:\n\n");

    for (size_t i = 0; i < 5; i++) {
        for (size_t j = 0; j < 5; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
