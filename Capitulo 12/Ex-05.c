/* 5) Faça um programa que leia números positivos e os converta em binário. Cada
número binário deverá ser salvo em uma linha de um arquivo texto. O programa
termina quando o usuário digitar um número negativo. */

/*
Reutilizei o algoritmo do Capítulo 9 para imprimir em binário utilizando 
recursão.
*/

#include <stdio.h>

// Copia `num` como número binário para o arquivo de texto apontado por `fp`.
void copia_binario(unsigned num, FILE *fp) {
    short digito = num & 1;

    if (num == 1 || num == 0) {
        fprintf(fp, "%d", digito);
        return;
    }

    copia_binario(num >> 1, fp);

    fprintf(fp, "%hd", digito);
}

int main() {
    int   num = 0;
    FILE *fp;
    char  c;

    // Cria o arquivo de texto
    if ((fp = fopen("binarios.txt", "w")) == NULL) {
        perror("Error");
        return 1;
    }

    do {
        printf("Informe um numero para registrar em binario: ");
        scanf("%d", &num);

        // Limpa buffer do stdin
        while ((c = getchar()) != '\n' && c != EOF);

        // Condição de encerramento do programa
        if (num < 0) break;

        copia_binario(num, fp);

        fputc('\n', fp);
    } while (1);

    fclose(fp);

    return 0;
}
