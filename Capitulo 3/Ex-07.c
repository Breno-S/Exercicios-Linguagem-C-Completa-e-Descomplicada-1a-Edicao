/* 7) Faça um programa que leia um valor em reais e a cotação do dólar.
Em seguida, imprima o valor correspondente em dólares. */

#include <stdio.h>

int main() {
    float   cotacao_dolar,
            valor_reais,
            valor_dolares;

    printf("Informe a quantidade de reais\n");
    printf("R$ ");
    scanf("%f", &valor_reais);

    printf("\nInforme a cotacao do dolar: ");
    scanf("%f", &cotacao_dolar);

    valor_dolares = valor_reais / cotacao_dolar;
 
    printf("\nQuantia em dolares:\n");
    printf("U$%.2f\n", valor_dolares);

    return 0;
}
