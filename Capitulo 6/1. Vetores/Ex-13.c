/* 13) Faça um programa para ler 10 números diferentes a serem armazenados em um
vetor. Os números deverão ser armazenados no vetor na ordem em que forem lidos,
sendo que, caso o usuário digite um número que já foi digitado anteriormente, o
programa deverá pedir a ele para digitar outro número. Note que cada valor
digitado pelo usuário deve ser pesquisado no vetor, verificando se ele existe
entre os números que já foram fornecidos. Exiba na tela o vetor final que foi
digitado. */

#include <stdio.h>

int main() {
    double  vetor[10] = { 0 }, 
            num = 0;
    char    is_repetido = 0;

    printf("Preencha o array com 10 valores\n\n");
    printf("Valor #1: ");
    scanf("%lf", &vetor[0]);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    char i = 1;
    while (i < 10) {
        printf("Valor #%d: ", i + 1);
        scanf("%lf", &num);

        while ((c = getchar()) != '\n' && c != EOF) {}

        for (char j = 0; j < i; j++) {
            if (vetor[j] == num) {
                printf("\nValor repetido. Digite novamente.\n\n");
                is_repetido = 1;
                break;
            }

            is_repetido = 0;
        }

        if (is_repetido) {
            continue;
        }        

        vetor[i] = num;
        i++;
    }

    printf("\nArray final:\n\n");

    for (char i = 0; i < 10; i++) {
        printf("[%d] = %lf\n", i, vetor[i]);
    }

    return 0;
}
