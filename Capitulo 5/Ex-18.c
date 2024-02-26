/* 18) Faça um programa que receba um número inteiro maior do que 1 e verifique
se o número fornecido é primo ou não. */

/* 
Busquei criar um algoritmo juntando ideias que eu já tinha usado com outras
que eu achei na internet, baseadas em algoritmos tradicionais como os crivos.
*/

#include <stdio.h>

int main() {
    int num,
        is_primo = 1;

    do {
        printf("Informe um numero inteiro maior do que 1: ");

        scanf("%d", &num);

        char c;
        while ((c = getchar()) != '\n' && c != EOF) {}

    } while (num <= 1);


    if (num == 2) {     // número 2
        is_primo = 1;
    } else if (num == 1 || num % 2 == 0) {      // 1 e números pares
        is_primo = 0;
    } else if (num < 9) {       // números 3, 5 e 7
        is_primo = 1;
    } else {        // todo o resto
        for (int i = 3; (i*i) <= num; i += 2) {
            if (num % i == 0) {
                is_primo = 0;
                break;
            }
        }
    }

    (is_primo) ? printf("%d e primo", num) : printf("%d nao e primo", num);

    return 0;
}
