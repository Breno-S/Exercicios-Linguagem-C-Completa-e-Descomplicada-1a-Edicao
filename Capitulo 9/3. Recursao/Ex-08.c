/* 8) A multiplicação de dois números inteiros pode ser feita através de somas
sucessivas (por exemplo, 2 * 3 = 2 + 2 + 2). Crie uma função recursiva que
calcule a multiplicação por somas sucessivas de dois inteiros. */

#include <stdio.h>

int multiplicacao(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }

    if (a < 0 && b > 0) {
        return - (-a + multiplicacao(a, b-1));
    }

    if (b < 0 && a > 0) {
        return - (a + multiplicacao(a, -(b)-1));
    }

    return a + multiplicacao(a, b-1);
}

int main() {
    int fator1 = 0,
        fator2 = 0;

    printf("Informe o primeiro fator da multiplicacao: ");
    scanf("%d", &fator1);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o segundo fator da multiplicacao: ");
    scanf("%d", &fator2);

    printf("%d * %d = %d\n", fator1, fator2, multiplicacao(fator1, fator2));

    return 0;
}
