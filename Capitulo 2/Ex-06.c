/* 6) Faça um programa que leia um valor do tipo double e depois o imprima na
forma de notação científica. */

#include <stdio.h>

int main() {
    double numero_double;

    scanf("%lf", &numero_double);

    // %e para exibir como notação científica
    printf("%e", numero_double);

    return 0;
}
