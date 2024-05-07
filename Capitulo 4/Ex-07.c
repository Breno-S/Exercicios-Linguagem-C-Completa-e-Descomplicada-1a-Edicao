/* 7) Uma empresa vende o mesmo produto para quatro diferentes estados. Cada
estado possui uma taxa diferente de imposto sobre o produto. Faça um programa em
que o usuário entre com o valor e o estado de destino do produto e o programa
retorne o preço final do produto acrescido do imposto do estado em que ele será
vendido. Se o estado digitado não for válido, mostrará uma mensagem de erro.

Estado  MG  SP  RJ  MS
Imposto 7%  12% 15% 8% */

#include <stdio.h>

int main() {
    float           imposto_MG = 0.07, // 1
                    imposto_SP = 0.12, // 2
                    imposto_RJ = 0.15, // 3
                    imposto_MS = 0.08, // 4

                    valor_base,
                    valor_final;

    unsigned short  opcao;

    printf("Informe o valor base do produto: ");
    scanf("%f", &valor_base);

    printf(
        "\nInforme o estado onde sera vendido:\n"
        "1 - MG | 2 - SP | 3 - RJ | 4 - MS\n\nR: "
    );

    scanf("%hu", &opcao);

    if (opcao < 1 || opcao > 4) {
        printf("\nErro. Escolheu opcao invalida (%hu)\n", opcao);
        return -1;
    }

    if (opcao == 1) {
        valor_final = valor_base + (valor_base * 0.07);
    } else if (opcao == 2) {
        valor_final = valor_base + (valor_base * 0.12);
    } else if (opcao == 3) {
        valor_final = valor_base + (valor_base * 0.15);
    } else {
        valor_final = valor_base + (valor_base * 0.08);
    }

    printf("\nValor final do produto: R$%.2f\n", valor_final);

    return 0;
}
