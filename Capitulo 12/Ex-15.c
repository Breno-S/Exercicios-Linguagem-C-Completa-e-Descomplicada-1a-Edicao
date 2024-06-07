/* 15) Elabore um programa para calcular e exibir o número de vezes que cada
letra ocorre dentro de um arquivo texto. Ignore as letras com acento. O usuário
deverá informar o nome do arquivo. */

#include <stdio.h>
#include <string.h>

/* Array que armazena o número de ocorrências.
Por ser uma variável global, sua memória é preenchida com o valor 0. */
size_t count[26];

int main() {
    char   nome_arquivo[256] = { 0 },
           c;

    int    m;
    
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
    
    // Itera até atingir o final do arquivo
    while (!feof(fp)) {
        c = fgetc(fp);

        // Se for uma letra minúscula, transforma em maiúscula
        if (c >= 97 && c <= 122) {
            c -= 32;
        }

        // Se for uma letra, adiciona ao seu respectivo contador
        if (c >= 65 && c <= 90) {
            count[c - 65]++;
        }
    }

    printf("\n");

    for (char i = 0; i < 26; i++) {
        printf(
            "%c%c aparece %zu vez(es) no arquivo '%s'\n",
            i + 65,
            i + 65 + 32,
            count[i],
            nome_arquivo
        );
    }
    
    fclose(fp);

    return 0;
}
