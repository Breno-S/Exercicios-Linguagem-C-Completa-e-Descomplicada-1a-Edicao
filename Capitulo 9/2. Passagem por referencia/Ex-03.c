/* 3) Escreva uma função que receba um array de 10 elementos e retorne a sua
soma. */

#include <stdio.h>

int soma_array(int *array, size_t tamanho) {
    int s = 0;

    for (size_t i = 0; i < tamanho; i++) {
        s += array[i];
    }
    
    return s;
}

int main() {
    int array[10];

    printf("Informe 10 valores para preencher o array\n\n");

    for (size_t i = 0; i < 10; i++) {
        printf("#%d: ", i+1);
        scanf("%d", &array[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("Soma dos elementos do array: %d", soma_array(array, 10));

    return 0;
}
