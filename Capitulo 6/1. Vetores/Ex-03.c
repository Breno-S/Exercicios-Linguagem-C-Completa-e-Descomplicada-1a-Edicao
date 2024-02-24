/* 3) Faça um programa que leia cinco valores e os armazene em um vetor. Em
seguida, mostre todos os valores lidos juntamente com a média dos valores. */

#include <stdio.h>

int main() {
    float   valores[5] = { 0 },
            media;

    for (int i = 0; i < 5; i++) {
        printf("Informe o valor #%d: ", i + 1);
        scanf("%f", &valores[i]);

        // Limpar o stdin após cada leitura do teclado
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        media+= valores[i];
    }

    media /= 5.0;

    printf(
        "\nValores lidos: {%f, %f, %f, %f, %f}",
        valores[0],
        valores[1],
        valores[2],
        valores[3],
        valores[4]
    );

    printf("\nMedia: %f", media);

    return 0;
}
