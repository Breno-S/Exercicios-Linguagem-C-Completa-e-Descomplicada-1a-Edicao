/* 6) Escreva uma função que receba o peso (quilos) e a altura (metros) de uma
pessoa.  Calcule e retorne o IMC (índice de massa corporal) dessa pessoa:
    IMC = peso/(altura * altura) */

#include <stdio.h>

float valor_IMC(float peso, float altura) {
    return peso / (altura * altura);
}

int main() {
    float   peso = 0,
            altura = 0;

    while (peso <= 0) {
        printf("Informe seu peso: ");
        scanf("%f", &peso);
    }

    while (altura <= 0) {
        printf("Informe sua altura: ");
        scanf("%f", &altura);
    }

    printf("\nIMC = %.2f", valor_IMC(peso, altura));

    return 0;
}
