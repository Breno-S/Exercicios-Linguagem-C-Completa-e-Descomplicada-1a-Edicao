/* 9) Escreva uma função que receba como parâmetro o nome de um arquivo texto e 
retorne quantas vogais esse arquivo possui. */

#include <stdio.h>
#include <string.h>

int is_vogal(char ch) {
    switch (ch) {
        case 'A':
        case 'a':
        case 'E':
        case 'e':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'U':
        case 'u':
            return 1;
        default:
            return 0;
    }
}

int main() {
    char   nome_arquivo[256] = { 0 };
    size_t count_vogais = 0;
    FILE  *fp;

    printf("Informe o nome do arquivo: ");
    fgets(nome_arquivo, 256, stdin);

    // Retira caractere '\n'
    if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
        nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
    }

    // Tenta abrir o arquivo
    if ((fp = fopen(nome_arquivo, "r")) == NULL) {
        perror("Error");
        return 1;
    }
    
    // Conta as vogais
    char c;
    while ((c = fgetc(fp)) != EOF) {
        count_vogais += is_vogal(c);
    }

    printf("Total de vogais: %zu\n", count_vogais);

    fclose(fp);

    return 0;
}
