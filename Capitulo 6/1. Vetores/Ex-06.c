/* 6) Escreva um programa que leia do teclado um vetor de 10 posições. Escreva 
na tela quantos valores pares foram armazenados nesse vetor. */

#include <stdio.h>

int main() {
    int vetor[10] = { 0 },
        total_pares = 0;

    for (int i = 0; i < 10; i++) {
        printf("Informe o valor #%d: ", i+1);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (vetor[i] % 2 == 0) {
            total_pares++;
        }
    }
    
    printf("\nTotal de numeros pares no array: %d", total_pares);

    return 0;
}
