/* 14) Faça um programa para verificar se determinado número inteiro lido é
divisível por 3 ou 5, mas não simultaneamente pelos dois. */

#include <stdio.h>

int main() {
    int num;

    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    if ( ((num % 3 == 0) && !(num % 5 == 0)) ||
         ((num % 5 == 0) && !(num % 3 == 0)) ) 
    {
        printf(
            "%d e divisivel por 3 ou 5, "
            "mas nao simultaneamente pelos dois.",
            num
        );
    } else {
        printf(
            "%d ou e simultaneamente divisivel por 3 e 5, "
            "ou nao e divisivel pelos dois.",
            num
        );
    }

    return 0;
}
