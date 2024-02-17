/* 2) Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem decrescente. */

#include <stdio.h>
#include <limits.h> 

int main() {
    size_t num;

    printf("Informe um numero positivo menor que %llu\n\nR: ", SIZE_MAX);
    scanf("%llu", &num);

    printf("\n");

    for (size_t i = num+1; i > 0; ) {
        printf("%llu ", --i);
    }

    return 0;
}

/******************************************************************************
 *                            VERSÃO SEM CONTADOR                             *
 ******************************************************************************/

/*
#include <stdio.h>
#include <limits.h> 

int main() {
    size_t num;

    printf("Informe um numero positivo menor que %llu\n\nR: ", SIZE_MAX);
    scanf("%llu", &num);

    printf("\n");

    do {
        printf("%llu ", num--);
    } while (num >= 1);
    
    printf("%llu ", num);

    return 0;
}
*/
