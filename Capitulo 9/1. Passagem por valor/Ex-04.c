/* 4) Escreva uma função que receba por parâmetro a altura e o raio de um
cilindro circular e retorne o volume desse cilindro. O volume de um cilindro
circular é calculado por meio da seguinte fórmula:
    V = π * raio2 * altura,
em que π = 3.1414592 */

#include <stdio.h>

double volume_cilindro(double h, double r) {
    return 3.1414592 * (r*r) * h;
}

int main() {
    double  altura = 0,
            raio = 0;

    while (altura <= 0) {
        printf("Informe a altura do cilindro: ");
        scanf("%lf", &altura);
    }

    while (raio <= 0) {
        printf("Informe o raio do cilindro: ");
        scanf("%lf", &raio);
    }

    printf("\nVolume do cilindro: %.2f\n", volume_cilindro(altura, raio));

    return 0;
}
