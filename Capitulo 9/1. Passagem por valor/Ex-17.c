/* 17) Faça uma função que receba um inteiro N como parâmetro. Calcule e
retorne o resultado da seguinte série S:
    S = 2/4 + 5/5 + 10/6 + ... + N^2 + 1/N + 3 */

#include <stdio.h>

double serie_S(int n) {
    double result = 0;

    for (int i = 1; i <= n; i++) {
        result += ((i*i)+1.0) / (i + 3.0);
    }

    return result;
}

int main() {
    int num = -1;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num <= 0);

    printf("Resultado: %f\n", serie_S(num));

    return 0;
}
