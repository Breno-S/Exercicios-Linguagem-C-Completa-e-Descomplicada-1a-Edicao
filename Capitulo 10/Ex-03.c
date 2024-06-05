/* 3) Crie um programa que contenha um array de float contendo 10 elementos.
Imprima o endereço de cada posição desse array. */

#include <stdio.h>

int main() {
    float array[10];

    for (int i = 0; i < 10; i++) {
        printf("Endereco [%d]: %p\n", i, &array[i]);
    }
    
    return 0;
}
