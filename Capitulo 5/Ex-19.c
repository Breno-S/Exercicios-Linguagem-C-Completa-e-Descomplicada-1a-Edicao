/* 19) Faça um programa que calcule e escreva o valor de S:
    S = 1/1 + 3/2 + 5/3 + 7/4 + ... + 99/55. */

#include <stdio.h>

int main() {
    double  numerador,
            denominador,
            total = 0;

    printf("S = ");

    for (
        numerador = denominador = 1;
        numerador <= 97;
        numerador += 2, denominador++
    ) {
        printf("%.0f/%.0f + ", numerador, denominador);

        total += numerador / denominador;
    }

    total += numerador / denominador;

    printf("%.0f/%.0f = %f", numerador, denominador, total);    

    return 0;
}
