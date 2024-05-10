/* 2) Faça um programa que leia uma string e imprima as quatro primeiras letras
dela. */

#include <stdio.h>

int main() {
    char str[32];
    
    fgets(str, 32, stdin);
    
    printf("%.4s\n", str);
    
    return 0;
}

/******************************************************************************
 *                     VERSÃO COM LOOPS E FUNÇÕES BÁSICAS                     *
 ******************************************************************************/

/* 
#include <stdio.h>

int main() {
    char    str[32],
            caractere;

    // Preenche todo a string com o caractere '\0'
    for (size_t i = 0; i <= 32; i++) {
        str[i] = '\0';
    }
    
    // Sobrescreve a string conforme o usuario digita, até atingir '\n' ou o 
    // limite de caracteres
    for (size_t i = 0; i < 32; i++) {
        caractere = getchar();

        if (caractere == '\n') {
            break;
        }
        
        str[i] = caractere;
    }
    
    // Imprime somente os 4 primeiros caracteres da string
    for (size_t i = 0; i < 4; i++) {
        putchar(str[i]);
    }
    
    return 0;
}
*/
