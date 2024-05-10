/* 11) Leia um conjunto de números reais, armazenando-o em vetor. Em seguida,
calcule o quadrado de cada elemento desse vetor armazenando esse resultado
em outro vetor. Os conjuntos têm, no máximo, 20 elementos. Imprima os dois
conjuntos de números. */

#include <stdio.h>

int main() {
    double          array[20],
                    quadrados[20];
    unsigned char   qtd;

    do {
        printf("Informe quantos numeros deseja armazenar (max 20): ");
        scanf("%d", &qtd);
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (qtd > 20 || qtd < 1);
    
    for (size_t i = 0; i < qtd; i++) {
        printf("#1: ");
        scanf("%lf", &array[i]);

        quadrados[i] = array[i] * array[i];

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    printf("Vetor informado = {");

    for (size_t i = 0; i < qtd-1; i++) {
        printf("%lf, ", array[i]);
    }

    printf("%lf}", array[qtd-1]);

    printf("\nQuadrados = {");
    
    for (size_t i = 0; i < qtd-1; i++) {
        printf("%lf, ", quadrados[i]);
    }

    printf("%lf}\n", quadrados[qtd-1]);

    return 0;
}
