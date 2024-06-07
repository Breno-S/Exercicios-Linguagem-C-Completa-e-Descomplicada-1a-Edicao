/* 14) Crie um programa para calcular e exibir o número de palavras contido em
um arquivo texto. O usuário deverá informar o nome do arquivo */

/*
Dessa vez optei por um algoritmo mais simples: qualquer coisa que esteja
separada por white-space é uma palavra.
*/
#include <stdio.h>
#include <string.h>

int is_espaco(char c) {
    switch (c) {
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 32:
            return 1;
        default:
            return 0;
    }
}

int main() {
    char   nome_arquivo[256] = { 0 },
           c;

    size_t count_palavras = 0;

    FILE  *fp;

    do {
        printf("Informe o nome do arquivo: ");
        fgets(nome_arquivo, 256, stdin);

        // Sanitiza a variável ou o buffer do stdin
        if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
            nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Tenta abrir o arquivo
        if ((fp = fopen(nome_arquivo, "r")) == NULL) {
            perror("Error");
        }

    } while (fp == NULL);

    c = fgetc(fp);

    // Enquanto não atingir o fim do arquivo...
    while (!feof(fp)) {
        // Descarta os caracteres de espaçamento antes da palavra
        while (is_espaco(c) && c != EOF) {
            c = fgetc(fp);
        }

        if (c == EOF) break;

        // Consome caracteres até encontrar um espaçamento (fim da palavra)
        while (!is_espaco(c) && c != EOF) {
            c = fgetc(fp);
        }

        count_palavras++;
    }

    printf(
        "Numero de palavras no arquivo '%s': %zu\n",
        nome_arquivo,
        count_palavras
    );

    fclose(fp);

    return 0;
}
