/* 7) Elabore um programa que peça ao usuário para digitar 10 valores. Some
esses valores e apresente o resultado na tela. */

#include <stdio.h>

int main() {
    double  num,
            soma;

    printf("Informe 10 numeros para obter a soma.\n\n");

    for (int i = 0; i < 10; i++) {
        printf("#%d: ", i+1);
        scanf("%lf", &num);

        soma += num;
    }

    printf("\nSoma dos numeros: %f\n", soma);

    return 0;
}
