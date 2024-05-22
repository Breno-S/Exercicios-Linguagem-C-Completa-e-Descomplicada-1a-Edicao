/* 1) Escreva um programa que mostre o tamanho em byte que cada tipo de dados
ocupa na memória: char, int, float, double. */

#include <stdio.h>

int main() {
    printf("Tamanho de cada tipo primitivo em bytes:\n\n");
    printf("char: %zu\n", sizeof(char));
    printf("int: %zu\n", sizeof(int));
    printf("float: %zu\n", sizeof(float));
    printf("double: %zu\n", sizeof(double));

    return 0;
}
