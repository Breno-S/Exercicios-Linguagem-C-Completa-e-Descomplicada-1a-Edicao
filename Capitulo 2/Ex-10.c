/* 10) Elabore um programa que solicite ao usuário entrar com o valor do dia,
mês e ano (inteiros). Em seguida, imprima os valores lidos separados por uma
barra (\). */

#include <stdio.h>

int main() {
    unsigned short  dia,
                    mes,
                    ano;

    printf("Dia: ");
    scanf("%hu", &dia); // "%hu" = unsigned short (tipo short sem sinal)

    printf("Mes: ");
    scanf("%hu", &mes);

    printf("Ano: ");
    scanf("%hu", &ano);

    printf("\n%hu/%hu/%hu", dia, mes, ano);

    return 0;
}
