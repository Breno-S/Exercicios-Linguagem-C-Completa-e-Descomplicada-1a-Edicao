/* 8) Elabore uma função para verificar se um número é um quadrado perfeito. Um
quadrado perfeito é um número inteiro não negativo que pode ser expresso como
o quadrado de outro número inteiro. Exemplos: 1, 4, 9. */

#include <stdio.h>
#include <stdbool.h>

bool is_quadrado_perfeito(int n) {
    if (n == 1) {
        return true;
    }
    
    for (int i = 2; (i*i) <= n; i++) {
        if (i * i == n) {
            return true;
        }
    }

    return false;
}

int main() {
    int num = 0;

    printf("Informe um numero: ");
    scanf("%d", &num);

    if (is_quadrado_perfeito(num)) {
        printf("%d e um quadrado perfeito\n", num);
    } else {
        printf("%d NAO e um quadrado perfeito\n", num);
    }
    
    return 0;
}
