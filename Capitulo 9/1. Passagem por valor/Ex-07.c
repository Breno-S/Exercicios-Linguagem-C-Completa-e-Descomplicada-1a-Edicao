/* 7) Elabore uma função que receba três números inteiros como parâmetro,
representando horas, minutos e segundos. A função deve retornar esse horário
convertido em segundos. */

#include <stdio.h>

long time_to_seconds(int h, int m, int s) {
    return (h * 3600 + m * 60 + s);
}

int main() {
    int horas = -1,
        minutos = -1,
        segundos = -1;  

    int hora_valida;

    printf("Informe uma quantidade de tempo no formato hh:mm:ss \n\n");

    while (1) {
        horas = -1;
        minutos = -1;
        segundos = -1;

        scanf("%2d:%2d:%2d", &horas, &minutos, &segundos);

        if ((horas < 0) ||
            (minutos < 0 || minutos > 59) ||
            (segundos < 0 || minutos > 59)
        ) {
            printf("\nHora invalida. Tente Novamente\n\n");
        } else {
            break;
        }
    }

    while (minutos < 0 || minutos > 59) {
        minutos = -1;
        printf("Informe a quantidade de minutos (59 max): ");
        scanf("%d", &minutos);
    }

    while (segundos < 0 || minutos > 59) {
        segundos = -1;
        printf("Informe a quantidade de segundos (59 max): ");
        scanf("%d", &segundos);
    }

    printf(
        "\n%.2d:%.2d:%.2d e igual a %ld segundos decorridos",
        horas,
        minutos,
        segundos,
        time_to_seconds(horas, minutos, segundos)
    );

    return 0;
}
