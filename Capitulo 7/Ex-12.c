/* 12) Escreva um programa que leia o nome e o valor de determinada mercadoria
de uma loja. Sabendo que o desconto para pagamento à vista é de 10% sobre o
valor total, calcule o valor a ser pago à vista. Escreva o nome da mercadoria,
o valor total, o valor do desconto e o valor a ser pago à vista. */

#include <stdio.h>

int main() {
    char    produto[64] = { '\0' };
    float   valor,
            desconto;
    int     tamanho_str;

    do {
        printf("Informe o nome da mercadoria: ");
        fgets(produto, 64, stdin);

        // Conta o tamanho da string
        for (tamanho_str = 0; produto[tamanho_str] != '\0'; tamanho_str++) {}

        // Se a string foi contida com folga, substitui '\n' por '\0'
        if (produto[tamanho_str-1] == '\n') {
            produto[tamanho_str-1] = '\0';
        }
        
        // Senão limpa o que restou no buffer de entrada
        else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    } while (produto[0] == '\0');

    printf("Informe o valor da mercadoria: ");
    scanf("%f", &valor);

    printf("\nProduto: %s\n", produto);
    printf("Preco: %.2f\n", valor);

    desconto = (valor / 10);

    printf("Desconto (a vista) 10%%: %.2f\n", desconto);
    printf("\nValor final: %.2f\n", valor-desconto);

    return 0;
}
