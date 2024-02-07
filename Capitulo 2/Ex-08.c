/* 8) Faça um programa que leia dois números inteiros e depois os imprima na
ordem inversa em que eles foram lidos. */

#include <stdio.h>

int main() {
    int primeiro_numero, segundo_numero;

    scanf("%d", &primeiro_numero);
    scanf("%d", &segundo_numero);

    printf("%d %d", segundo_numero, primeiro_numero);

    return 0;
}
