/* 13) Crie uma função que receba um vetor de tamanho N e ordene os seus
valores. */

/* 
Selection Sort não é recomendado para amostras muito grandes de números. Ainda
assim, é melhor do que o Bubble Sort.
*/

#include <stdio.h>

#define SIZE 10

void ordenar_array(int *array, size_t tamanho) {
    for (size_t i = 0; i < tamanho - 1; i++) {
        int i_menor = i;

        for (size_t j = i + 1; j < tamanho; j++) {
            if (array[j] < array[i_menor]) {
                i_menor = j;
            }
        }

		if (i_menor != i) {
			int temp = array[i];
			array[i] = array[i_menor];
			array[i_menor] = temp;
		}
    }
}

void printar_array(int *array, size_t tamanho) {
    for (size_t i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
}

int main() {
    int vetor[SIZE] = { 0 };

    printf("Informe os valores inteiros do vetor de %d posicoes\n\n", SIZE);

    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        scanf("%d", &vetor[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    ordenar_array(vetor, SIZE);

    printf("\nVetor ordenado em ordem crescente: ");

    printar_array(vetor, SIZE);
    
    printf("\n");

    return 0;
}
