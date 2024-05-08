/* 15) Elabore um programa que faça a leitura de vários números inteiros até que
se digite um número negativo. O programa tem de retornar o maior e o menor
número lido. */

#include <stdio.h>

int main() {
    long long   num = 0, 
                maior, menor;
    char        ch;

    printf(
        "Digite um numero positivo para ser lido. "
        "Digite um numero negativo para encerrar o programa.\n\n"
    );

    printf("> ");
    scanf("%lld", &num);

    if (num < 0) {
        return 0;
    }

    maior = menor = num;
    
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    do {
        printf("> ");
        scanf("%lld", &num);
        
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        if (num < 0) {
            break;
        }

        menor = (num < menor) ? num : menor;
        maior = (num > maior) ? num : maior;
        
    } while (1); // loop infinito

    printf("\nMaior numero lido: %lld\n", maior);
    printf("Menor numero lido: %lld\n", menor);
    return 0;
}
