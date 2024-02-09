/* 1) Faça um programa que leia um número inteiro e retorne seu antecessor e
seu sucessor. */

#include <stdio.h>

int main() {
    int numero_inteiro;

    scanf("%d", &numero_inteiro);

    printf("%d %d", numero_inteiro-1, numero_inteiro+1);

    return 0;
}
