/* 15) Faça um programa que leia os coeficientes de uma equação do segundo grau.
Em seguida, calcule e mostre as raízes dessa equação, lembrando que as raízes
são calculadas como 
    x = (-b ± sqrt(∆)) / 2*a
em que ∆ = b² - 4*a*c e ax² + bx + c = 0 representa uma equação do segundo grau.
A variável a tem de ser diferente de zero. Caso seja igual, imprima a mensagem
“Não é equação de segundo grau”. Do contrário, imprima:
    • Se ∆ < 0, não existe real. Imprima a mensagem “Não existe raiz”.
    • Se ∆ = 0 existe uma raiz real. Imprima a raiz e a mensagem “Raiz única”.
    • Se ∆ > 0, existem duas raízes reais. Imprima as raízes. */

#include <stdio.h>
#include <math.h>

int main() {
    double  a, b, c;

    double  delta,
            raiz_unica,
            raiz1, raiz2;

    printf("Coeficiente a: ");
    scanf("%lf", &a);

    printf("Coeficiente b: ");
    scanf("%lf", &b);

    printf("Coeficiente c: ");
    scanf("%lf", &c);

    delta = b * b - 4 * a * c;

    printf("\n");

    if (a == 0) {
        printf("Nao e equacao de segundo grau");
    } else {
        if (delta < 0) {
            printf("Nao existe raiz.");
        }

        if (delta == 0) {
            raiz_unica = (-b + sqrt(delta)) / (2.0 * a);
            printf("Raiz unica: %f", raiz_unica);
        }

        if (delta > 0) {
            raiz1 = (-b + sqrt(delta)) / (2.0 * a);
            raiz2 = (-b - sqrt(delta)) / (2.0 * a);
            printf("Primeira raiz: %f\n", raiz1);
            printf("Segunda raiz: %f", raiz2);
        }
    }

    printf("\n");

    return 0;
}
