/* 17) Escreva um programa que leia um número inteiro e mostre o seu complemento
bit a bit. */

/* 
Para entender melhor o que ocorre neste exercício, recomendo que pesquise sobre
como a representação de números inteiros funciona em computadores, especialmente
o funcionamento do "two's complement", o papel do bit mais significativo e como
isso se reflete na diferença entre o complemento de um signed e um unsigned
int.
*/

#include <stdio.h>

int main() {
    int numero,
        complemento_bit;

    printf("Informe um numero: ");
    scanf("%d", &numero);

    complemento_bit = ~numero;

    printf("Complemento bit a bit: %d", complemento_bit);

    return 0;
}
