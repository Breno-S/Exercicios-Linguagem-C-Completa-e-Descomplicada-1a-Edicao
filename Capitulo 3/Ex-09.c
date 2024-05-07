/* 9) Leia um ângulo em graus e apresente-o convertido em radianos. A fórmula de
conversão é R = G * π/180, sendo G o ângulo em graus e R em radianos e
π = 3.141592. */

#include <stdio.h>

#define PI 3.141592

int main() {
    double  angulo_graus,
            angulo_rad;

    printf("Informe o angulo em graus: ");
    scanf("%lf", &angulo_graus);

    angulo_rad = angulo_graus * PI / 180;

    printf("%.1f graus = %f rad\n", angulo_graus, angulo_rad);

    return 0;
}
