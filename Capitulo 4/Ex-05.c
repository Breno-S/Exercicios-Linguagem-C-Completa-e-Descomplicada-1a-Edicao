/* 5) Faça um programa que leia um número e, caso ele seja positivo, calcule e
mostre:
    • O número digitado ao quadrado.
    • A raiz quadrada do número digitado. */

#include <stdio.h>
#include <math.h>

int main() {
    double  num;

    printf("Digite um numero: ");
    scanf("%lf", &num);

    if (num > 0) {
        printf("Numero digitado ao quadrado: %f\n", pow(num, 2));
        printf("Raiz quadrada do numero digitado: %f", sqrt(num));
    }

    return 0;
}
