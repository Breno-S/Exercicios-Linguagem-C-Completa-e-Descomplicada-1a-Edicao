/* 10) Um arquivo texto possui uma matriz de valores inteiros dentro dele. Os
dois primeiros números são as dimensões da matriz (linhas e colunas), enquanto o
restante dos números são os valores de cada elemento da matriz. Escreva uma
função que receba o nome do arquivo e retorne o ponteiro para uma matriz alocada
dinamicamente contendo os valores lidos do arquivo. */

/*
Para poder imprimir a matriz no terminal, a função retorna um struct com o
tamanho da matriz.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Contém o endereço da matriz e suas dimensões.
typedef struct {
    int **conteudo;
    size_t lin;
    size_t col;
} Matriz;

/* Extrai os elementos presentes no arquivo informado
e retorna um struct do tipo `Matriz`. */
Matriz matriz_arquivo(char *arquivo);

// Libera a memória alocada pela função `matriz_arquivo()`.
void free_matriz_arquivo(Matriz *matriz);

int main() {
    char   nome_arquivo[256] = { 0 };
    Matriz matriz = { 0 };

    do {
        printf("Informe o nome do arquivo que contem a matriz: ");
        fgets(nome_arquivo, 256, stdin);

        // Sanitiza a variável ou o buffer do stdin
        if (nome_arquivo[strlen(nome_arquivo) - 1] == '\n') {
            nome_arquivo[strlen(nome_arquivo) - 1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
        }

        matriz = matriz_arquivo(nome_arquivo);
    } while (matriz.conteudo == NULL);

    for (size_t i = 0; i < matriz.lin; i++) {
        for (size_t j = 0; j < matriz.col; j++) {
            printf("%d\t", matriz.conteudo[i][j]);
        }
        printf("\n");
    }

    free_matriz_arquivo(&matriz);

    matriz.conteudo = NULL;
    
    return 0;
}

Matriz matriz_arquivo(char *arquivo) {
    Matriz M = { 0 };
    FILE  *fp;

    // Tenta abrir o arquivo
    if ((fp = fopen(arquivo, "r")) == NULL) {
        perror("Error");
        return M;
    }

    // Lê as dimensões da matriz
    fscanf(fp, "%zu %zu", &M.lin, &M.col);

    if (M.lin == 0 || M.col == 0) {
        return M;
    }

    // Aloca a matriz
    if ((M.conteudo = calloc(M.lin, sizeof *(M.conteudo))) == NULL) {
        return M;
    }

    if ((M.conteudo[0] = calloc(M.lin * M.col, sizeof **(M.conteudo))) == NULL) {
        return M;
    }

    for (size_t i = 1; i < M.lin; i++) {
        M.conteudo[i] = M.conteudo[0] + i * M.col;
    }
    
    // Lê os elementos da matriz do arquivo para a matriz alocada
    for (size_t i = 0; i < M.lin; i++) {
        for (size_t j = 0; j < M.col; j++) {
            fscanf(fp, "%d", &M.conteudo[i][j]);
        }
    }

    fclose(fp);

    return M;
}

void free_matriz_arquivo(Matriz *matriz) {
    free(matriz->conteudo[0]);
    free(matriz->conteudo);
}
