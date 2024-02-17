/* 8) Faça um programa que leia 10 inteiros e imprima sua média. */

#include <stdio.h>

#define QTD_NUMS 10

int main() {
    int     num;
    double  media = 0;

    printf(
        "Recebendo %d numero(s) inteiro(s) para calcular a media.\n\n",
        QTD_NUMS
    );

    for (int i = 0; i < QTD_NUMS; i++) {
        printf("#%d: ", i + 1);
        
        scanf("%d", &num);

        media += num;
        
        // Limpar o '\n' e qualquer outro lixo restante no buffer de entrada
        // padrão (a.k.a. stdin).
        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    media /= QTD_NUMS;

    printf("\nMedia: %f", media);

    return 0;
}
