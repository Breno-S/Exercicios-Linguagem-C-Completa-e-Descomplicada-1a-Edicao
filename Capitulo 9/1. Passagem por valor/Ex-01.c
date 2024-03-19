/* 1) Escreva uma função que receba por parâmetro dois números e retorne o maior
deles. */

#include <stdio.h>

int maior(int a, int b) {
    return (a >= b) ? a : b;
}

int main() {
    int num1 = 0, num2 = 0;

    printf("Informe dois numeros: ");
    scanf("%d %d", &num1, &num2);

    printf("Maior numero: %d", maior(num1, num2));

    return 0;
}
