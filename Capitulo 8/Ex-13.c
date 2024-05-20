/* 13) Crie uma enumeração representando os meses do ano. Agora, escreva um
programa que leia um valor inteiro do teclado e exiba o nome do mês
correspondente e quantos dias ele possui */

#include <stdio.h>

enum Mes {
    JANEIRO = 1,
    FEVEREIRO,
    MARCO,
    ABRIL,
    MAIO,
    JUNHO,
    JULHO,
    AGOSTO,
    SETEMBRO,
    OUTUBRO,
    NOVEMBRO,
    DEZEMBRO
};

int main() {
    enum Mes mes = 0;   

    while (mes < 1 || mes > 12) {
        printf("Informe um mes de 1 a 12: ");
        scanf("%d", (int *) &mes);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    switch (mes) {
        case JANEIRO:
            puts("Janeiro - 30 dias");
            break;
        case FEVEREIRO:
            puts("Fevereiro - 28 ou 29 dias");
            break;
        case MARCO:
            puts("Marco - 31 dias");
            break;
        case ABRIL:
            puts("Abril - 30 dias");
            break;
        case MAIO:
            puts("Maio - 31 dias");
            break;
        case JUNHO:
            puts("Junho - 30 dias");
            break;
        case JULHO:
            puts("Julho - 31 dias");
            break;
        case AGOSTO:
            puts("Agosto - 31 dias");
            break;
        case SETEMBRO:
            puts("Setembro - 30 dias");
            break;
        case OUTUBRO:
            puts("Outubro - 31 dias");
            break;
        case NOVEMBRO:
            puts("Novembro - 30 dias");
            break;
        case DEZEMBRO:
            puts("Dezembro - 31 dias");
            break;
    }

    return 0;
}
