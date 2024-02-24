/* 8) Faça um programa que preencha um vetor com 10 números reais. Em seguida,
calcule e mostre na tela a quantidade de números negativos e a soma dos números
positivos desse vetor. */

#include <stdio.h>

int main() {
    float   vetor[10] = { 0 },
            soma_positivos = 0;
    
    int     qtd_negativos = 0;


    printf("Digite 10 numeros reais:\n");

    for (int i = 0; i < 10; i++) {
        printf("Valor #%d: ", i+1);
        scanf("%f", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    for (int i = 0; i < 10; i++) {
        if (vetor[i] < 0) {
            qtd_negativos++;
        } else if (vetor > 0) {
            soma_positivos += vetor[i];
        }
    }

    printf("\nQuantidade de numeros negativos: %d\n", qtd_negativos);
    printf("Soma dos numeros positivos: %f", soma_positivos);
    

    return 0;
}
