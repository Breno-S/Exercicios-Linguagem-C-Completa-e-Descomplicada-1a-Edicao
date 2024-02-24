/* 2) Crie um programa que leia do teclado seis valores inteiros e em seguida
mostre na tela os valores lidos na ordem inversa. */

#include <stdio.h>

int main() {
    int valores[6] = { 0 };

    for (char i = 0; i < 6; i++) {
        printf("Informe o valor #%d: ", i + 1);
        scanf("%d", &valores[i]);

        // Limpar o stdin após cada leitura do teclado
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf(
        "Valores lidos em ordem reversa: {%d, %d, %d, %d, %d, %d}",
        valores[5],
        valores[4],
        valores[3],
        valores[2],
        valores[1],
        valores[0]
    );

    return 0;
}
