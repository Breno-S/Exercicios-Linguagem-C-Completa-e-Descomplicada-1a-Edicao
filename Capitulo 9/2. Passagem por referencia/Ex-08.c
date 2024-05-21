/* 8) Faça uma função que receba, por parâmetro, uma matriz A contendo seis
linhas e seis colunas. Essa função deve retornar, por referência, a soma dos
elementos da sua diagonal principal e da sua diagonal secundária. */

#include <stdio.h>

#define SIZE 6

void somas_diagonais(int matriz[SIZE][SIZE], int *principal, int *secundaria) {
    *principal = *secundaria = 0;

    for (size_t i = 0; i < SIZE; i++) {
        *principal += matriz[i][i];
        *secundaria += matriz[i][(SIZE-1)-i];
    }
}

int main() {
    int matriz[SIZE][SIZE];
    int soma_principal, soma_secundaria;

    printf(
        "Informe os valores da matriz %dx%d "
        "(colunas separadas por espacos e linhas por novas linhas):\n\n",
        SIZE,
        SIZE
    );

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    somas_diagonais(matriz, &soma_principal, &soma_secundaria);

    printf("\nSoma dos elementos da diagonal principal: %d", soma_principal);
    printf("\nSoma dos elementos da diagonal secundaria: %d\n", soma_secundaria);
    
    return 0;
}
