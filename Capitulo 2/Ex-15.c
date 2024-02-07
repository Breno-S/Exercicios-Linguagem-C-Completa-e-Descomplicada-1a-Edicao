/* 15) Escreva um programa que leia três variáveis: char, int e float. Em
seguida, imprima as de três maneiras diferentes: separadas por espaços, por uma
tabulação horizontal e uma em cada linha. Use um único comando printf() para
cada operação de escrita das três variáveis. */

/*

Teste diversos valores para cada uma das variáveis, separando com espaços,
ENTERs, sem separar, invertendo a ordem dos valores, omitindo valores; para
entender o comportamento das funções de scanf e printf.

*/

#include <stdio.h>

int main() {
    char    caractere;
    int     inteiro;
    float   real;

    scanf("%c %d %f", &caractere, &inteiro, &real);

    printf("%c %d %f", caractere, inteiro, real);

    return 0;
}
