/* 1) Escreva uma função recursiva que calcule a soma dos primeiros n cubos:
    S = 1^3 + 2^3 + ... + n^3 */

#include <stdio.h>

unsigned long long n_primeiros_cubos(unsigned n) {
    if (n == 0) return 0;

    if (n == 1) return 1;

    return (n*n*n) + n_primeiros_cubos(n-1);
}

int main() {
    int num = -1;

    while (1) {
        printf("Informe ate qual cubo somar: ");
        scanf("%d", &num);

        int c;
        while((c = getchar()) != '\n' && c != EOF) {}

        if (num < 0) {
            printf("\nInforme um numero positivo\n\n");
        } else {
            break;
        }
    }

    printf("Soma dos %u primeiros cubos: %llu", num, n_primeiros_cubos(num));

    return 0;
}
