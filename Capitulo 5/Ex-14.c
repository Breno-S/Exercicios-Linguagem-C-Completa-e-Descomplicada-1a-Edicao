/* 14) Escreva um programa que leia um número inteiro, maior ou igual a zero, do
usuário. Imprima o enésimo termo da sequência de Fibonacci. Essa sequência
começa no termo de ordem zero, e, a partir do segundo termo, seu valor é dado
pela soma dos dois termos anteriores. Alguns termos dessa sequência são: 0, 1,
1, 2, 3, 5, 8, 13, 21, 34. */

#include <stdio.h>

int main() {
    long long num = 0;

    size_t  a = 0,
            b = 1,
            c;

    do {
        printf("Informe um numero maior ou igual a zero: ");
        scanf("%llu", &num);

        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}

    } while (num < 0);

    if (num == 0) {
        printf("Fim do programa");
        return 0;
    }
    if (num == 1) {
        printf("Termo #%llu da sequencia de Fibonacci: %llu", num, a);
    } else if (num == 2) {
        printf("Termo #%llu da sequencia de Fibonacci: %llu", num, b);
    } else {
        for (int i = 3; i <= num; i++) {
            c = a + b;

            a = b;
            b = c;
        }

        printf("Termo #%llu da sequencia de Fibonacci: %llu", num, c);
    }

    return 0;
}
