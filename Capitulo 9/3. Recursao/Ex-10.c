/* 10) Escreva uma função recursiva que receba um número inteiro, maior ou igual
a zero, e retorne o enésimo termo da sequência de Fibonacci. Essa sequência
começano termo de ordem zero e, a partir do segundo termo, seu valor é dado
pela soma dos dois termos anteriores. Alguns termos dessa sequência são: 0, 1,
1, 2, 3, 5, 8, 13, 21, 34. */

/*
Conforme o valor de n aumenta, o tempo para computar o resultado também aumenta.
Dependendo do seu PC, isso pode ser bem perceptível.
*/

#include <stdio.h>

unsigned int fibonacci(unsigned int n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int num = -1;
    
    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);
    
    printf("Termo #%d da sequencia de Fibonacci: %u\n", num, fibonacci(num));

    return 0;
}
