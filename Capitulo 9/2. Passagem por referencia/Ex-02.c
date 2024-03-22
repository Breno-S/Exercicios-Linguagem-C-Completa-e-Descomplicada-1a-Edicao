/* 2) Escreva uma função para o cálculo do volume e área de uma esfera
    V = 4/3 π * r^3 ,
    A = 4π * r^2
em que π = 3.1414592. O valor do raio r deve ser passado por parâmetro, e os
valores calculados devem ser retornados por referência. */

#include <stdio.h>

void calcula_V_A_esfera(double raio, double *V, double *A) {
    *V = 4.0 / 3.0 * 3.1414592 * (raio * raio * raio);
    *A = 4.0 * 3.1414592 * (raio * raio);
}

int main() {
    double  raio;
    
    double  volume,
            area;

    printf("Informe o raio da esfera: ");
    scanf("%lf", &raio);

    calcula_V_A_esfera(raio, &volume, &area);

    printf("\n\tVolume: %lf", volume);
    printf("\n\tArea: %lf", area);

    return 0;
}
