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
    for (char i = 0; i < 10; i++) {
        for (char j = i+1; j < 10; j++) {
            if (vetor[i] > vetor[j]) {
                float temp = vetor[j];
                vetor[j] = vetor[i];
                vetor[i] = temp;
            }
        }
    }

    printf("Array ordenado: {");

    for (char i = 0; i < 9; i++) {
        printf("%f, ", vetor[i]);
    }

    printf("%f}", vetor[9]);

    return 0;
}
