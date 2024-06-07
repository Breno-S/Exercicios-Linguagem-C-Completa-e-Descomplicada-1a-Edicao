/* 2) Escreva um programa que leia do usuário os nomes de dois arquivos texto.
Crie um terceiro arquivo texto com o conteúdo dos dois primeiros juntos (o
conteúdo do primeiro seguido do conteúdo do segundo). */

#include <stdio.h>
#include <string.h>

int main(){
    char  arquivo1[256] = { 0 },
          arquivo2[256] = { 0 },
          c;

    FILE *fp1,
         *fp2,
         *fp3;

    do {
        printf("Informe o nome do primeiro arquivo de texto a ser copiado: ");
        fgets(arquivo1, 256, stdin);

        // Sanitiza a variável ou o buffer do stdin
        if (arquivo1[strlen(arquivo1) - 1] == '\n') {
            arquivo1[strlen(arquivo1) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Tenta abrir o arquivo
        if ((fp1 = fopen(arquivo1, "r")) == NULL) {
            perror("Error");
        }
    } while (fp1 == NULL);

    do {
        printf("Informe o nome do segundo arquivo de texto a ser copiado: ");
        fgets(arquivo2, 256, stdin);

        if (arquivo2[strlen(arquivo2) - 1] == '\n') {
            arquivo2[strlen(arquivo2) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        if ((fp2 = fopen(arquivo2, "r")) == NULL) {
            perror("Error");
        }
    } while (fp2 == NULL);

    // Cria o arquivo final
    if ((fp3 = fopen("concat.txt", "w")) == NULL) {
        fclose(fp1);
        fclose(fp2);
        perror("Error");
        return 1;
    }

    // Copia o arquivo 1 para o 3
    while ((c = fgetc(fp1)) != EOF) {
        fputc(c, fp3);
    }
    
    // Copia o arquivo 2 para o 3
    while ((c = fgetc(fp2)) != EOF) {
        fputc(c, fp3);
    }

    printf("\nArquivos concatenados para 'concat.txt'\n");

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    return 0;
}
