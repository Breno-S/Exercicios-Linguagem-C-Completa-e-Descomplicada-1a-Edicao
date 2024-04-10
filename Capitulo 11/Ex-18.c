/* 18) Escreva uma função que receba como parâmetro duas matrizes, A e B, e seus
tamanhos. A função deve retornar o ponteiro para uma matriz C, em que C é o
produto da multiplicação da matriz A pela matriz B. Se a multiplicação das
matrizes não for possível, retorne um ponteiro nulo. */

/*
O programa poderia ser decomposto em diversas subrotinas, mas evitei fazer isso
para deixar a função pedida pelo enunciado em evidência.
*/

#include <stdio.h>
#include <stdlib.h>

// Multiplica matrizes de inteiros A e B, e retorna a matriz produto como `int**`.
int **produto_matrizes(int *A, size_t A_lin, size_t A_col,
                       int *B, size_t B_lin, size_t B_col);

// Libera a memória alocada pela função `produto_matrizes()`.
void free_matriz(int **matriz);

int main() {
    int **matriz1 = NULL, linhas1 = 0, colunas1 = 0,
        **matriz2 = NULL, linhas2 = 0, colunas2 = 0,
        **matriz_produto = NULL;

    do {
        while (linhas1 <= 0 || colunas1 <= 0) {
            linhas1 = colunas1 = 0;

            printf("Informe as dimensoes da matriz A no modelo NxN: ");
            scanf("%dx%d", &linhas1, &colunas1);

            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        }

        while (linhas2 <= 0 || colunas2 <= 0) {
            linhas2 = colunas2 = 0;

            printf("\nInforme as dimensoes da matriz B no modelo NxN: ");
            scanf("%dx%d", &linhas2, &colunas2);

            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        }

        if (linhas2 != colunas1) {
            printf(
                "\nMultiplicacao entre matrizes e impossivel "
                "com as dimensoes atuais. Tente outros valores.\n\n"
            );

            linhas1 = colunas1 = linhas2 = colunas2 = 0;
        }

    } while (linhas1 == 0);

    // Alocação da matriz A
    if ((matriz1 = calloc(linhas1, sizeof *matriz1)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    if ((matriz1[0] = calloc(linhas1 * colunas1, sizeof **matriz1)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    for (int i = 1; i < linhas1; i++) {
        matriz1[i] = matriz1[0] + i * colunas1;
    }

    // Alocação da matriz B
    if ((matriz2 = calloc(linhas2, sizeof *matriz2)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    if ((matriz2[0] = calloc(linhas2 * colunas2, sizeof **matriz2)) == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    for (int i = 1; i < linhas2; i++) {
        matriz2[i] = matriz2[0] + i * colunas2;
    }

    printf("\nInforme os valores da matriz A:\n\n");

    for (int i = 0; i < linhas1; i++) {
        for (int j = 0; j < colunas1; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz1[i][j]);

            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    printf("\nInforme os valores da matriz B:\n\n");

    for (int i = 0; i < linhas2; i++) {
        for (int j = 0; j < colunas2; j++) {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);

            int c;
            while((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    matriz_produto = produto_matrizes(
        *matriz1, linhas1, colunas1,
        *matriz2, linhas2, colunas2
    );

    if (matriz_produto == NULL) {
        printf("Erro ao calcular o produto");
        return 2;
    }

    printf("\nMatriz produto C:\n\n");

    for (size_t i = 0; i < linhas1; i++) {
        for (size_t j = 0; j < colunas2; j++) {
            printf("%d\t", matriz_produto[i][j]);
        }
        printf("\n");
    }

    free(matriz1[0]);
    free(matriz1);

    matriz1 = NULL;

    free(matriz2[0]);
    free(matriz2);

    matriz2 = NULL;

    free_matriz(matriz_produto);

    matriz_produto = NULL;

    return 0;
}

int **produto_matrizes(int *A, size_t A_lin, size_t A_col,
                       int *B, size_t B_lin, size_t B_col)
{
    int **C,
          soma;

    if (A_col != B_lin) return NULL;
    
    // Alocação da matriz produto 'C'
    if ((C = calloc(A_lin, sizeof *C)) == NULL) return NULL;

    if ((C[0] = calloc(A_lin * B_col, sizeof **C)) == NULL) return NULL;

    for (int i = 1; i < A_lin; i++) {
        C[i] = C[0] + i * B_col;
    }

    // i = linha de A
    for (int i = 0; i < A_lin; i++) {

        // j = coluna de B
        for (int j = 0; j < B_col; j++) {
            soma = 0;

            // k = coluna de A, linha de B. São os fatores em cada iteração
            for (int k = 0; k < A_col; k++) {
                soma += A[i * A_col + k] * B[k * B_col + j];
            }

            C[i][j] = soma;
        }
    }

    return C;
}

void free_matriz(int **matriz) {
    free(matriz[0]);
    free(matriz);

    matriz = NULL;
}
