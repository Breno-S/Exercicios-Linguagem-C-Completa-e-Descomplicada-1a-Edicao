/* 1) Escreva um programa que mostre o tamanho em byte que cada tipo de dados
ocupa na memória: char, int, float, double. */

#include <stdio.h>

int main() {
    printf("Tamanho de cada tipo primitivo em bytes:\n\n");
    printf("char: %llu\n", sizeof(char));
    printf("int: %llu\n", sizeof(int));
    printf("float: %llu\n", sizeof(float));
    printf("double: %llu\n", sizeof(double));

    return 0;
}
