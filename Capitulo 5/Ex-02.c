/* 2) Faça um programa que leia um número inteiro positivo N e imprima todos os
números naturais de 0 até N em ordem decrescente. */

#include <stdio.h>
#include <stdint.h> 

int main() {
    size_t num;

    printf("Informe um numero positivo menor que %zu\n\nR: ", SIZE_MAX);
    scanf("%zu", &num);

    printf("\n");

    for (size_t i = num+1; i > 0; ) {
        printf("%zu ", --i);
    }

    printf("\n");

    return 0;
}

/******************************************************************************
 *                            VERSÃO SEM CONTADOR                             *
 ******************************************************************************/

/*
#include <stdio.h>
#include <stdint.h> 

int main() {
    size_t num;

    printf("Informe um numero positivo menor que %zu\n\nR: ", SIZE_MAX);
    scanf("%zu", &num);

    printf("\n");

    do {
        printf("%zu ", num--);
    } while (num >= 1);
    
    printf("%zu\n", num);

    return 0;
}
*/
