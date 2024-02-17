/* 16) Em matemática, o número harmônico designado por Hn define-se como o
enésimo termo da série harmônica. Ou seja:
    Hn = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
Apresente um programa que calcule o valor de qualquer Hn. */

#include <stdio.h>

int main() {
    size_t 	num;
    double	harmonico;

    harmonico = 1.0;

    printf("Informe o valor de n para calcular o Numero Harmonico de n: ");
    scanf("%llu", &num);

    for (size_t i = 2; i <= num; i++) {
        harmonico += 1.0 / i;
    }

    printf("H(%llu) = %f", num, harmonico);

    return 0;
}
