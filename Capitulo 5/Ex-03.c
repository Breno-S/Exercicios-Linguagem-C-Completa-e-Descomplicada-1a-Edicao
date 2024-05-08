/* 3) Faça um programa que leia um número inteiro N e depois imprima os N
primeiros números naturais ímpares. */

#include <stdio.h>
#include <stdint.h>

int main() {
    size_t num; 

    printf("Informe um numero positivo menor que %zu\n\nR: ", SIZE_MAX);
    scanf("%zu", &num);

    printf("\n%zu primeiro(s) numero(s) impar(es): ", num);

    for (size_t i = 1, count = 0; count < num; i += 2) {
        printf("%zu ", i);
        count++;
    }

    printf("\n");

    return 0;
}
