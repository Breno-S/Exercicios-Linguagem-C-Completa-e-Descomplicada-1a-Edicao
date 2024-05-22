/* 2) Escreva um programa que contenha duas variáveis inteiras. Leia essas
variáveis do teclado. Em seguida, compare seus endereços e exiba o conteúdo do
maior endereço. */

#include <stdio.h>

int main() {
    int var1, var2;
    int *maior_endereco = (&var1 > &var2) ? &var1 : &var2;

    printf("Informe o valor da primeira variavel: ");
    scanf("%d", &var1);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o valor da segunda variavel: ");
    scanf("%d", &var2);

    printf("\nConteudo do maior endereco: %d\n", *maior_endereco);

    return 0;
}
