/* 15) Em matemática, o número harmônico designado por Hn define-se como o
enésimo termo da série harmônica. Ou seja:
    Hn = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
Escreva uma função recursiva que calcule o valor de qualquer Hn. */

#include <stdio.h>

double harmonico(unsigned int n) {
    if (n == 1) {
        return 1;
    }

    double parcial = 1.0 / n;

    return parcial + harmonico(n-1);
}

int main() {
    int num = -1;

    do {
        printf("Informe qual numero harmonico imprimir: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num <= 0);

    printf("Hn de %d: %f\n", num, harmonico(num));

    return 0;
}
