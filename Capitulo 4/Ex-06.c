/* 6) Faça um programa que receba a altura e o sexo de uma pessoa e calcule e
mostre seu peso ideal, utilizando as seguintes fórmulas (em que “h” corresponde
à altura):
    • Homens: (72,7 * h) – 58
    • Mulheres: (62,1 * h) – 44,7 */

#include <stdio.h>

int main() {
    float   altura,
            peso_ideal;

    char    sexo;

    printf("Informe a sua altura: ");
    scanf("%f", &altura);

    printf("Informe o seu sexo\n\n1 - Feminino\n2 - Masculino\n\nR: ");

    /*
    Para manter o código simples, a string da função scanf() possui um espaço
    " %c", para que ignore o caractere '\n' (do buffer), assim como 
    qualquer espaço em branco.
    */

    scanf(" %c", &sexo);

    switch (sexo) {
        case '1':
            peso_ideal = (62.1 * altura) - 44.7;
            printf("\nPeso ideal: %f\n", peso_ideal);
            break;
        case '2':
            peso_ideal = (72.7 * altura) - 58;
            printf("\nPeso ideal: %f\n", peso_ideal);
            break;
        default:
            printf("\nErro, tente novamente.\n");
    }

    return 0;
}
