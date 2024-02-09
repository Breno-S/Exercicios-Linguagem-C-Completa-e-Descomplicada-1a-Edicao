/* 12) Leia a altura e o raio de um cilindro circular e imprima o volume desse
cilindro. O volume de um cilindro circular é calculado por meio da seguinte
fórmula:
    V = π * raio² * altura,
em que π = 3.141592 */

#include <stdio.h>

#define PI 3.141592F

int main() {
    double  altura,
            raio,
            volume;

    printf("Informe a altura do cilindro: ");
    scanf("%lf", &altura);

    printf("Informe o raio do cilindro: ");
    scanf("%lf", &raio);

    volume = PI * (raio * raio) * altura;

    printf("Volume = %f", volume);

    return 0;
}
