/* 16) Elabore uma função que receba um vetor contendo N valores e retorne por
referência o maior elemento do vetor e o número de vezes que esse elemento
ocorreu no vetor. */

#include <stdio.h>

#define SIZE 10

int num_ocorrencias_maior(int *array, size_t tamanho, int *maior_valor) {
    size_t count = 1;
    *maior_valor = array[0];
    
    for (size_t i = 0; i < tamanho; i++) {
        if (array[i] > *maior_valor) {
            *maior_valor = array[i];
            count = 1;
        } else if (array[i] == *maior_valor) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int vetor[SIZE] = { 0 },
        maior_elemento,
        count_maior;

    printf("Informe os valores inteiros do vetor de %d posicoes\n\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    count_maior = num_ocorrencias_maior(vetor, SIZE, &maior_elemento);

    printf("\nMaior elemento do vetor: %d", maior_elemento);
    printf("\nNumero de ocorrencias do elemento: %d\n", count_maior);

    return 0;
}
