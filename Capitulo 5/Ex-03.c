/* 3) Faça um programa que leia um número inteiro N e depois imprima os N
primeiros números naturais ímpares. */

#include <stdio.h>
#include <limits.h>

int main() {
    size_t num; 

    printf("Informe um numero positivo menor que %llu\n\nR: ", SIZE_MAX);
    scanf("%llu", &num);

    printf("\n%llu primeiro(s) numero(s) impar(es): ", num);

    for (size_t i = 1, count = 0; count < num; i += 2) {
        printf("%llu ", i);
        count++;
    }

    return 0;
}
