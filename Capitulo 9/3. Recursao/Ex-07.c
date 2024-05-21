/* 7) Escreva uma função recursiva que receba por parâmetro dois valores
inteiros x e y e calcule e retorne o resultado de x^y para o programa principal.
*/

#include <stdio.h>

int potenciacao(int x, int y) {
    if (y == 0) {
        return 1;
    }
    
    if (y < 0) {
        return 1.0 / potenciacao(x, -(y));
    }
    
    if (y > 0) {
        return x * potenciacao(x, y-1);
    }
    
    return x * potenciacao(x, y-1);
}

int main() {
    int base = 0,
        exp = 0;

    printf("Informe a base da exponenciacao: ");
    scanf("%d", &base);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o expoente: ");
    scanf("%d", &exp);

    printf("%d ^ %d = %d\n", base, exp, potenciacao(base,exp));

    return 0;
}
