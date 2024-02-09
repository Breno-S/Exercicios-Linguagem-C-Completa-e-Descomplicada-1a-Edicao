/* 13) Sejam a e b os catetos de um triângulo cuja hipotenusa h é obtida pela
equação: 
    h = sqrt(a² + b²)
Faça um programa que leia os valores de a e b, e calcule o valor da hipotenusa
através da fórmula dada. Imprima o resultado. */

#include <stdio.h>
#include <math.h>

int main() {
    double  cateto_a, cateto_b,
            hipotenusa;

    printf("Informe o cateto A: ");
    scanf("%lf", &cateto_a);

    printf("Informe o cateto B: ");
    scanf("%lf", &cateto_b);

    hipotenusa = sqrt((pow(cateto_a, 2) + pow(cateto_b, 2)));

    printf("\n");
    printf("Hipotenusa = %f", hipotenusa);

    return 0;
}
