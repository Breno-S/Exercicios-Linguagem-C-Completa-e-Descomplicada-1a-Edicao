/* 9) Crie uma função que receba uma string e retorne o ponteiro para essa
string invertida. */

#include <stdio.h>
#include <stdlib.h>

#define BUFF_SIZE 64

char *str_invertida(char *str, size_t buff_size);
void retira_newline(char *str, size_t buff_size);

int main() {
    char string[BUFF_SIZE],
        *string_invertida;

    printf("Digite uma string de ate 63 caracteres: ");
    fgets(string, BUFF_SIZE, stdin);
    retira_newline(string, BUFF_SIZE);

    string_invertida = str_invertida(string, BUFF_SIZE);

    if (string_invertida == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    printf("String invertida: %s", string_invertida);

    free(string_invertida);
    string_invertida = NULL;

    return 0;
}

char *str_invertida(char *str, size_t buff_size) {
    char *invertida = NULL;

    size_t strlen;
    for (strlen = 0; strlen < buff_size && str[strlen] != '\0'; strlen++) {}

    invertida = calloc(strlen+1, sizeof(char));

    if (invertida != NULL) {
        for (size_t i = 0; i < strlen; i++) {
            invertida[i] = str[strlen-1 - i];
        }
    }

    return invertida;
}

void retira_newline(char *str, size_t buff_size) {
    for (size_t i = 0; i < buff_size && *(str + i) != '\0'; i++) {
        if (*(str + i) == '\n') {
            *(str + i) = '\0';
        }
    }
}
