/* 15) Escreva um programa que leia duas strings e as imprima em ordem
alfabética, a ordem em que elas apareceriam em um dicionário. */

/* 
Este algoritmo somente funciona para caracteres da tabela ASCII. Qualquer
comparação envolvendo caracteres da tabela ASCII extendida pode resultar em algo
fora da ordem alfabética. Recomendo muito pesquisar sobre a história do ASCII,
do Unicode, das codificações (principalmente o UTF-8) e das implementações em C,
como <wchar.h> e <uchar.h>. Creio que isso pode ajudar qualquer um a entender
mais a fundo como os computadores e a interpretação da informação funcionam.
*/

#include <stdio.h>

int main() {
    char    str1[256] = { '\0' },
            str2[256] = { '\0' },
            s1[256]   = { '\0' },
            s2[256]   = { '\0' };

    short   tamanho_str;

    int     is_ordenado = 0;

    do {
        printf("Informe a string 1: ");
        fgets(str1, 256, stdin);

        // Conta o tamanho da string
        for (tamanho_str = 0; str1[tamanho_str] != '\0'; tamanho_str++) {}

        // Se a string NÃO foi contida com folga, limpa o stdin
        if (!(str1[tamanho_str-1] == '\n')) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        
    } while(str1[0] == '\0');

    // Faz uma cópia da string em lowercase
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] >= 65 && str1[i] <= 90) {
            s1[i] = str1[i] + 32;
        } else {
            s1[i] = str1[i];
            
            // Retira o newline character da string original, para exibição
            if (str1[i] == '\n') {
                str1[i] = '\0';
            }
        }
    }

    do {
        printf("Informe a string 2: ");
        fgets(str2, 256, stdin);

        // Conta o tamanho da string
        for (tamanho_str = 0; str2[tamanho_str] != '\0'; tamanho_str++) {}

        // Se a string NÃO foi contida com folga, limpa o stdin
        if (!(str2[tamanho_str-1] == '\n')) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
        
    } while(str2[0] == '\0');

    // Faz uma cópia da string em lowercase
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] >= 65 && str2[i] <= 90) {
            s2[i] = str2[i] + 32;
        } else {
            s2[i] = str2[i];

            // Retira o newline character da string original, para exibição
            if (str2[i] == '\n') {
                str2[i] = '\0';
            }
        }
    }

    for(int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i]) {
            puts(str1);
            puts(str2);
            is_ordenado = 1;
            break;
        } else if (s1[i] > s2[i]) {
            puts(str2);
            puts(str1);
            is_ordenado = 1;
            break;
        } else {
            continue;
        }
    }

    if (!is_ordenado) {
        puts(str1);
        puts(str2);
    }
    
    return 0;
}
