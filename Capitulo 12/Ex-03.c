/* 3) Escreva um programa para converter o conteúdo de um arquivo texto em
caracteres maiúsculos. O programa deverá ler do usuário o nome do arquivo a ser
convertido e o nome do arquivo a ser salvo. */

#include <stdio.h>
#include <string.h>

int main() {
    char  arquivo1[256] = { 0 },
          arquivo2[256] = { 0 },
          c;

    FILE *fp_leitura,
         *fp_escrita;

    do {
        printf("Informe o nome do arquivo de texto a ser convertido: ");
        fgets(arquivo1, 256, stdin);

        // Sanitiza a variável ou o buffer do stdin
        if (arquivo1[strlen(arquivo1) - 1] == '\n') {
            arquivo1[strlen(arquivo1) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Tenta abrir o arquivo
        if ((fp_leitura = fopen(arquivo1, "r")) == NULL) {
            perror("Error");
        }
    } while (fp_leitura == NULL);

    printf("Informe o nome do arquivo de texto a ser salvo: ");
    fgets(arquivo2, 256, stdin);

    if (arquivo2[strlen(arquivo2) - 1] == '\n') {
        arquivo2[strlen(arquivo2) - 1] = '\0';
    }

    if ((fp_escrita = fopen(arquivo2, "w")) == NULL) {
        fclose(fp_leitura);
        perror("Error");
        return 1;
    }

    // Copia o conteúdo tornando minúsculas em maiúsculas
    while ((c = fgetc(fp_leitura)) != EOF) {
        fputc((c >= 97 && c <= 122) ? c -= 32 : c, fp_escrita);
    }

    printf("Conteúdo salvo com sucesso.\n");

    fclose(fp_leitura);
    fclose(fp_escrita);

    return 0;
}
