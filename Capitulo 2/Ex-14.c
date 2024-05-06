/* 14) Faça um programa que leia três caracteres do tipo char e depois os
imprima um em cada linha. Use um único comando printf() para isso. */

/*
Neste exercício notamos o problema de obter valores pelo teclado de forma
consecutiva. As funções de leitura de caractere obtêm o primeiro caractere do
buffer de entrada e não limpam o resto dele. Dessa forma, qualquer caractere
extra permanece no buffer; inclusive o caractere de nova linha '\n', que é
inserido quando apertamos ENTER para "enviar" do terminal para o programa.
Esses caracteres restantes podem acabar sendo lidos acidentalmente, em funções
de leitura seguintes.

Para evitar isso, devemos limpar o buffer de entrada entre as leituras do
teclado (quando houver sobras no buffer).

Existem algumas funções que fazem essa limpeza, porém elas se comportam de
maneira diferente entre os sistemas operacionais. Portanto o método mais
portátil de limpar o buffer de entrada é o seguinte:

    int c;
    while ( (c = getchar()) != '\n' && c != EOF) {}

Resumidamente, este código cria um loop sem bloco de execução que simplesmente
"recolhe" os caracteres do buffer até que encontre o caractere de nova linha
('\n') ou o fim do arquivo (EOF).
*/

#include <stdio.h>

int main() {
    char char1, char2, char3;

    scanf("%c", &char1);
    scanf("%c", &char2);
    scanf("%c", &char3);

    printf("\n%c\n%c\n%c\n", char1, char2, char3);

    return 0;
}
