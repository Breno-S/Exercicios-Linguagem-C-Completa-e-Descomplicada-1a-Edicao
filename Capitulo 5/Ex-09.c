/* 9) Escreva um programa que leia 10 números e escreva o menor valor lido e o
maior valor lido. */

/*
Perceba que se este programa tivesse sido feito para comparar números
floating-point, as comparações não funcionariam corretamente 100% das vezes.
Isso ocorre porque a representação de números fracionários em binário na verdade
não corresponde exatamente ao número que se deseja armazenar, mas a uma
aproximação dele. Assim, sempre haverá nas casas mais à direita algarismos
estranhos provenientes dessa aproximação;
*/

#include <stdio.h>

#define QTD_NUMS 10

int main() {
    int num,
        menor,
        maior;

    printf("Recebendo %u numero(s).\n\n#1: ", QTD_NUMS);

    scanf("%d", &num);

    maior = menor = num;

    // Limpar o stdin
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    for (int i = 1; i < QTD_NUMS; i++) {
        printf("#%d: ", i+1);

        scanf("%d", &num);

        // Limpar o stdin
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (num > maior) {
            maior = num;
        } else if (num < menor) {
            menor = num;
        }
    }

    printf("\nMenor numero lido: %d\n", menor);
    printf("Maior numero lido: %d\n", maior);

    return 0;
}
