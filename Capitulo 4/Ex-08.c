/* 8) Escreva um programa que, dada a idade de um nadador, o classifique em uma
das seguintes categorias:

    Infantil A  5-7
    Infantil B  8-10
    Juvenil A   11-13
    Juvenil B   14-17
    Sênior      maiores de 18 anos */

#include <stdio.h>

int main() {
    unsigned short idade;

    printf("Informe a idade do(a) nadador(a): ");
    scanf("%hu", &idade);

    if (idade < 5) {
        printf("Erro: a idade minima e de 5 anos.");
    } else {
        printf("Categoria: ");

        if (idade >= 5 && idade <= 7) {
            printf("Infantil A");
        } else if (idade >= 8 && idade <= 10) {
            printf("Infantil B");
        } else if (idade >= 11 && idade <= 13) {
            printf("Juvenil A");
        } else if (idade >= 14 && idade <= 17) {
            printf("Juvenil B");
        } else {
            printf("Senior");
        }
    }

    return 0;
}
