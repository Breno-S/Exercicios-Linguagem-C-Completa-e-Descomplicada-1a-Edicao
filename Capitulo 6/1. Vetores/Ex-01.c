/* 1) Crie um programa que leia do teclado seis valores inteiros e em seguida
mostra na tela os valores lidos. */

#include <stdio.h>

int main() {
    int valores[6] = { 0 }; // Inicializa o primeiro elemento do array como 0
                            // e, implicitamente, o resto dele também como 0

    for (int i = 0; i < 6; i++) {
        printf("Informe o valor #%d: ", i + 1);
        scanf(" %d", &valores[i]);

        // Limpar o stdin após cada leitura do teclado
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf(
        "\nValores lidos: {%d, %d, %d, %d, %d, %d}",
        valores[0],
        valores[1],
        valores[2],
        valores[3],
        valores[4],
        valores[5]
    );

    return 0;
}
