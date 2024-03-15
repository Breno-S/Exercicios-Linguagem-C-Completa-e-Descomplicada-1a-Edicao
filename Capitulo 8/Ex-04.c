/* 4) Crie uma estrutura chamada Retângulo. Essa estrutura deverá conter o ponto
superior esquerdo e o ponto inferior direito do retângulo. Cada ponto é definido
por uma estrutura Ponto, a qual contém as posições X e Y. Faça um programa que
declare e leia uma estrutura Retângulo e exiba a área e o comprimento da
diagonal e o perímetro desse retângulo. */

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

    double  area,
            comprimento_diagonal,
            perimetro;

    double  base,
            altura;
    
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

    // Comprimento diagonal é igual a distancia entre os dois pontos
    comprimento_diagonal = sqrt(
        pow(retangulo.top_left.x - retangulo.bottom_right.x, 2) + 
        pow(retangulo.top_left.y - retangulo.bottom_right.y, 2)
    );

    // Base é a distancia no eixo x
    base = retangulo.bottom_right.x - retangulo.top_left.x;

    // Altura é a distância no eixo y
    altura = retangulo.top_left.y - retangulo.bottom_right.y;

    area = abs(base * altura);

    perimetro = abs(base*2) + abs(altura*2);

    printf("\nPropriedades do retangulo\n\n");
    printf("Area: %f\n", area);
    printf("Comprimento da diagonal: %f\n", comprimento_diagonal);
    printf("Perimetro: %f\n", perimetro);

    return 0;
}
