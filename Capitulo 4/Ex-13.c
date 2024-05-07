/* 13) Faça um programa que mostre ao usuário um menu com quatro opções de
operações matemáticas (as operações básicas, por exemplo). O usuário escolhe uma
das opções, e o seu programa pede dois valores numéricos e realiza a operação,
mostrando o resultado. */

#include <stdio.h>

int main() {
    char    opcao;
    double  opnd1, opnd2;

    printf("Escolha uma operacao:\n + | - | * | / \n\nR: ");
    scanf("%c", &opcao);

    if (opcao != '+' && opcao != '-' && opcao != '*' && opcao != '/') {
        printf("Erro. Digite um dos caracteres e aperte ENTER.\n");
        return 0;
    }

    printf("\nInforme dois operandos: ");
    scanf("%lf %lf", &opnd1, &opnd2);

    printf("\n");

    switch (opcao) {
        case '+':
            printf("%lf + %lf = %lf", opnd1, opnd2, (opnd1 + opnd2));
            break;
        case '-':
            printf("%lf - %lf = %lf", opnd1, opnd2, (opnd1 - opnd2));
            break;
        case '*':
            printf("%lf * %lf = %lf", opnd1, opnd2, (opnd1 * opnd2));
            break;
        case '/':
            printf("%lf / %lf = %lf", opnd1, opnd2, (opnd1 / opnd2));
            break;
    }

    printf("\n");

    return 0;
}
