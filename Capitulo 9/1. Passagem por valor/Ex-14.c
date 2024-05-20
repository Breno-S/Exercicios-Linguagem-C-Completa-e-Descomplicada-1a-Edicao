/* 14) Escreva uma função que receba um número inteiro positivo n. Calcule e
retorne o seu fatorial n!: n! = n * (n – 1) * (n – 2) * ... * 1. */

/* 
A função retorna o valor correto até o fatorial de 20, no fatorial de 21 o
resutado ultrapassa a largura máxima de ints de 64 bits.
*/

#include <stdio.h>

unsigned long long fatorial(int n) {
    unsigned long long f = 1;

    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    for (int i = n; i > 0; i--) {
        f *= i;
    }

    return f;
}

int main() {
    int num = 0;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    printf("%d! = %llu\n", num, fatorial(num));

    return 0;
}
