/* 4) Elabore um programa no qual o usuário informe o nome de um arquivo texto e
uma palavra, e o programa informe o número de vezes que aquela palavra aparece
dentro do arquivo. */

/*
Ao contrário das minhas soluções para os exercícios 8 e 9 do Capítulo 7, as
ocorrências sobrepostas de uma palavra não são mais consideradas. Somente
ocorrências delimitadas contam como um match, isto é, o programa procura por
palavras inteiras.
*/

#include <stdio.h>
#include <string.h>

// Checa se o argumento é um caractere de whitespace, símbolo
// ou pontuação (na tabela ASCII).
int is_delimitador(char ch);

int main() {
    char      nome_arquivo[256] = { 0 },
              palavra[64] = { 0 },

              c;
    
    size_t    total_corresp = 0,
              tamanho_corresp = 0;

    FILE     *fp;

    do {
        printf("Informe o nome do arquivo de texto a ser pesquisado: ");
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

    printf("Informe uma palavra para buscar no arquivo: ");
    fgets(palavra, 64, stdin);

    // Retira caractere '\n'
    if (palavra[strlen(palavra) - 1] == '\n') {
        palavra[strlen(palavra) - 1] = '\0';
    }

    c = fgetc(fp);

    // Enquanto não chegar ao fim do arquivo
    while (!feof(fp)) {

        // "Consome" caracteres até encontrar um não-delimitador ou...
        while (is_delimitador(c) && c != EOF) {

            // ...sai do loop se a palavra começar com o delimitador lido
            if (is_delimitador(c) && c == palavra[0]) {
                break;
            }

            c = fgetc(fp);
        }

        // Se o caractere for igual ao primeiro caractere da palavra...
        if (c == palavra[0]) {
            tamanho_corresp = 1;

            // ...começa a comparar até atingir o tamanho da palavra
            while (tamanho_corresp < strlen(palavra)) {
                c = fgetc(fp);

                if (c != palavra[tamanho_corresp]) {
                    break;
                }

                tamanho_corresp++;
            }

            // Se a semelhança atingiu o tamanho da palavra...
            if (tamanho_corresp == strlen(palavra)) {
                c = fgetc(fp);

                // ...e o próximo caractere for um delimitador, ou for
                // alfanumérico enquanto o último caractere da string for um
                // delimitador, incrementa o contador de matches
                if (is_delimitador(c) || 
                    (is_delimitador(palavra[strlen(palavra) - 1]) &&
                        !is_delimitador(c)
                    ) ||
                    (c == EOF)
                ) {
                    total_corresp++;
                    continue;
                }
            }
        }

        // Caso não seja um match, consome caracteres até o próximo delimitador
        while (!is_delimitador(c) && c != EOF) {
            c = fgetc(fp);
        }
    }

    printf(
        "\n'%s' aparece %zu vez(es) no arquivo '%s'\n",
        palavra,
        total_corresp,
        nome_arquivo
    );

    fclose(fp);

    return 0;
}

int is_delimitador(char ch) {
    switch (ch) {
        // Caracteres de Espaçamento
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 32:
        // Símbolos e pontuação
        case 33:
        case 34:
        case 35:
        case 36:
        case 37:
        case 38:
        case 39:
        case 40:
        case 41:
        case 42:
        case 43:
        case 44:
        case 45:
        case 46:
        case 47:
        case 58:
        case 59:
        case 60:
        case 61:
        case 62:
        case 63:
        case 64:
        case 91:
        case 92:
        case 93:
        case 94:
        // case 95: /* Exceto underscore _ */
        case 96:
        case 123:
        case 124:
        case 125:
        case 126:
            return 1;
        default:
            return 0;
    }
}
