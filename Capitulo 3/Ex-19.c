/* 19) Elabore um programa que leia dois números inteiros e exiba o resultado
das operações de “ou exclusivo”, “ou bit a bit” e “e bit a bit” entre eles. */

#include <stdio.h>

int main() {
    int numero1, numero2,
        num_xor,
        num_or,
        num_and;

    printf("Informe o primeiro numero: ");
    scanf("%d", &numero1);

    printf("Informe o segundo numero: ");
    scanf("%d", &numero2);

    // OU EXCLUSIVO (bit a bit)
    num_xor = numero1 ^ numero2;

    // OU bit a bit
    num_or = numero1 | numero2;

    // E bit a bit
    num_and = numero1 & numero2;

    printf("\nXOR: %d\n", num_xor);
    printf("OR: %d\n", num_or);
    printf("AND: %d\n", num_and);

    return 0;
}
