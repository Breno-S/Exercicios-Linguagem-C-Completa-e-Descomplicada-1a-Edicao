/* 6) Escreva um programa que aloque dinamicamente uma matriz de inteiros. As
dimensões da matriz deverão ser lidas do usuário. Em seguida, escreva uma função
que receba um valor e retorne 1, caso o valor esteja na matriz, ou retorne 0, no
caso contrário. */

/*
Existem diversos meios de alocar dinamicamente uma matriz. Optei pela terceira
opção descrita no livro, com uma alteração: utiliza-se apenas um variável, do
tipo `int **`.

Se ignorarmos VLAs, que foram adicionados do padrão C99, esta é a melhor opção
para se alocar dinamicamente uma matriz retangular.

Além disso, a função implementa a indexação aritmética (com apenas um colchete).
Assim, tanto arrays estáticos como arrays dinâmicos são aceitos como argumento.

Fonte: https://c-faq.com/aryptr/dynmuldimary.html
*/

#include <stdio.h>
#include <stdlib.h>

int valor_na_matriz(int *matriz, unsigned lin, unsigned col, int valor) {
    for (unsigned i = 0; i < lin; i++) {
        for (unsigned j = 0; j < col; j++) {
            if (matriz[i * col + j] == valor) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    int **matriz = NULL,
          linhas = 0,
          colunas = 0,
          valor = 0;

    while (linhas <= 0) {
        printf("Informe a quantidade de linhas da matriz: ");
        scanf("%d", &linhas);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    while (colunas <= 0) {
        printf("Informe a quantidade de colunas da matriz: ");
        scanf("%d", &colunas);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    // `matriz` aponta para um array de três ponteiros para int.
    matriz = malloc(sizeof *matriz * linhas);

    if (matriz == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }
    
    // O primeiro ponteiro do array aponta para a porção de memória alocada para
    // armazenar toda a matriz
    matriz[0] = malloc(sizeof **matriz * linhas * colunas);

    if (matriz[0] == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    // O restante dos ponteiros apontam para o primeiro elemento de cada linha
    for (int i = 1; i < linhas; i++) {
        matriz[i] = matriz[0] + i * colunas;
    }

    printf("\nMatriz:\n\n");
    int x = 1;
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matriz[i][j] = x++;
            printf("[%d][%d] = %d\n", i, j, matriz[i][j]);
        }
    }

    printf("\nInforme um valor para procurar na matriz: ");
    scanf("%d", &valor);

    if (valor_na_matriz(*matriz, linhas, colunas, valor)) {
        printf("\n%d foi encontrado na matriz", valor);
    } else {
        printf("\n%d nao foi encontrado", valor);
    }

    // Liberar o bloco de memória da matriz e liberar o array de ponteiros
    free(matriz[0]);
    free(matriz);

    matriz = NULL;

    return 0;
}
