/* 7) Faça um programa que receba do usuário um vetor X com 10 posições. Em 
seguida deverão ser impressos o maior e o menor elemento desse vetor. */

#include <stdio.h>

int main() {
    int X[10] = { 0 },
        maior,
        menor;

    printf("Informe o valor #1: ");
    scanf("%d", &X[0]);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    maior = menor = X[0];

    for (int i = 1; i < 10; i++) {
        printf("Informe o valor #%d: ", i+1);
        scanf("%d", &X[i]);

        while ((c = getchar()) != '\n' && c != EOF) {}
        
        if (X[i] > maior) {
            maior = X[i];
        }

        if (X[i] < menor) {
            menor = X[i];
        }

    }

    printf("\nMenor numero lido: %d\n", menor);
    printf("Maior numero lido: %d\n", maior);

    return 0;
}
