/* 3) Escreva uma função que receba por parâmetro uma temperatura em graus
Fahrenheit e a retorne convertida em graus Celsius. A fórmula de conversão é:
C = (F – 32.0) * (5.0/9.0), sendo F a temperatura em Fahrenheit e C a
temperatura em Celsius. */

#include <stdio.h>

float fahrenheit_to_celsius(float t) {
    return (t - 32) * (5.0F/9.0F);
}

int main() {
    float temp_F;

    printf("Informe a temperatura em Fahrenheit: ");
    scanf("%f", &temp_F);

    printf("%.2f F = %.2f C\n", temp_F, fahrenheit_to_celsius(temp_F));

    return 0;
}
