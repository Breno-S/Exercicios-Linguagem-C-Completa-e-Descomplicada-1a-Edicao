/* 7) Crie uma estrutura representando uma hora. Essa estrutura deve conter os
campos hora, minuto e segundo. Agora, escreva um programa que leia um vetor de
cinco posições dessa estrutura e imprima a maior hora. */

#include <stdio.h>

struct Hora {
    unsigned short horas;
    unsigned short minutos;
    unsigned short segundos;
};

int main() {
    struct Hora hora[5];
    int indice_maior_horario = 0;

    printf("Informe cinco horarios diferentes no formato hh:mm:ss\n\n");

    for (int i = 0; i < 5; i++) {
        // Loop infinito
        while (1) {
            // Inicializa os campos da estrutura com valores inválidos
            hora[i].horas = 24;
            hora[i].minutos = 60;
            hora[i].segundos = 60;

            printf("#%d: ", i+1);
            scanf(
                "%2hu:%2hu:%2hu",
                &hora[i].horas,
                &hora[i].minutos,
                &hora[i].segundos
            );

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            // Checa se os valores que acabaram de ser lidos são válidos
            if (
                (hora[i].horas >= 24) ||
                (hora[i].minutos >= 60) ||
                (hora[i].segundos >= 60)
            ) {
                printf("\nHora invalida. Digite novamente.\n\n");
            } else {
                break;
            }
        }
    }

    // Compara as horas, os minutos e os segundos de cada horario
    for (size_t i = 1; i < 5; i++) {
        if (hora[i].horas > hora[indice_maior_horario].horas) {

            indice_maior_horario = i;

        } else if (hora[i].horas == hora[indice_maior_horario].horas) {

            if (hora[i].minutos > hora[indice_maior_horario].minutos) {
            
                indice_maior_horario = i;

            } else if (hora[i].minutos == hora[indice_maior_horario].minutos) {

                if (hora[i].segundos > hora[indice_maior_horario].segundos) {

                    indice_maior_horario = i;

                }
            }
        }
    }

    printf(
        "\nMaior horario: %02hu:%02hu:%02hu\n",
        hora[indice_maior_horario].horas,
        hora[indice_maior_horario].minutos,
        hora[indice_maior_horario].segundos
    );
    
    return 0;
}
