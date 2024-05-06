/* 3) Escreva um programa que leia um número inteiro e depois imprima a mensagem 
“Valor lido:”, seguido do valor inteiro. Use apenas um comando printf(). */

#include <stdio.h>

int main() {
    int numero_inteiro;

    scanf("%d", &numero_inteiro);

    printf("Valor lido: %d\n", numero_inteiro);

    return 0;
}
