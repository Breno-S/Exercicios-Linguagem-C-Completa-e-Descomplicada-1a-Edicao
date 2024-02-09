/* 11) Leia o valor do raio de um círculo. Calcule e imprima a área do círculo
correspondente. A área do círculo é A = π * raio² , sendo π = 3.141592. */

#include <stdio.h>

#define PI 3.141592F 

int main() {
    float   raio,
            area;

    printf("Informe o raio do circulo: ");
    scanf("%f", &raio);
    
    area = PI * (raio * raio);

    printf("Area = %f", area);

    return 0;
}
