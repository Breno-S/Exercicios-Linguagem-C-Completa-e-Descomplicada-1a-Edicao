/* 5) Faça um programa que leia um valor do tipo float e depois o imprima usando
o operador “%d”. Veja o que aconteceu. */

#include <stdio.h>

int main() {
    float numero_float;

    scanf("%f", &numero_float);

    // print usando o placeholder "%d" no tipo float
    printf("Valor lido: %d\n", numero_float);

    return 0;
}
