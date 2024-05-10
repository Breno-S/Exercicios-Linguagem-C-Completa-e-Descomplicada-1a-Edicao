/* 15) Leia um vetor com 10 números de ponto flutuante. Em seguida, ordene os
elementos desse vetor e imprima o vetor na tela */

#include <stdio.h>

int main() {
    float vetor[10];

    printf("Informe os valores do array:\n");

    for (char i = 0; i < 10; i++) {
        printf("[%d]: ", i);
        scanf("%f", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    // Bubble Sort (ineficiente)
    for (char i = 0; i < 9; i++) {
        for (char j = 0; j < 9 - i; j++) {
            if (vetor[j] > vetor[j+1]) {
                float temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }

    printf("\nArray ordenado: {");

    for (char i = 0; i < 9; i++) {
        printf("%f, ", vetor[i]);
    }

    printf("%f}\n", vetor[9]);

    return 0;
}
