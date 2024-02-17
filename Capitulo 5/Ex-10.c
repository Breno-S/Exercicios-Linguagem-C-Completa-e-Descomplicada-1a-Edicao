/* 10) Faça um programa que leia 10 inteiros positivos, ignorando não positivos,
e imprima sua média. */

#include <stdio.h>

#define QTD_NUMS 10

int main() {
    int		num;
    double	media;

    printf(
        "Recebendo %d numeros naturais para calcular a media.\n\n",
        QTD_NUMS
    );

    int i = 0;
    while (i < QTD_NUMS) {
        printf("#%d: ", i+1);

        scanf("%d", &num);
        
        // Limpar o stdin
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (num < 0) {
            printf("Somente numeros inteiros positivos sao permitidos.\n\n");
            continue;
        }

        media += num;
        i++;
    }

    media /= QTD_NUMS;

    printf("\nMedia: %f", media);

    return 0;
}
