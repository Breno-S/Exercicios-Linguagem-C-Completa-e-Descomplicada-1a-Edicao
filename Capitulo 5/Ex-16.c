/* 16) Em matemática, o número harmônico designado por Hn define-se como o
enésimo termo da série harmônica. Ou seja:
    Hn = 1 + 1/2 + 1/3 + 1/4 + ... + 1/n
Apresente um programa que calcule o valor de qualquer Hn. */

#include <stdio.h>

int main() {
    size_t 	num = 0;
    double	harmonico;

    do {
	    printf("Informe o valor de n para calcular seu Numero Harmonico: ");
	    scanf("%zu", &num);

	    int c;
	    while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num == 0);

    for (size_t i = 1; i <= num; i++) {
        harmonico += 1.0 / i;
    }

    printf("H(%zu) = %f\n", num, harmonico);

    return 0;
}
