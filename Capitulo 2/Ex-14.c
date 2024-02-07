/* 14) Faça um programa que leia três caracteres do tipo char e depois os
imprima um em cada linha. Use um único comando printf() para isso. */

/*

Neste exercício notamos os problemas de obter valores pelo teclado de forma
consecutiva. As funções de leitura de caractere obtêm o primeiro caractere do
buffer de entrada e não limpam o resto dele. Dessa forma, qualquer caractere
extra fica armazenado no buffer e é lido pela próxima função de leitura de
dados; isso inclui o caractere de nova linha '\n', que é inserido quando
apertamos ENTER no teclado.

Existem diversas soluções para este problema, mas muitas delas envolvem o uso
de funções que não são compatíveis com todos os sistemas operacionais. A
solução mais portátil para limpar o buffer de entrada é a seguinte:

    int c;
    while ( (c = getchar()) != '\n' && c != EOF) {}

Resumidamente, este código cria um loop sem bloco de execução que simplesmente
"recolhe" os caracteres do buffer até que encontre o fim da string ('\n') ou o
fim do arquivo (EOF).

*/

#include <stdio.h>

int main() {
    char char1, char2, char3;

    scanf("%c", &char1);
    scanf("%c", &char2);
    scanf("%c", &char3);

    printf("%c\n%c\n%c", char1, char2, char3);

    return 0;
}
