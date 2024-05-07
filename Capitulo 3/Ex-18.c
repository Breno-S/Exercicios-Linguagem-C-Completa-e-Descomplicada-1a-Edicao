/* 18) Elabore um programa que leia dois números inteiros e exiba o
deslocamento, à esquerda e à direita, do primeiro número pelo segundo. */

#include <stdio.h>

int main() {
    int num1, num2,
        deslocamento_esquerda,
        deslocamento_direita;

    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);

    printf("Informe o segundo numero: ");
    scanf("%d", &num2);

    deslocamento_esquerda = num1 << num2; // é o mesmo que (num1 * 2^num2)
    deslocamento_direita = num1 >> num2;  // é o mesmo que (num1 / 2^num2)

    printf(
        "\nDeslocamento a esquerda do primeiro pelo segundo: %d",
        deslocamento_esquerda
    );

    printf(
        "\nDeslocamento a direita do primeiro pelo segundo: %d\n",
        deslocamento_direita
    );

    return 0;
}
