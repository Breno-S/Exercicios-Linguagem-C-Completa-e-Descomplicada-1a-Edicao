/* 16) Escreva um programa que leia um número inteiro e mostre a multiplicação
e a divisão desse número por dois (utilize os operadores de deslocamento de
bits). */

#include <stdio.h>

int main() {
    int numero,
        dobro,
        metade;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    dobro = numero << 1;  // é o mesmo que (n * 2^1)
    metade = numero >> 1; // é o mesmo que (n / 2^1)

    printf("Dobro: %d\n", dobro);
    printf("Metade: %d", metade);

    return 0;
}
