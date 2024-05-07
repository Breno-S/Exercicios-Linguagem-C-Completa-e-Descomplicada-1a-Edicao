/* 1) Faça um programa que leia dois números e mostre qual deles é o maior. */

#include <stdio.h>

int main() {
    double num1, num2;

    printf("Informe dois numeros: ");
    scanf("%lf %lf", &num1, &num2);

    printf("Maior numero: ");

    if (num1 > num2)
        printf("%f\n", num1);
    else
        printf("%f\n", num2);

    return 0;
}
