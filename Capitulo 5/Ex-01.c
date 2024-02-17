/* 1) Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem crescente. */

/*
O header limits.h define macros com os limites de cada tipo de dado

size_t == tipo para armazenar tamanhos de objetos. Seu tamanho varia conforme a
arquitetura, mas normalmente possui o maior valor inteiro suportado.

%llu = placeholder para unsigned long long (o qual o size_t se refere).
*/

#include <stdio.h>
#include <limits.h> 


int main() {
    size_t num;

    printf("Informe um numero positivo menor que %llu\n\nR:", SIZE_MAX);
    scanf("%llu", &num);

    printf("\n");

    for (unsigned long long i = 0; i <= num; i++) {
        printf("%llu ", i);
    }

    return 0;
}
