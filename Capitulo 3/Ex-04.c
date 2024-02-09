/* 4) Leia quatro valores do tipo float. Calcule e exiba a média aritmética
desses valores. */

#include <stdio.h>

int main() {
    float   a, b, c, d,
            media_aritmetica;

    scanf("%f %f %f %f", &a, &b, &c, &d);

    media_aritmetica = (a + b + c + d) / 4;

    printf("%f", media_aritmetica);

    return 0;
}
