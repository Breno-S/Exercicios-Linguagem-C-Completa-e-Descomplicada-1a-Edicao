/* 6) Faça um programa que leia um arquivo texto contendo uma lista de compras.
Cada linha do arquivo possui nome, quantidade e valor unitário do produto. O
programa então exibe o total da compra. */

/*
O arquivo precisa estar num padrão semelhante ao CSV para que o programa
funcione:

Arroz, 1, 4.0
Feijao, 2, 3.5
Carne, 1, 15.0
Leite, 3, 3.0
Ovos, 1, 8.5

O asterisco no especificador de formato da função scanf `%*[^,]` indica que o
que for assimilado deve ser descartado.
*/

#include <stdio.h>

int main() {
    int   qtd = 0;

    float preco = 0,
          total = 0;

    FILE *fp;

    if ((fp = fopen("lista_compras.txt", "r")) == NULL) {
        perror("Error");
        return 1;
    }
    
    while (!feof(fp)) {
        fscanf(fp, "%*[^,],%d,%f", &qtd, &preco);

        total += preco * qtd;

        preco = qtd = 0;
    }

    printf("Total da compra: R$%.2f\n", total);
    
    fclose(fp);

    return 0;
}
