/* 3) Crie uma estrutura para representar as coordenadas de um ponto no plano
(posições X e Y). Em seguida, declare e leia do teclado dois pontos e exiba a
distância entre eles. */

#include <stdio.h>
#include <math.h>

struct Ponto {
    double x;
    double y;
} ponto1, ponto2;

int main() {
    double distancia;

    printf("Informe as coordenadas do primeiro ponto\n\n");
    printf("x: ");
    scanf("%lf", &ponto1.x);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &ponto1.y);

    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("\nInforme as coordenadas do segundo ponto\n\n");
    printf("x: ");
    scanf("%lf", &ponto2.x);

    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &ponto2.y);

    distancia = sqrt(pow(ponto1.x - ponto2.x, 2) + pow(ponto1.y - ponto2.y, 2));

    printf("\nDistancia entre os dois pontos: %f", distancia);
    
    return 0;
}
 