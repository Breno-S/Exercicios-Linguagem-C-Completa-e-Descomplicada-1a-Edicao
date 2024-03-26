/* 9) Escreva uma função recursiva que receba um número inteiro positivo n.
Calcule e retorne o seu fatorial n!:
    n! = n * (n – 1) * (n – 2) * ... * 1 */

#include <stdio.h>

unsigned long long fatorial(unsigned n) {
    if (n == 1 || n == 0) {
        return 1;
    }

    return n * fatorial(n-1);
}

int main() {
    int num = -1;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    printf("Fatorial de %d = %llu", num, fatorial(num));

    return 0;
}
