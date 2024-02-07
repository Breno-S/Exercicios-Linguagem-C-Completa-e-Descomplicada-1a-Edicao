/* 4) Faça um programa que leia um número inteiro e depois o imprima usando o
operador “%f”. Veja o que aconteceu. */

#include <stdio.h>

int main() {
    int numero_inteiro;

    scanf("%d", &numero_inteiro);

    // print usando o placeholder "%f" no tipo int
    printf("Valor lido: %f", numero_inteiro);

    return 0;
}
