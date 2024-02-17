/* 21) Escreva um programa que leia certa quantidade de números, imprima o maior
deles e quantas vezes o maior número foi lido. A quantidade de números a serem
lidos deve ser fornecida pelo usuário. */

#include <stdio.h>

int main() {
    unsigned    qtd = 0,
                maior_count = 0;

    int         num = 0,
                maior = 0,
                c;

    do {
        printf(
            "Quantos numeros gostaria de inserir?\n"
            "R: "
        );
        scanf("%u", &qtd);

        while ((c= getchar()) != '\n' && c != EOF) {}
    } while (qtd < 1);

    printf("\n");

    printf("#1: ");
    scanf("%d", &num);

    while ((c= getchar()) != '\n' && c != EOF) {}
    
    maior = num;

    for (int i = 2; i <= qtd; i++) {
        printf("#%d: ", i);
        scanf("%d", &num);

        while ((c= getchar()) != '\n' && c != EOF) {}

        if (num > maior) {
           maior = num;
           maior_count++; 
        }
    }

    printf("\nMaior numero lido: %d\n", maior);
    printf(
        "Quantidade de vezes que o maior numero foi reescrito: %d",
        maior_count
    );
    
    return 0;
}
