/* 1) Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem crescente. */

/*
O header <stdint.h> define o macro SIZE_MAX, valor máximo do tipo de dado size_t.

size_t == tipo para armazenar tamanhos de objetos. Seu tamanho varia conforme a
arquitetura, mas normalmente possui o maior valor inteiro suportado.

%zu = placeholder do tipo size_t.
*/

#include <stdio.h>
#include <stdint.h> 


int main() {
    size_t num;

    printf("Informe um numero positivo menor que %zu\n\nR:", SIZE_MAX);
    scanf("%zu", &num);

    printf("\n");
    for (size_t i = 0; i <= num; i++) {
        printf("%zu ", i);
    }

    printf("\n");

    return 0;
}
