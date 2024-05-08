/******************************************************************************
 * Ex-08_overengineered.c                                                     *
 *                                                                            *
 * Feito para resolver o mesmo problema do exercício 8 (capítulo 5), porém    *
 * recebendo na chamada do programa os números para fazer o cálculo da média  *
 * (argumentos de linha de comando via argc e argv), podendo ser mais ou      *
 * menos que 10 argumentos.                                                   *
 *                                                                            *
 * Ex: "./programa.exe 10 13 18 20 30"                                        *
 * Ex: "./programa.exe 10 13 18 20 30 49 23 1 3 90 4 23 77 420 69"            *
 *                                                                            *
 * O programa só permite realizar cálculos com números inteiros de magnitude  *
 * uma dezena inferior à maior suportada pelo tipo long long.                 *
 *                                                                            *
 * Ex: "./programa.exe 111111111111111111 -111111111111111111"                *
 *                                                                            *
 * A média é representada como long double para que haja menos erros de       *
 * representação. Se no seu computador a média impressa for sempre 0, então a *
 * função printf() sendo utilizada não implementa long double. Se você        *
 * estiver utilizando mingw, siga as instruções na linha 96 para resolver o   *
 * problema.                                                                  *
 *                                                                            *
 ******************************************************************************/


/********************************** HEADERS ***********************************/

#include <stdio.h>  // Entrada e saida de dados
#include <stdlib.h> // Conversão de dados
#include <ctype.h>  // Validação de caracteres


/********************************** MACROS ************************************/

// Numero padrão a ser lido caso não haja argumentos na chamada do executavel.
#define QTD_PADRAO 10

// Largura do maior valor aceito (incluindo o sinal).
#define QTD_MAX_WIDTH  19


/**************************** DECLARANDO FUNÇÕES ******************************/

// Checa se a string representa um número inteiro.
int check_int(char *);


/*********************************** MAIN *************************************/

int main(int argc, char *argv[]) {
    char        buffer[24] = { '\0' };
    long double media = 0;
    long long   num,
                quantidade = 0;
    int         c,
                is_negativo;

    // Se houver argumentos de linha de comando, adiciona os números inteiros à
    // variavel `media` e depois divide pela quantidade de números
    if (argc > 1) {
        for (size_t i = 1; i < argc; i++) {
            if (check_int(argv[i])) {
                media += atoll(argv[i]);
                quantidade++;
            } else {
                printf("\"%s\" desconsiderado\n", argv[i]);
            }
        }

        media /= quantidade;
    }

    // Senão, pede a quandidade padrão de números inteiros e calcula a média
    else {
        printf("Informe %d numeros para calcular a media:\n\n", QTD_PADRAO);

        for (int i = 0; i < QTD_PADRAO; i++) {
            printf("#%d: ", i+1);
            scanf("%23s", buffer);

            // Limpa o buffer de entrada padrão stdin
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (check_int(buffer)) {
                num = atoll(buffer);
                media += num; 
            } else {
                printf("Valor inserido nao e valido.\n");
                i--;
            }
        }

        media /= QTD_PADRAO;
    } 

    // Comente esta linha se somente 0 é impresso e estiver utilizando minGW
    printf("\nMedia: %Lf\n", media);

    // Descomente esta linha se somente 0 é impresso e estiver utilizando minGW
    // __mingw_printf("\nMedia: %Lf\n", media);

    // Alternativamente, você pode compilar o programa com a opção
    // -D__USE_MINGW_ANSI_STDIO (caso esteja usando o minGW).

    // Ex: 
    // gcc Ex-20.c -D__USE_MINGW_ANSI_STDIO

    // Como último recurso, copie e cole no https://www.onlinegdb.com/

    return 0;
}


/***************************** DEFININDO FUNÇÕES ******************************/

int check_int(char* str) {
/*
 * Retorna 1 se str representar um número inteiro que o programa consegue lidar.
 * Retorna 0 caso contrário.
 */

    int is_negativo = 0;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            if (str[i] == '-' && i == 0) {
                is_negativo = 1;
                continue;
            }
            return 0;
        }

        if ((is_negativo && (i == QTD_MAX_WIDTH)) ||
            (!is_negativo && (i == QTD_MAX_WIDTH-1)) 
        ) {
           return 0; 
        }
    }

    return 1;
}
