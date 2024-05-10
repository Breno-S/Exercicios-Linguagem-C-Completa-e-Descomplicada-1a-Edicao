/* 8) Construa um programa que leia duas strings do teclado. Imprima uma
mensagem informando se a segunda string lida está contida dentro da primeira. */

/*
Este exemplo é case-sensitive e conta os casos de strings sobrepostas (ex: 'ana'
ocorre 2 vezes em 'banana'). O contador `i` é usado no index da string 1, o
contador `j` no index da string 2 e o contador `k` é utilizado como offset na
comparação, isto é, onde a semelhança com a string 2 começa na string 1.
*/

#include <stdio.h>
#include <stdbool.h>    // Define 4 macros para implementar booleanos

int main() {
    char    str1[64],
            str2[64];

    short   tamanho1 = 0,
            tamanho2 = 0;

    int 	i, j, k,
            tamanho_corresp;
    
    bool    has_corresp = false;

    printf("Digite a string 1: ");
    fgets(str1, 64, stdin);

    // Calcula o tamanho da string
    for (int i = 0; str1[i] != '\0'; i++) {
        tamanho1++;
    }

    // Retira o caractere de nova linha
    if (str1[tamanho1-1] == '\n') {
        str1[tamanho1-1] = '\0';
        tamanho1--;
    }

    printf("Digite a string 2: ");
    fgets(str2, 64, stdin);

    // Calcula o tamanho da string
    for (int i = 0; str2[i] != '\0'; i++) {
        tamanho2++;
    }

    // Retira o caractere de nova linha
    if (str2[tamanho2-1] == '\n') {
        str2[tamanho2-1] = '\0';
        tamanho2--;
    }

    if (tamanho2 > 0 && tamanho1 >= tamanho2) {

        // Procura por matches a partir de todos os caracteres matematicamente
        // possíveis de se encontrar
        for (i = 0; i <= tamanho1 - tamanho2; i++) {

            // Se o caractere em questão é igual ao primeiro da string 2
            if (str1[i] == str2[0]) {

                // Começa a comparar a string 2 com a string 1 a partir dele
                for (j = 0, k = i, tamanho_corresp = 0; j < tamanho1; j++, k++){

                    // Verifica se ainda há semelhança
                    if (str1[k] == str2[j]) {
                        tamanho_corresp++;
                        
                        // Se a correspondencia continuar até o final da string
                        // 2, conta como um match
                        if (tamanho_corresp == tamanho2) {
                            has_corresp = true;
                            break;
                        }
                    } else {
                        // Caso pare de haver igualdade entre as strings, sai do
                        // loop e continua procurando no resto da string 1
                        break;
                    }
                }
            }

            if (has_corresp) {
                break;
            }
        }
    }

    if (has_corresp) {
        printf("\nString 2 esta contida na string 1!\n");
    } else {
        printf(
            "\nNenhuma correspondencia da string 2 foi encontrada na string 1.\n"
        );
    }

    return 0;
}
