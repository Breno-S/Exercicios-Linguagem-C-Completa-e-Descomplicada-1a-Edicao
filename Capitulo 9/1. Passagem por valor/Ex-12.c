/* 12) Escreva uma função que receba um número inteiro positivo e retorne o
maior fator primo desse número. */

#include <stdio.h>

// Retorna 1 se `n` for um número primo, 0 caso contrário.
int is_primo(int n);

// Retorna o maior fator primo de `n`. Retorna -1 caso não há.
int maior_fator_primo(int n);

int main() {
    int num = -1, maior_primo;

    do {
        printf("Informe um numero natural: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (num < 0);

    if (maior_fator_primo(num) != -1) {
        printf("\nMaior fator primo de %d = %d", num, maior_fator_primo(num));
    } else {
        printf("\n%d nao possui fator primo", num);
    }

    return 0;
}

int is_primo(int n) {
    if (n == 2) {   // número 2
        return 1;
    }
    
    if (n == 1 || n % 2 == 0) {     // 1 e números pares
        return 0;
    }
    
    if (n < 9) {    // números 3, 5 e 7
        return 1;
    }
    
    for (int i = 3; (i*i) <= n; i += 2) {   // todo o resto
        if (n % i == 0) {
            return 0;
        }
    }
}

int maior_fator_primo(int n) {
    int resultado = n;

    if (n < 2) {
        return -1;
    }
    
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) {
            if (is_primo(i)) {
                resultado = i; 
            }
        }
    }

    return resultado;
}
