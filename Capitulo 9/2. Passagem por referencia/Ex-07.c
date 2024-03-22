/* 7) Crie uma função que receba uma matriz A contendo 10 linhas e 10 colunas e
retorne a soma dos seus elementos. */

#include <stdio.h>

#define SIZE 10 // Mude isso se não quiser digitar 100 elementos

int soma_matriz(int matriz[SIZE][SIZE]) {
    int s = 0;

    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++) {
            s += matriz[i][j];
        }
    }
    
    return s;
}


int main() {
    int matriz[SIZE][SIZE] = { 0 };

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

    printf("\nSoma dos elementos da matriz = %d", soma_matriz(matriz));

    return 0;
}
