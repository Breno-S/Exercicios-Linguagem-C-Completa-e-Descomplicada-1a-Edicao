/* 1) Escreva um programa que contenha duas variáveis inteiras. Compare seus
endereços e exiba o maior endereço */

/*
Variáveis locais são alocadas no stack frame de sua respectiva função conforme
foram declaradas, entretanto a ordem pode variar com a arquitetura de cada
computador. Logo, só é possível afirmar que a diferença entre os endereços será
igual ao tamanho da variável (int).
*/

#include <stdio.h>

int main() {
    int var1, var2;

    int *maior_endereco = (&var1 > &var2) ? &var1 : &var2;

    printf("Endereco da primeira variavel:\t%p\n", &var1);
    printf("Endereco da segunda variavel:\t%p\n", &var2);

    printf("\nMaior endereco: %p\n", maior_endereco);

    return 0;
}
