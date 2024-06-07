/* 12) Escreva uma função que receba um vetor e seu tamanho como parâmetros e
salve-a em um arquivo texto de nome “vetor.txt”. Cada valor do vetor deve ser
salvo em uma linha do arquivo. */

#include <stdio.h>

#define SIZE 10

int salva_vetor(int *vetor, size_t tam) {
    FILE *fp;

    if ((fp = fopen("vetor.txt", "w")) == NULL) {
        return 0;
    }

    for (size_t i = 0; i < tam; i++) {
        fprintf(fp, "%d\n", vetor[i]);
    }

    fclose(fp);

    return 1;
}

int main() {
    int vetor[SIZE];

    // Preenche o vetor com valores para teste
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = i*i;
    }

    if (!salva_vetor(vetor, SIZE)) {
        printf("Erro: nao foi possivel salvar o vetor no arquivo.\n");
        return 1;
    }

    printf("Vetor salvo com sucesso em 'vetor.txt'.\n");
    
    return 0;
}
