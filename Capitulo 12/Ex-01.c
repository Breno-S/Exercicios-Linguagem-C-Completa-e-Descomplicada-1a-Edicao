/* 1) Escreva um programa que leia do usuário o nome de um arquivo texto. Em
seguida, mostre na tela quantas linhas esse arquivo possui */

#include <stdio.h>
#include <string.h>

int main(){
    char    nome_arquivo[256] = { 0 },
            c;

    size_t  total_linhas = 0;
    
    FILE   *fp;

    printf("Digite o nome do arquivo de texto: ");
    fgets(nome_arquivo, 256, stdin);

    // Retira o caractere '\n'
    if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
        nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
    }

    // Tenta abrir o arquivo
    if ((fp = fopen(nome_arquivo, "r")) == NULL) {
        perror("Error");
        return 1;
    }

    // "Espia" o primeiro caractere do arquivo
    c = fgetc(fp);
    ungetc(c, fp);

    // Se não houver nada, o arquivo possui 0 linhas. Senão, possui 1 linha
    total_linhas = (c == EOF) ? 0 : 1;

    // Consome caracteres até encontrar um '\n' ou o fim do arquivo
    while (!feof(fp)) {
        c = fgetc(fp);

        if (c == '\n') {
            // Se houver algo após '\n', incrementa o número de linhas
            if ((c = fgetc(fp)) != EOF) {
                total_linhas++;
                ungetc(c, fp);
            }
        }
    }

    printf("Total de linhas do arquivo '%s': %zu\n", nome_arquivo, total_linhas);

    fclose(fp);

    return 0;
}
