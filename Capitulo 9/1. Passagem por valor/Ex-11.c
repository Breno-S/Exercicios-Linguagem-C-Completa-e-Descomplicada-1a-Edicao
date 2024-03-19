/* 11) Escreva uma função que receba por parâmetros dois valores inteiros x e y
e calcule e retorne o resultado de x^y para o programa principal. Não use
nenhuma função pronta para isso. */

#include <stdio.h>

double my_pow(int x, int y) {
    double resultado = 1;

    if (x == 1) {
        return 1;
    } else if (y > 0) {
        for (; y > 0; y--) {
            resultado *= x;
        }
    } else if (y < 0) {
        for (; y < 0; y++) {
            resultado *= x;
        }

        resultado = 1 / resultado;
    }

    return resultado;
}

int main() {
    int base = 0,
        exp = 0;

    printf("Informe a base da exponenciacao: ");
    scanf("%d", &base);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o exponente: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %f", base, exp, my_pow(base,exp));

    return 0;
}
