/* 5) Faça um programa que leia um vetor de oito posições. Em seguida, leia
também dois valores X e Y quaisquer correspondentes a duas posições no vetor.
Seu programa deverá exibir a soma dos valores encontrados nas respectivas
posições X e Y. */

#include <stdio.h>

int main() {
    int vetor[8] = {0},
        x, y;
    
    x = y = 0;

    for (int i = 0; i < 8; i++) {
        printf("Informe o valor #%d: ", i + 1);
        scanf("%d", &vetor[i]);

        // Limpar o stdin após cada leitura do teclado
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    do {
        printf("Agora informe duas posicoes do vetor: ");
        scanf("%d %d", &x, &y);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

    } while ((x > 8 || x <= 0) || (y > 8 || y <= 0));

    printf(
        "Soma dos valores #%d (%d) e #%d (%d) do vetor: %d\n",
        x,
        vetor[x-1],
        y,
        vetor[y-1],
        vetor[x-1] + vetor[y-1]
    );

    return 0;
}
