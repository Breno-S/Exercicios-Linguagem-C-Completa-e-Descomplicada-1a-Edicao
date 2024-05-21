/* 12) Escreva uma função recursiva que receba um valor inteiro em base decimal
e o imprima em base binária. */

#include <stdio.h>

void imprime_em_binario(int num) {
    unsigned char digito = num & 1;

    if (num == 1 || num == 0) {
        printf("%d", digito);
        return;
    }

    imprime_em_binario(num >> 1);

    printf("%d", digito);
}

int main() {
    int num = 0;

    do {
        printf("Informe um numero inteiro: ");
        scanf("%d", &num);

        if (num < 0) {
            num = -num;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    printf("%d em binario: ", num);

    imprime_em_binario(num);

    printf("\n");

    return 0;
}
