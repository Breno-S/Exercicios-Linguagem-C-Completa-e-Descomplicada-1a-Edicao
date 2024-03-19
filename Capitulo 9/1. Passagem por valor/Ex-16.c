/* 16) Elabore uma função que receba como parâmetro um valor inteiro n e gere
como saída um triângulo lateral formado por asteriscos conforme o exemplo a
seguir, em que usamos n = 4:
*
**
***
****
***
**
* */

#include <stdio.h>

void print_triangulo(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }

    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    int num = 0;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    print_triangulo(num);
    return 0;
}
