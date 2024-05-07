/* 8) Leia um valor que represente uma temperatura em graus Celsius e
apresente-a convertida em graus Fahrenheit. A fórmula de conversão é:
F = C * (9.0/5.0) + 32.0, sendo F a temperatura em Fahrenheit e C a temperatura
em Celsius. */

#include <stdio.h>

int main() {
    float   T_celsius,
            T_fahrenheit;

    printf("Informe a temperatura em graus Celsius: ");
    scanf("%f", &T_celsius);

    T_fahrenheit = T_celsius * (9.0 / 5.0) + 32;

    printf("%.1f C = %.1f F\n", T_celsius, T_fahrenheit);

    return 0;
}
