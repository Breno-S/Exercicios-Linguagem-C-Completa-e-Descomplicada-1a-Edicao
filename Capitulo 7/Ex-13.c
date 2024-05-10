/* 13) Escreva um programa que recebe uma string S e dois valores inteiros não
negativos i e j. Em seguida, imprima os caracteres contidos no segmento que vai
de i a j da string S. */

#include <stdio.h>

int main() {
    char    S[64];
    int     i, j,
            tamanho_str;

    i = j = 0;

    printf("Informe a string: ");
    fgets(S, 64, stdin);

    // Conta o tamanho da string
    for (tamanho_str = 0; S[tamanho_str] != '\0'; tamanho_str++) {}

    // Se a string foi contida com folga, substitui '\n' por '\0'
    if (S[tamanho_str-1] == '\n') {
        S[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    // Senão limpa o que restou no buffer de entrada
    else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
     
    printf("\nString: \"%s\"\n", S);
    printf("Tamanho: %d\n\n", tamanho_str);

    do {
        printf(
            "Informe um offset de inicio (min = 0 / max = %d): ",
            tamanho_str-1
        );
        scanf("%d", &i);
    } while (i > tamanho_str-1 || i < 0);

    do {
        printf(
            "Informe a posicao final (min = %d / max = %d): ",
            i,
            tamanho_str-1
        );
        scanf("%d", &j);
    } while (j > tamanho_str-1 || j < i);

    printf("\nString: final: ");

    // Imprime os caracteres a partir do offset de início, até o offset final
    for (; i <= j && S[i] != '\0'; i++) {
        putchar(S[i]);
    }

    printf("\n");

    return 0;
}
