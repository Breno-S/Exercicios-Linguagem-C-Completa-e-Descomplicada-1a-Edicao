/* 3) Faça um programa que leia três valores inteiros e mostre sua soma. */

#include <stdio.h>

int main() {
    int	a, b, c,
        soma;

    scanf("%d %d %d", &a, &b, &c);

    soma = a + b + c;

    printf("\n%d\n", soma);

    return 0;
}
