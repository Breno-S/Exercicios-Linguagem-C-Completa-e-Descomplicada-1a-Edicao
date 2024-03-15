/* 5) Usando a estrutura Retângulo do exercício anterior, faça um programa que
declare e leia uma estrutura Retângulo e um Ponto, e informe se esse ponto está
ou não dentro do retângulo. */

#include <stdio.h>
#include <math.h>

struct Ponto {
    double x;
    double y;
};

struct Retangulo {
    struct Ponto top_left;
    struct Ponto bottom_right;
};

int main() {
    struct Retangulo retangulo;
    struct Ponto ponto;

    printf(
        "Informe as coordenadas do vertice "
        "superior esquerdo do retangulo\n\n"
    );
    
    printf("x: ");
    scanf("%lf", &retangulo.top_left.x);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &retangulo.top_left.y);

    while ((c = getchar()) != '\n' && c != EOF) {}

    printf(
        "\nInforme as coordenadas do vertice "
        "inferior direito do retangulo\n\n"
    );

    printf("x: ");
    scanf("%lf", &retangulo.bottom_right.x);

    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &retangulo.bottom_right.y);

    while ((c = getchar()) != '\n' && c != EOF) {}

    // Se o ponto inferior direito está à esquerda, corrige o valor da abcissa.
    if (retangulo.bottom_right.x < retangulo.top_left.x) {
        int temp = retangulo.bottom_right.x;
        retangulo.bottom_right.x = retangulo.top_left.x;
        retangulo.top_left.x = temp;
    }

    // Se o ponto inferior direito está acima, corrige o valor da ordenada.
    if (retangulo.bottom_right.y > retangulo.top_left.y) {
        int temp = retangulo.bottom_right.y;
        retangulo.bottom_right.y = retangulo.top_left.y;
        retangulo.top_left.y = temp;
    }

    printf("\nAgora informe as coordenadas de um ponto qualquer\n\n");

    printf("x: ");
    scanf("%lf", &ponto.x);
    
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("y: ");
    scanf("%lf", &ponto.y);

    if ((ponto.x > retangulo.top_left.x && ponto.x < retangulo.bottom_right.x)
     && (ponto.y < retangulo.top_left.y && ponto.y > retangulo.bottom_right.y)
    ) {
        printf("\nO ponto esta contido no retangulo.");
    } else {
        printf("\nO ponto nao se encontra dentro do retangulo.");
    }

    return 0;
}
