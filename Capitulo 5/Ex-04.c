/* 4) Faça um programa que determine e mostre os cinco primeiros múltiplos de 3
considerando números maiores que 0. */

#include <stdio.h>

int main() {
    printf("Cinco primeiros multiplos de tres: ");

    for (int i = 3, mult_count = 0; mult_count < 5; i += 3, mult_count++) {
        printf("%d ", i);
    }
    
    printf("\n");

    return 0;
}
