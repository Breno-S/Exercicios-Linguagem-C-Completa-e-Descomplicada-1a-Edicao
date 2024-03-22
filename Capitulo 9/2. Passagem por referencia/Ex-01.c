/* 1) Escreva uma função que, dado um número real passado como parâmetro,
retorne a parte inteira e a parte fracionária desse número por referência. */

#include <stdio.h>

void repartir_real(double num, int *inteiro, double *fracionario) {
    *inteiro = (int) num;
    *fracionario = num - (int) num;
}

int main() {
    double  numero_real;

    double  pt_fracionaria;
    int     pt_inteira;

    printf("Informe um numero fracionario: ");
    scanf("%lf", &numero_real);

    repartir_real(numero_real, &pt_inteira, &pt_fracionaria);

    printf("Numero = %f\n", numero_real);
    printf("Parte inteira = %d\n", pt_inteira);
    printf("Parte fracionaria = %f", pt_fracionaria);
    
    return 0;
}
