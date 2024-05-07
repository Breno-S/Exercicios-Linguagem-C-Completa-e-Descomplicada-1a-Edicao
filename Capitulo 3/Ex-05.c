/* 5) Faça um programa que calcule o ano de nascimento de uma pessoa a partir
de sua idade e do ano atual. */

#include <stdio.h>

int main() {
    unsigned short  idade,
                    ano_atual,
                    ano_nascimento;

    printf("Informe sua idade: ");
    scanf("%hu", &idade);

    printf("Informe o ano atual: ");
    scanf("%hu", &ano_atual);

    ano_nascimento = ano_atual - idade;

    printf("\nAno de nascimento: %hu\n", ano_nascimento);

    return 0;
}
