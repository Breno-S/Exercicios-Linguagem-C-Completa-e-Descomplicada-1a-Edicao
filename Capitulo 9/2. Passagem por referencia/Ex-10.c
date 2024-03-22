/* 10) Escreva uma função que receba uma string e retorne se ela é um palíndromo
(1) ou não (0). Um palíndromo é uma palavra que tem a propriedade de poder ser
lida tanto da direita para a esquerda como da esquerda para a direita. Exemplos:
ovo, arara, rever, asa, osso etc. */

/*
Assim como no capitulo 7 esta solução é case-insensitive.
*/

#include <stdio.h>

int is_palind(char* str, size_t tamanho_max) {
    // Tamanho da string.
    size_t strlen;
    for (strlen = 0; strlen < tamanho_max && str[strlen] != '\0'; strlen++) {}

    // Retira o caractere de nova linha se houver.
    if (str[strlen-1] == '\n') {
        str[strlen-1] = '\0';
        strlen--;
    }

    // Compara os caracteres da string simetricamente, par a par
    for (size_t i = 0, j = (strlen-1); i <= j; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char string[64] = { 0 };
    
    printf("Informe uma string de ate 63 caracteres: ");

    fgets(string, 64, stdin);

    if (is_palind(string, 64)) {
        printf("\nA string e um palindromo!\n");
    } else {
        printf("\nA string nao e um palindromo.\n");
    }

    return 0;
}
