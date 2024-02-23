/* 11) Faça um algoritmo que leia um número positivo e imprima seus divisores.
Exemplo: os divisores do número 66 são: 1, 2, 3, 6, 11, 22, 33 e 66. */

#include <stdio.h>

int main() {
    unsigned num = 0;

    do {
        printf("Informe um numero inteiro e positivo: ");
        scanf("%u", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);
    
    printf("\n");
    
    if (num == 0) {
        printf("Divisores de 0: Conjunto dos numeros reais.");
    } else if (num == 1) {
        printf("Divisores de 1: 1");
    } else {
        printf("Divisores de %u: ", num);
        for (size_t i = 1; i <= num/2; i++) {
            if (num % i == 0) {
                printf("%llu, ", i);
            }
        }

        printf("%d", num);
    }

    return 0;
}
