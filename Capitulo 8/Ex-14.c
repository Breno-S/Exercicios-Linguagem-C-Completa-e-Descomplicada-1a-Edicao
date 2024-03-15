/* 4) Crie uma enumeração representando os itens de uma lista de compras. Agora,
escreva um programa que leia um valor inteiro do teclado e exiba o nome do item
comprado e o seu preço. */

#include <stdio.h>

enum Produto {
    ARROZ = 1,
    FEIJAO,
    CARNE_BOVINA,
    ALFACE,
    TOMATE,
    AZEITE,
    OVOS,
    BATATA,
    FAROFA,
    SUCO
};

float preco[10] = {15, 9, 24.98, 3.99, 5, 27.2, 17.69, 7.99, 10, 12.5};

int main() {
    enum Produto produto = -1;

    while (produto < 1 || produto > 10) {
        printf("Informe um item de 1 a 10: ");
        scanf("%d", &produto);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    putchar('\n');

    switch (produto) {
        case ARROZ:
            printf("Arroz ");
            break;
        case FEIJAO:
            printf("Feijao ");
            break;
        case CARNE_BOVINA:
            printf("Carne bovina ");
            break;
        case ALFACE:
            printf("Alface ");
            break;
        case TOMATE:
            printf("Tomate ");
            break;
        case AZEITE:
            printf("Azeite ");
            break;
        case OVOS:
            printf("Ovos ");
            break;
        case BATATA:
            printf("Batata ");
            break;
        case FAROFA:
            printf("Farofa ");
            break;
        case SUCO:
            printf("Suco ");
            break;
    }

    printf("- R$%.2f", preco[produto-1]);

    return 0;
}
