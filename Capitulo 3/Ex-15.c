/* 15) Faça um programa para ler um número inteiro positivo de três dígitos.
Em seguida, calcule e mostre o número formado pelos dígitos invertidos do
número lido.
Exemplo: 
    Número lido = 123 
    Número gerado = 321 */

#include <stdio.h>

int main() {
    unsigned short  numero,
                    digito_1,
                    digito_2,
                    digito_3,
                    numero_invertido;

    printf("Informe um numero inteiro positivo de tres digitos: ");
    scanf("%hu", &numero);

    digito_3 = numero % 10;
    numero = numero / 10;

    digito_2 = numero % 10;
    numero = numero / 10;

    digito_1 = numero;

    numero_invertido = (digito_3 * 100) + (digito_2 * 10) + (digito_1 * 1);

    printf("%hu", numero_invertido);

    return 0;
}
