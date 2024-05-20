/* 13) Escreva uma função que receba um número inteiro positivo n. Calcule e
retorne o somatório de 1 até n: 1 + 2 + 3 + ... + n. */

#include <stdio.h>

long long somatorio_1_ate_n(int n) {
    long long result = 0;

    for (int i = 1; i <= n; i++) {
        result += i;
    }

    return result;
}

int main() {
    int num = 0;

    do {
        printf("Informe um numero natural maior que 0: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 1);

    printf("Somatorio de 1 ate %d = %llu\n", num, somatorio_1_ate_n(num));

    return 0;
}
