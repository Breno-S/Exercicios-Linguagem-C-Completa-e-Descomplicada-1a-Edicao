/* 12) Escreva um programa que leia o nome e o valor de determinada mercadoria
de uma loja. Sabendo que o desconto para pagamento à vista é de 10% sobre o
valor total, calcule o valor a ser pago à vista. Escreva o nome da mercadoria,
o valor total, o valor do desconto e o valor a ser pago à vista. */

#include <stdio.h>
#include <string.h>

int main() {
    char            produto[100][40] = { '\0' },
                    resposta_prompt;

    float           preco[100] = { 0 }, total = 0;

    unsigned short 	desconto = 10;

    int             tamanho_str,
                    i = 0,
                    c;

    do {
        printf("Produto: ");
        fgets(produto[i], 40, stdin);

        // Conta o tamanho da string
        for (tamanho_str = 0; produto[i][tamanho_str] != '\0'; tamanho_str++) {}

        // Se a string foi contida com folga, substitui '\n' por '\0'
        if (produto[i][tamanho_str-1] == '\n') {
            produto[i][tamanho_str-1] = '\0';
        }
        
        // Senão limpa o que restou no buffer de entrada
        else {
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        // Transforma o nome do produto em UPPERCASE
        for (int j = 0; produto[i][j] != '\0'; j++) {
            if (produto[i][j] >= 97 && produto[i][j] <= 122) {
                produto[i][j] -= 32;
            }
        }

        if (produto[i][0] != '\0') {

            // Prompt de preço
            do {
                printf("Preco R$: ");
                scanf("%f", &preco[i]);
    
                while ((c = getchar()) != '\n' && c != EOF) {}
            } while (preco[i] == 0);

            printf("\n");

            // Prompt de finalizar
            do {
                printf("Finalizar? (S/N): ");
                resposta_prompt = getchar();
    
                // Validação resposta
                if (resposta_prompt != '\n') {
                    if (getchar() != '\n') {
                        while ((c = getchar()) != '\n' && c != EOF) {}
                        resposta_prompt = 0; 
                    }
                }

            } while (!(resposta_prompt == 'N' || resposta_prompt == 'n') &&
                    (!(resposta_prompt == 'S' || resposta_prompt == 's')) 
            );
            
            printf("\n");
            
            if (resposta_prompt == 'N' || resposta_prompt == 'n') {
                i++;
            }
        }

    } while (
        (resposta_prompt == 'N' || resposta_prompt == 'n') ||
        produto[i][0] == '\0'
    );

    // Imprime a lista de produtos e seus preços
    for (int j = 0; j <= i; j++) {
        printf("%-36s\t$%10.2f\n", (produto[j]), preco[j]);
        total += preco[j];
    }

    printf("---------------------------------------------------\n");
    printf("Total:                                  $%10.2f\n", total);
    printf(
        "%hd%% desconto:                          -$%10.2f\n\n",
        desconto,
        total * ((float) desconto) / 100.0
    );
    printf(
        "A pagar:                                $%10.2f\n",
        total - total * ((float) desconto) / 100.0
    );
    
    return 0;
}
