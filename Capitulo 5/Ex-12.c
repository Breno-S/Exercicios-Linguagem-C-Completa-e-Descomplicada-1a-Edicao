/* 12) Escreva um programa que leia um número inteiro e calcule a soma de todos
os divisores desse número, com exceção dele próprio. Exemplo: a soma dos
divisores do número 66 é 1 + 2 + 3 + 6 + 11 + 22 + 33 = 78. */

#include <stdio.h>

int main() {
    int	num = 0,
        soma = 0;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    printf("\n");

    if (num < 0) {
        num *= -1;
    }
    
    if (num == 0) {
        printf("Soma dos divisores de 0: ?");
    } else if (num == 1) {
        printf("Soma dos divisores de 1 exceto ele mesmo: 0");
    } else {
        for (size_t i = 1; i <= num/2; i++) {
            if (num % i == 0) {
                soma += i;
            }
        }

        printf("Soma dos divisores de %d exceto ele mesmo: %d\n", num, soma);
    }

    return 0;
}
