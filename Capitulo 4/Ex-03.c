/* 3) Faça um programa que leia um número inteiro e verifique se esse número é
par ou ímpar. */

#include <stdio.h>

int main() {
    int num;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    if (num % 2 == 0)
        printf("\nPar");
    else
        printf("\nImpar");

    return 0;
}
