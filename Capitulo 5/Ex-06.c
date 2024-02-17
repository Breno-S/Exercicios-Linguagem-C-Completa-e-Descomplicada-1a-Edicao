/* 6) Faça um programa que mostre uma contagem regressiva na tela, iniciando em
10 e terminando em 0. Mostre uma mensagem “FIM!” após a contagem. */

/*
char é praticamente um int de 8 bits. Em termos de armazenamento (dados binários
na memória) não há diferença.

sizeof(char) = 1 byte = 8 bits
range: signed (-128~127), unsigned (0~255)
*/

#include <stdio.h>

int main() {
    signed char contagem = 10;

    while (contagem >= 0) {
        printf("%d\n", contagem--);
    }

    printf("FIM!");

    return 0;
}

/******************************************************************************
 *                         VERSÃO COM DELAY NA CONTAGEM                       *
 ******************************************************************************/

/*

Utilizando a função time() do cabeçalho <time.h> obtemos um 'timestamp'. Por
meio de comparações com um timestamp mais novo é possível atrasar a execução do
código propositalmente.

*/

/*
#include <stdio.h>
#include <time.h>

int main() {
    signed char contagem = 10;
    time_t      referencia = time(NULL),
                agora;

    while (contagem >= 0) {
        agora = time(NULL);

        if (agora - referencia < 1) {
            continue;
        }

        printf("%d\n", contagem--);
        referencia = time(NULL);
    }

    printf("FIM!");

    return 0;
}
*/
