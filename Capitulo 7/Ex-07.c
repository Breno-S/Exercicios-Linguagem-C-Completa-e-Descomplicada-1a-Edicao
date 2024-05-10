/* 7) Faça um programa que leia uma string e imprima uma mensagem dizendo se ela
é um palíndromo ou não. Um palíndromo é uma palavra que tem a propriedade
de poder ser lida tanto da direita para a esquerda como da esquerda para a
direita. Exemplos: ovo, arara, rever, asa, osso etc. */

/* 
Sempre utilize as versões mais seguras das funções, como strncmp() no lugar de
strcmp(). 

Resolvi reciclar a inversão de string do exercício 5, mas seria mais simples
comparar o caractere `n` com o caractere `strlen - n` e se fossem diferentes em
alguma iteração retornar falso.

S A T O R
A R E P O
T E N E T
O P E R A
R O T A S
*/

#include <stdio.h>
#include <string.h>

int main() {
    char    str_lida[64],
            str_contrario[64] = { '\0' },   
                                // ^^ Inicializa o primeiro elemento do array
                                // como '\0' e, implicitamente, o resto dele 
                                // também como '\0'

            char_comeco,                  
            char_fim;

    int     tamanho_str = 0;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str_lida, 64, stdin);

    tamanho_str = strlen(str_lida);

    // Retira o caractere de nova linha para não imprimi-lo depois
    if (str_lida[tamanho_str-1] == '\n') {
        str_lida[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    // Troca os caracteres da string simetricamente, par a par, desta vez sem
    // ignorar o caractere central
    for (size_t i = 0, j = (tamanho_str-1); i <= j; i++, j--) {
        char_comeco = str_lida[i];
        char_fim = str_lida[j];

        str_contrario[j] = char_comeco;
        str_contrario[i] = char_fim;
    }
    
    // Compara as strings
    if (strncmp(str_lida, str_contrario, tamanho_str) == 0) {
        printf("\nA string e um palindromo!\n");
        printf("\nFrase invertida: %s\n", str_contrario);
    } else {
        printf("\nA string nao e um palindromo.\n");
        printf("\nFrase invertida: %s\n", str_contrario);
    }

    return 0;
}


/******************************************************************************
 *                             VERSÃO MAIS SIMPLES                            *
 ******************************************************************************/

/*
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char    str[64];
    int     tamanho_str = 0;
    bool    is_palindromo = true;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str, 64, stdin);

    tamanho_str = strlen(str);

    // Retira o caractere de nova linha para não imprimi-lo depois
    if (str[tamanho_str-1] == '\n') {
        str[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    // Compara os caracteres da string simetricamente, par a par, desta vez sem
    // ignorar o caractere central
    for (size_t i = 0, j = (tamanho_str-1); i <= j; i++, j--) {
        if(str[i] != str[j]) {
            is_palindromo = false;
        }
    }
    
    if (is_palindromo) {
        printf("\nA string e um palindromo!\n");
    } else {
        printf("\nA string nao e um palindromo\n");
    }

    return 0;
}
*/
