/* 7) Faça um programa que leia um valor em reais e a cotação do dólar.
Em seguida, imprima o valor correspondente em dólares. */

#include <stdio.h>

int main() {
    float   cotacao_dolar,
            valor_reais,
            valor_dolares;

    printf("Informe o valor em reais: ");
    scanf("%f", &valor_reais);

    printf("Informe a cotacao do dolar: ");
    scanf("%f", &cotacao_dolar);

    valor_dolares = valor_reais / cotacao_dolar;

    printf("R$%.2f = U$%.2f", valor_reais, valor_dolares);

    return 0;
}
