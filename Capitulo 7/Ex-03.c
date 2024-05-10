/* 3) Sem usar a função strlen(), faça um programa que leia uma string e imprima
quantos caracteres ela possui. */

/* 
Perceba que o tamanho da string é sempre 1 caractere maior que o digitado (ou 31
se você digitou mais que o limite da variável). Isso ocorre por que a função
`fgets()` lê até o caractere '\0' (incluindo o '\n' quando aperta-se ENTER) ou
até atingir `tamanho-1`.
*/

#include <stdio.h>

int main() {
    char str[32];
    int tamanho_str = 0;
    
    fgets(str, 32, stdin);

    for (size_t i = 0; str[i] != '\0'; i++) {
        tamanho_str++;
    }

    printf("\nQuantidade de caracteres da string: %d\n", tamanho_str);
    
    return 0;
}
