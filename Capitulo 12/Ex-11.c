/* 11) Escreva uma função que receba uma matriz e seu tamanho como parâmetros e
salve-a em um arquivo texto de nome “matriz.txt”’. Cada linha da matriz deve ser
salva em uma linha do arquivo. */

#include <stdio.h>

#define LINHAS 3
#define COLUNAS 3

int salva_matriz(int *matriz, size_t lin, size_t col) {
    FILE *fp;

    if ((fp = fopen("matriz.txt", "w")) == NULL) {
        return 0;
    }

    for (size_t i = 0; i < lin; i++) {
        for (size_t j = 0; j < col; j++) {
            fprintf(fp, "%d\t", matriz[i * col + j]);
        }
        fputc('\n', fp);
    }

    fclose(fp);

    return 1;
}

int main() {
    int matriz[LINHAS][COLUNAS];

    // Preenche a matriz com valores para teste
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = j + i;
        }
    }

    if (!salva_matriz(&matriz[0][0], LINHAS, COLUNAS)) {
        printf("Erro: nao foi possivel salvar a matriz no arquivo.\n");
        return 1;
    }

    printf("Matriz salva com sucesso em 'matriz.txt'.\n");
    
    return 0;
}
