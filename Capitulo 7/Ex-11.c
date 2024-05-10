/* 11) Escreva um programa que leia uma string do teclado e converta todos os
seus caracteres em minúscula. Dica: some 32 dos caracteres cujo código ASCII
está entre 65 e 90. */

#include <stdio.h>

int main() {
    char    str[64];
    int     tamanho;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str, 64, stdin);

    // Calcula o tamanho da string
    for (tamanho = 0; str[tamanho] != '\0'; tamanho++) {}

    // Retira o caractere de nova linha
    if (str[tamanho-1] == '\n') {
        str[tamanho-1] = '\0';
        tamanho--;
    }

    for (size_t i = 0; i < tamanho; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
    }
    
    printf("String convertida para letras minusculas: %s\n", str);
    return 0;
}
