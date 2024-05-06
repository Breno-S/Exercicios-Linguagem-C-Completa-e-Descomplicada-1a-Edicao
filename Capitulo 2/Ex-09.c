/* 9) Faça um programa que leia dois valores do tipo float. Use um único comando
de leitura para isso. Em seguida, imprima os valores lidos na ordem inversa em
que eles foram lidos. */

#include <stdio.h>

int main() {
    float valor1, valor2;

    scanf("%f %f", &valor1, &valor2);

    printf("%f %f\n", valor2, valor1);

    return 0;
}
