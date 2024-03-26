/* 3) Crie uma função recursiva que receba um número inteiro N e imprima todos
os números naturais de 0 até N em ordem crescente. */

#include <stdio.h>

void print_naturais_ate_n(int n) {
    if (n <= 0) {
        printf("0 ");
        return;
    }

    if (n < 0) {
        printf("%d ", n);
        print_naturais_ate_n(n+1);
    }
    
    if (n > 0) {
        print_naturais_ate_n(n-1);
        printf("%d ", n);
    }
}

int main() {
    int num = 0;

    printf(
        "Numeros naturais de 0 ate n em ordem crescente, "
        "informe o valor de n: "
    );

    scanf("%d", &num);

    print_naturais_ate_n(num);

    return 0;
}
