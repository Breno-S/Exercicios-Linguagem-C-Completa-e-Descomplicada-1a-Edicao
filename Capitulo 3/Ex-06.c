/* 6) Leia uma velocidade em km/h (quilômetros por hora) e apresente convertida
em m/s (metros por segundo). A fórmula de conversão é M = K/3.6, sendo K a
velocidade em km/h e M em m/s. */

#include <stdio.h>

int main() {
    float	vel_quilometros_hora,
            vel_metros_segundo;

    printf("Informe a velocidade em km/h: ");
    scanf("%f", &vel_quilometros_hora);

    vel_metros_segundo = vel_quilometros_hora / 3.6;

    printf("%.2f km/h = %.2f m/s", vel_quilometros_hora, vel_metros_segundo);

    return 0;
}
