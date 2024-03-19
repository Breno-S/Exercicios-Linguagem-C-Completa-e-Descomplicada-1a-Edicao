/* 19) Faça uma função que receba como parâmetro o valor de um ângulo em graus e
calcule o valor do cosseno desse ângulo usando a sua respectiva série de Taylor:
em que x é o valor do ângulo em radianos. Considerar π = 3.1414592 e n variando
de 0 até 5. */

#include <stdio.h>
#include <math.h>

// Calcula o fatorial de n.
unsigned long long fatorial(int n);

// Transforma um valor positivo de graus para radianos.
double graus_para_radianos(double graus);

// Calcula o cosseno de um ângulo em graus com a série de Taylor.
double cosseno_por_taylor(double angulo_graus);

int main() {
    int angulo = -1;

    do {
        printf("Informe o angulo em graus para calcular o cosseno: ");
        scanf("%d", &angulo);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (angulo < 0);

    printf(
        "Cosseno de %f = %.3f",
        angulo,
        cosseno_por_taylor(angulo)
    );

    return 0;
}

double graus_para_radianos(double graus) {
    return graus * 3.1415926 / 180.0;
}

unsigned long long fatorial(int n) {
    unsigned long long f = 1;

    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    for (int i = n; i > 0; i--) {
        f *= i;
    }

    return f;
}

double cosseno_por_taylor(double angulo_graus) {
    double radianos = graus_para_radianos(angulo_graus);

    double result = 0;

    for (int n = 0; n <= 5; n++) {
        result += pow(-1, n) / fatorial(2*n) * pow(radianos, 2*n);
    }
    
    return result;
}
