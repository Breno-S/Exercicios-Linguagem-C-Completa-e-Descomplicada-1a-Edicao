/* 15) Crie uma união contendo dois tipos básicos diferentes. Agora, escreva um
programa que inicialize um dos tipos dessa união e exiba em tela o valor do
outro tipo. */

#include <stdio.h>

typedef union {
    short inteiro_short;
    char caractere;
} Uniao;

int main() {
    Uniao uniao;

    uniao.inteiro_short = 2625;   

    // 2625 = 00001010 01000001
    //                 ^-CHAR-^
    //        ^-----SHORT-----^

    printf("%c ", uniao.caractere);

    putchar('\n');

    return 0;
}
