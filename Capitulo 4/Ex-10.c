/* 10) Faça um programa que leia três números inteiros positivos e efetue o
cálculo de uma das seguintes médias de acordo com um valor numérico digitado
pelo usuário e mostrado na tabela a seguir:

Número digitado     Média 
1                   Geométrica
2                   Ponderada
3                   Harmônica
4                   Aritmética */

#include <stdio.h>
#include <math.h>

int main() {
    double  num1, num2, num3,
            result;
            
    char    opcao;

    printf("Informe 3 numeros: ");
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    printf(
        "\nEscolha uma media:\n"
        "1 - Geometrica | 2 - Ponderada | 3 - Harmonica"" | 4 - Aritmetica\n"
        
        "\nR: "
    );
    scanf(" %c", &opcao);

    switch (opcao) {
        case '1':
            result = pow((num1 * num2 * num3), 1.0/3.0);
            printf("\nMedia Geometrica: %f\n", result);
            break;
        case '2':
            result = (num1 + 2*num2 + 3*num3) / 6.0;
            printf("\nMedia Ponderada: %f\n", result);
            break;
        case '3':
            result = 3.0 / (1.0/num1 + 1.0/num2 + 1.0/num3);
            printf("\nMedia Harmonica: %f\n", result);
            break;
        case '4':
            result = (num1 + num2 + num3) / 3.0;
            printf("\nMedia Aritmetica: %f\n", result);
            break;
        default:
            printf("\nOpcao invalida\n");
    }

    return 0;
}
