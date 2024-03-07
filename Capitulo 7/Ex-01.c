/* 1) Faça um programa que leia uma string e a imprima na tela. */

/* 
NUNCA USE A FUNÇÃO GETS()!!!!!!!
*/

#include <stdio.h>

int main() {
    char str[64];
    
    fgets(str, 64, stdin);
    
    fputs(str, stdout);

    return 0;
}
