/* 9) Faça um programa que receba do usuário dois arrays, A e B, com 10 números
inteiros cada. Crie um novo array C calculando C = A - B. Mostre na tela os
dados do array C. */

#include <stdio.h>

int main() {
    int A[10], B[10], C[10];

    printf("Informe os valores do array A\n\n");

    for (size_t i = 0; i < 10; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nInforme os valores do array B\n\n");

    for (size_t i = 0; i < 10; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    for (size_t i = 0; i < 10; i++) {
        C[i] = A[i] - B[i];
    }
    
    printf("\nArray C = {");
    
    for (size_t i = 0; i < 9; i++) {
        printf("%d, ", C[i]);
    }

    printf("%d}", C[9]);

    return 0;
}
