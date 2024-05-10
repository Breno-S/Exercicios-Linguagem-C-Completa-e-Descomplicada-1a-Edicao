/* 6) Leia uma string do teclado e conte quantas vogais (a, e, i, o, u) ela
possui. Entre com um caractere (vogal ou consoante) e substitua todas as vogais
da palavra dada por esse caractere. Ao final, imprima a nova string e o número
de vogais que ela possui.*/

#include <stdio.h>
#include <string.h>

int main() {
    char    str[64],
            vogais[10] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};

    int     tamanho_str,
            qtd_vogais = 0;

    printf("Digite uma frase com no maximo 63 caracteres: ");

    fgets(str, 64, stdin);

    tamanho_str = strlen(str);

    // Retira o caractere de nova linha para não imprimi-lo depois
    if (str[tamanho_str-1] == '\n') {
        str[tamanho_str-1] = '\0';
        tamanho_str--;
    }

    // Para cada caractere da string checa se é uma vogal
    for (size_t i = 0; i < tamanho_str; i++) {
        for (size_t j = 0; j < 10; j++) {
            if (str[i] == vogais[j]) {
                qtd_vogais++;
                break;
            }
        }
    }

    printf("Quantidade de vogais [nao acentuadas] na string: %d\n", qtd_vogais);

    return 0;
}
