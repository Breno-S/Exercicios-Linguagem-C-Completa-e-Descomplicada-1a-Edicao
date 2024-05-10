/* 5) Faça um programa que leia uma string e a inverta. A string invertida deve
ser armazenada na mesma variável. Em seguida, imprima a string invertida. */

/*
Ter duas variáveis para trocar os caracteres é desnecessário, mas ilustra bem o
que o código faz.
*/

#include <stdio.h>
#include <string.h>

int main() {
    char    str[64],
            char_comeco,
            char_fim;

    int     tamanho_str = 0;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str, 64, stdin);

    tamanho_str = strlen(str);

    // Retira o caractere de nova linha para não imprimi-lo depois
    if (str[tamanho_str-1] == '\n') {
        str[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    // Troca os caracteres da string simetricamente, par a par
    for (size_t i = 0, j = (tamanho_str-1); i < j; i++, j--) {
        char_comeco = str[i];
        char_fim = str[j];

        str[j] = char_comeco;
        str[i] = char_fim;
    }
    
    printf("Frase invertida: %s\n", str);

    return 0;
}
