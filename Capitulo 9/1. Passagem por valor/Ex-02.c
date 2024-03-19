/* 2) Faça uma função que receba um número inteiro de 1 a 12 e imprima em tela o
mês e a sua quantidade de dias de acordo com o número digitado pelo usuário.
Exemplo: Entrada = 4. Saída = abril. */

#include <stdio.h>

void print_num_mes(unsigned n) {
    switch (n) {
        case 1:
            printf("Janeiro - 31");
            break;
        case 2:
            printf("Fevereiro - 28 ou 29");
            break;
        case 3:
            printf("Marco - 31");
            break;
        case 4:
            printf("Abril - 30");
            break;
        case 5:
            printf("Maio - 31");
            break;
        case 6:
            printf("Junho - 30");
            break;
        case 7:
            printf("Julho - 31");
            break;
        case 8:
            printf("Agosto - 31");
            break;
        case 9:
            printf("Setembro - 30");
            break;
        case 10:
            printf("Outubro - 31");
            break;
        case 11:
            printf("Novembro - 30");
            break;
        case 12:
            printf("Dezembro - 31");
            break;
        default:
            printf("Entrada invalida.");
            break;
    }
}

int main() {
    int num;

    printf("Informe o numero de um mes (1 a 12): ");
    scanf("%d", &num);

    print_num_mes(num);
    return 0;
}
