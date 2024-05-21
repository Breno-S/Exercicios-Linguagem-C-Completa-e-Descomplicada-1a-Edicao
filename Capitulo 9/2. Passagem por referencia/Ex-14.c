/* 14) Elabore uma função que receba por parâmetros os coeficientes de uma
equação do segundo grau. Em seguida, calcule e mostre as raízes dessa equação.
Lembre-se de que as raízes são calculadas como
    x = (-b ± sqrt(∆)) / 2*a
em que ∆ = b2 – 4 * a * c e ax2 + bx + c = 0 representa uma equação do segundo
grau. A variável a tem de ser diferente de zero. Caso seja igual, imprima a
mensagem “Não é equação de segundo grau” e retorne o valor −1. Do contrário,
retorne o número de raízes e as raízes (por referência) se elas existirem:
    • Se ∆ < 0, não existe real. Número de raízes: 0.
    • Se ∆ = 0, existe uma raiz real. Número de raízes: 1.
    • Se ∆ > 0, existem duas raízes reais. Número de raízes: 2 */

#include <stdio.h>
#include <math.h>

int calcular_raizes(double a, double b, double c, double *raiz1, double *raiz2) {
    if (a == 0) {
        raiz1 = NULL;
        raiz2 = NULL;
        return -1;
    }

    double delta = b * b - 4 * a * c;

    if (delta < 0) {
        raiz1 = NULL;
        raiz2 = NULL;
        return 0;
    }

    if (delta == 0) {
        *raiz1 = *raiz2 = (-b + sqrt(delta)) / (2.0 * a);

        return 1;
    }

    if (delta > 0) {
        *raiz1 = (-b + sqrt(delta)) / (2.0 * a);
        *raiz2 = (-b - sqrt(delta)) / (2.0 * a);

        return 2;
    }
}

int main() {
    double  a, b, c,
            raiz1, raiz2;

    printf("Coeficiente a: ");
    scanf("%lf", &a);

    printf("Coeficiente b: ");
    scanf("%lf", &b);

    printf("Coeficiente c: ");
    scanf("%lf", &c);

    switch (calcular_raizes(a, b, c, &raiz1, &raiz2)) {
        case -1:
            printf("\nNao e equacao de segundo grau.\n");
            break;
        case 0:
            printf("\nA equacao nao possui raiz\n");
            break;
        case 1:
            printf("\nS = {%lf}\n", raiz1);
            break;
        case 2:
            printf("\nS = {%lf, %lf}\n", raiz1, raiz2);
            break;
        default:
            break;
    }

    return 0;
}
