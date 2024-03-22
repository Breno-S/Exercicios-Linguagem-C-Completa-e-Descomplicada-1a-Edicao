/* 11) Escreva uma função que receba uma string e converta todos os seus
caracteres em maiúscula. Dica: subtraia 32 dos caracteres cujo código ASCII está
entre 97 e 122. */

#include <stdio.h>

void str_uppercase(char *str, size_t tamanho_max) {
    for (size_t i = 0; i < tamanho_max && str[i] != '\0'; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
}

int main() {
    char string[64];

    printf("Informe uma frase de no maximo 63 caracteres: ");

    fgets(string, 64, stdin);

    str_uppercase(string, 64);

    fputs(string, stdout);

    return 0;
}