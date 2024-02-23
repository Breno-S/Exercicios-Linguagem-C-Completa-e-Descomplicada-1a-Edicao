/* 9) Escreva um programa que leia 10 números e escreva o menor valor lido e o
maior valor lido. */

#include <stdio.h>

#define QTD_NUMS 10

int main() {
    double  num,
            menor,
            maior;

    printf("Recebendo %u numero(s).\n\n#1: ", QTD_NUMS);

    scanf("%lf", &num);

    maior = menor = num;

    // Limpar o stdin
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    for (int i = 1; i < QTD_NUMS; i++) {
        printf("#%d: ", i + 1);

        scanf("%lf", &num);

        if (num > maior) {
            maior = num;
        } else if (num < menor) {
            menor = num;
        }

        // Limpar o stdin
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nMenor numero lido: %f\n", menor);
    printf("Maior numero lido: %f\n", maior);

    return 0;
}
