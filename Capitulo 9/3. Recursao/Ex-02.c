/* 2) Crie uma função recursiva que receba um número inteiro N e retorne o
somatório dos números de 1 a N. */

#include <stdio.h>

long long somatorio(int n) {
    if (n == 1) {
        return n;
    }

    if (n <= 0) {
        return n + somatorio(n+1);
    }
    
    return n + somatorio(n-1);
}

int main() {
    int num = 0;
        
    printf("Somatorio de 1 ate n, informe o valor de n: ");
    scanf("%d", &num);

    printf(
        "Somatorio de %d ate %d: %lld",
        (num < 1) ? num : 1,
        (num < 1) ? 1 : num,
        somatorio(num)
    );

    return 0;
}
