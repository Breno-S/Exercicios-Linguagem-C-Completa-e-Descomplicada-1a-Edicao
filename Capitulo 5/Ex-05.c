/* 5) Faça um programa que calcule e mostre a soma dos 50 primeiros números
pares. */

#include <stdio.h>

int main() {
    int soma_total = 0;

    for (int numero = 2, count = 1; count <= 50; numero += 2, count++) {
        soma_total += numero;

        if (count != 50)
            printf("%d + ", numero);
        else
            printf("%d ", numero);
    }

    printf("= %d\n", soma_total);

    return 0;
}
