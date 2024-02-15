/* 2) Faça um programa que leia dois números e mostre o maior deles. Se, por
acaso, os dois números forem iguais, imprima a mensagem “Números iguais”. */

#include <stdio.h>

int main() {
    double num1, num2;

    printf("Informe dois numeros: ");
    scanf("%lf %lf", &num1, &num2);

    if (num1 == num2)
        printf("Numeros iguais");
    else {
        if (num1 > num2)
            printf("Maior numero: %lf", num1);
        else
            printf("Maior numero: %lf", num2);
    }

    return 0;
}
