/* 4) Faça um programa que leia uma string e a imprima de trás para a frente. */

#include <stdio.h>
#include <string.h>

int main() {
    char    str[64];
    int     tamanho_str;

    printf("Digite uma frase de ate 63 caracteres: ");
    fgets(str, 64, stdin);

    tamanho_str = strlen(str);

    // Retira o caractere de nova linha para não imprimi-lo depois
    if (str[tamanho_str-1] == '\n') {
        str[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    printf("Frase ao contrario: ");

    for (int i = tamanho_str-1; i >= 0; i--) {
       putchar(str[i]); 
    }

    printf("\n");

    return 0;
}
