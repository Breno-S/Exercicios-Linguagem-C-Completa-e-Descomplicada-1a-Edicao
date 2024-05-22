/* 7) Elabore uma função que receba duas strings como parâmetros e verifique se
a segunda string ocorre dentro da primeira. Use aritmética de ponteiros para
acessar os caracteres das strings. */

/*
Semelhante ao exercício 8 do Capítulo 7. Esta função assume que as strings
passadas como argumento serão terminadas por '\0'. No mundo real este nem sempre
é o caso.
*/

#include <stdio.h>
#include <stdbool.h>

bool str_match(const char *, const char *);
void retira_newline(char *);

int main() {
    char string1[64], string2[64];

    printf("Digite uma string: ");
    fgets(string1, 64, stdin);
    retira_newline(string1);

    printf("Digite uma string para buscar dentro da primeira: ");
    fgets(string2, 64, stdin);
    retira_newline(string2);

    if (str_match(string1, string2)) {
        printf("\nA segunda string ocorre na primeira!\n");
    } else {
        printf("\nA segunda string nao foi encontrada na primeira\n");
    }

    return 0;
}

bool str_match(const char *text, const char *str) {
    int     i, j, k,
            tamanho_corresp;
    
    size_t  tamanho1 = 0,
            tamanho2 = 0;

    // Calcula o tamanho do texto
    for (i = 0; *(text + i) != '\0'; i++) {
        tamanho1++;
    }

    // Calcula o tamanho da string
    for (i = 0; *(str + i) != '\0'; i++) {
        tamanho2++;
    }

    if (tamanho2 > 0 && tamanho1 >= tamanho2) {

        // Procura por matches a partir de todos os caracteres matematicamente
        // possíveis de se encontrar
        for (i = 0; i <= tamanho1 - tamanho2; i++) {

            // Se o caractere em questão é igual ao primeiro da string
            if (*(text + i) == *str) {

                // Começa a comparar a string com o texto a partir dele
                for (j = 0, k = i, tamanho_corresp = 0; j < tamanho1; j++, k++){

                    // Verifica se ainda há semelhança
                    if (*(text + k) == *(str + j)) {
                        tamanho_corresp++;
                        
                        // Se a correspondencia continuar até o final da string,
                        // conta como um match
                        if (tamanho_corresp == tamanho2) {
                            return true;
                        }
                    } else {
                        // Caso pare de haver igualdade, sai do loop e continua 
                        // procurando no resto do texto
                        break;
                    }
                }
            }
        }
    }

    return false;
}

void retira_newline(char *str) {
    for (size_t i = 0; *(str + i) != '\0'; i++) {
        if (*(str + i) == '\n') {
            *(str + i) = '\0';
        }
    }
}
