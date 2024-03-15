/* 12) Crie uma enumeração representando os dias da semana. Agora, escreva um
programa que leia um valor inteiro do teclado e exiba o dia da semana
correspondente */

#include <stdio.h>

enum DiaSemana {
    DOMINGO = 1,
    SEGUNDA,
    TERCA,
    QUARTA,
    QUINTA,
    SEXTA,
    SABADO
};

int main() {
    enum DiaSemana diaSemana = 0;

    while (diaSemana < 1 || diaSemana > 7) {
        printf("Informe um dia de 1 a 7: ");
        scanf("%d", &diaSemana);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    switch (diaSemana) {
        case DOMINGO:
            puts("Domingo");
            break;
        case SEGUNDA:
            puts("Segunda-feira");
            break;
        case TERCA:
            puts("Terca-feira");
            break;
        case QUARTA:
            puts("Quarta-feira");
            break;
        case QUINTA:
            puts("Quinta-feira");
            break;
        case SEXTA:
            puts("Sexta-feira");
            break;
        case SABADO:
            puts("Sabado");
            break;
    }

    return 0;
}
