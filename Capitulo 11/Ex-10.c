/* 10) Escreva uma função que receba um valor inteiro positivo N por parâmetro
retorne o ponteiro para um vetor de tamanho N alocado dinamicamente. Esse
vetor deverá ter os seus elementos preenchidos com certo valor, também passado
por parâmetro. Se N for negativo ou igual a zero, um ponteiro nulo deverá ser
retornado. */

#include <stdio.h>
#include <stdlib.h>

int *heap_vetor_int_fill(int N, int fill_vl) {
    int *ptr = NULL;

    if (N > 0) {
        ptr = calloc(N, sizeof *ptr);

        if (fill_vl != 0 && ptr != NULL) {
            while (N-- > 0) {
                ptr[N] = fill_vl;
            }
        }
    }

    return ptr;
}

int main() {
    int *vetor = NULL,
         tamanho = 0,
         valor = 0;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o valor com o qual preencher o vetor: ");
    scanf("%d", &valor);

    vetor = heap_vetor_int_fill(tamanho, valor);

    if (vetor == NULL) {
        printf("\nErro: memoria insuficiente\n");
        return 1;
    }

    printf("\nVetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);
    vetor = NULL;

    return 0;
}
