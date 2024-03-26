/* 11) Escreva uma função recursiva que receba um valor inteiro e o retorne
invertido.
Exemplo: 
    Número lido = 123.
    Número retornado = 321. */

#include <stdio.h>

int invertido(int n) {
    unsigned magnitude = 10;

    if (n < 10) {
        return n;
    }

    while (magnitude*10 <= n) {
        magnitude *= 10;
    }

    return (n % 10) * magnitude + invertido(n/10);
}

int main() {
    int num = -1;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    printf("Numero invertido: %d", invertido(num));
    
    return 0;
}
