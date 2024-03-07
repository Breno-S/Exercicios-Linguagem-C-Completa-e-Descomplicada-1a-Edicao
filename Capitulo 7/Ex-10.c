/* 10) Escreva um programa que leia uma string do teclado e converta todos os
seus caracteres em maiúscula. Dica: subtraia 32 dos caracteres cujo código ASCII
está entre 97 e 122. */

#include <stdio.h>

int main() {
    char    str[64];
    int     tamanho;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str, 64, stdin);

    // Calcula o tamanho da string
    for (int i = 0; str[i] != '\0'; i++) {
        tamanho++;
    }

    // Retira o caractere de nova linha
    if (str[tamanho-1] == '\n') {
        str[tamanho-1] = '\0';
        tamanho--;
    }

    for (size_t i = 0; i < sizeof(str); i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
    
    printf("String convertida para letras maiusculas: %s", str);
    return 0;
}
