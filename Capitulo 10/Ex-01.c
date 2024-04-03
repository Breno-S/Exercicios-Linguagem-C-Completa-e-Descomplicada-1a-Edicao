/* 1) Escreva um programa que contenha duas variáveis inteiras. Compare seus
endereços e exiba o maior endereço */

/*
O endereço da primeira variável é maior que o da segunda e a diferença entre
eles é igual ao tamanho da variável. Isso ocorre porque as variáveis locais são
alocadas na porção de memória chamada stack, que na maioria das arquiteturas
'cresce' do maior endereço de memória para o menor.
*/

#include <stdio.h>

int main() {
    int var1, var2;

    int *maior_endereco = (&var1 > &var2) ? &var1 : &var2;

    printf("Endereco da primeira variavel:\t0x%X\n", &var1);
    printf("Endereco da segunda variavel:\t0x%X\n", &var2);

    printf("\nMaior endereco: 0x%X", maior_endereco);

    return 0;
}
