/* 13) Faça uma função recursiva que calcule o valor da série S descrita a
seguir para um valor n maior do que zero a ser fornecido como parâmetro para a mesma:
    S = 2 + 5/2 + 10/3 + ... + (1 + n^2)/n */

#include <stdio.h>

double serie_s(unsigned n) {
    if (n == 1) {
        return 2;
    }

    return (1 + (double)(n*n))/n + serie_s(n-1);
}

int main() {
    int num = -1;

    printf("S = 2 + 5/2 + 10/3 + ... + (1 + n^2) / n\n");

    do {
        printf("\nInforme o valor de n (maior que zero): ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num <= 0);

    printf("\nS com n valendo %d: %f", num, serie_s(num));

    return 0;
}
