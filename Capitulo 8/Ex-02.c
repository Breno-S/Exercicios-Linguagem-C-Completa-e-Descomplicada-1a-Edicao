/* 2) Crie uma estrutura para representar as coordenadas de um ponto no plano
(posições X e Y). Em seguida, declare e leia do teclado um ponto e exiba a
distância dele até a origem das coordenadas, isto é, a posição (0,0). */

#include <stdio.h>
#include <math.h>

struct Ponto {
    double x;
    double y;
};

int main() {
    struct Ponto ponto;
    double distancia;

    printf("Informe as coordenadas do ponto\n\n");
    printf("x: ");
    scanf("%lf", &ponto.x);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &ponto.y);

    distancia = sqrt(pow(ponto.x, 2) + pow(ponto.y, 2));

    printf("\nDistancia do ponto a origem: %f\n", distancia);
    
    return 0;
}
 