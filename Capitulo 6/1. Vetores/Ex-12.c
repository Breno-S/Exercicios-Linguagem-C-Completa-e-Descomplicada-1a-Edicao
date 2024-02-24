/* 12) Faça um programa que leia um vetor de 10 posições. Verifique se existem
valores iguais e os escreva na tela. */

#include <stdio.h>

int main() {
    int vetor[10],
        repetidos[10] = { 0 };

    printf("Preencha um array de 10 posicoes\n\n");

    for (size_t i = 0; i < 10; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    for (size_t i = 0; i < 10; i++) {
        if (repetidos[i] == 1) {
            continue;
        }

        for (size_t j = 0; j < 10; j++) {
            if (i == j) {
                continue;
            }

            if (vetor[i] == vetor[j]) {
                printf("Valor repetido: [%d] = [%d] = %d\n", i, j, vetor[i]);
                repetidos[i] = repetidos[j] = 1;
            }
        }
    }


    return 0;
}
