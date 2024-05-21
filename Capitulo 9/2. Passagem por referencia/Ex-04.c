/* 4) Escreva uma função que receba um array contendo a nota de 10 alunos e
retorne a média dos alunos. */

#include <stdio.h>

double media_array(int *array, size_t tamanho) {
    int m = 0;

    for (size_t i = 0; i < tamanho; i++) {
        m += array[i];
    }

    m /= tamanho;
    
    return m;
}

int main() {
    int array[10];

    printf("Informe as notas dos 10 alunos\n\n");

    for (size_t i = 0; i < 10; i++) {
        printf("#%zu: ", i+1);
        scanf("%d", &array[i]);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    printf("\nMedia: %.2f\n", media_array(array, 10));

    return 0;
}
