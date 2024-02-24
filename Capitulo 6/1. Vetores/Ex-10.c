/* 10) Faça um programa que preencha um vetor de tamanho 100 com os 100
primeiros números naturais que não são múltiplos de 7. Ao final, imprima esse
vetor na tela. */

#include <stdio.h>

int main() {
    int not_multiplos_7[100];

    char i = 0;
    unsigned char num = 0;

    while (i < 100) {
        if (num % 7 == 0) {
            num++;
            continue;
        }
        
        not_multiplos_7[i++] = num;

        num++;
    }

    printf("Array sem multiplos de 7 = {");
    
    for (size_t i = 0; i < 100; i++) {
        printf("%d, ", not_multiplos_7[i]);
    }

    printf("%d}", not_multiplos_7[99]);


    return 0;
}
