/* 13) Faça um programa que exiba a soma de todos os números naturais abaixo de
1.000 que são múltiplos de 3 ou 5. */

#include <stdio.h>

int main() {
    int soma = 0;

    printf(
        "Soma de todos os numeros naturais abaixo de 1.000 que sao multiplos de"
        " 3 ou 5:\n\n"
    );

    for (size_t i = 1; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            if (i == 999) {
                printf("%zu = ", i);
            } else {
                printf("%zu + ", i);
            }

            soma += i;
        }
    }

    printf("%d\n", soma);

    return 0;
}
