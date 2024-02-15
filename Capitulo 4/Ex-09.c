/* 9) Faça um programa que leia a altura e o peso de uma pessoa. De acordo com a
tabela a seguir, verifique e mostre qual a classificação dessa pessoa.

Altura              Peso
                    Até 60  Entre 60-90 (inclusive) Acima de 90
Menor do que 1,20   A       D                       G
1,20-1,70           B       E                       H
Maior do que 1,70   C       F                       I*/

#include <stdio.h>

int main() {
    float   altura,
            peso;

    printf("Informe sua altura em metros: ");
    scanf("%f", &altura);

    printf("Informe seu peso em quilos: ");
    scanf("%f", &peso);

    printf("\nClassificacao: ");

    if (altura < 1.20) {
        if (peso <= 60) {
            printf("A");
        } else if (peso > 60 && peso <= 90) {
            printf("D");
        } else {
            printf("G");
        }
    } else if (altura >= 1.20 && altura <= 1.70) {
        if (peso <= 60) {
            printf("B");
        } else if (peso > 60 && peso <= 90) {
            printf("E");
        } else {
            printf("H");
        }
    } else {
        if (peso <= 60) {
            printf("C");
        } else if (peso > 60 && peso <= 90) {
            printf("F");
        } else {
            printf("I");
        }
    }

    return 0;
}
