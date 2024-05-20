/* 5) Escreva uma função para o cálculo do volume de uma esfera
    V = 4/3π * r3,
em que π = 3.1414592 valor do raio r deve ser passado por parâmetro. */

#include <stdio.h>

double volume_esfera(double r) {
    return 4.0 / 3.0 * 3.1414592 * (r*r*r);
}

int main() {
    double raio = 0;

    while (raio <= 0) {
        printf("Informe o raio da esfera: ");
        scanf("%lf", &raio);
    }

    printf("Volume da esfera: %.2f\n", volume_esfera(raio));

    return 0;
}
