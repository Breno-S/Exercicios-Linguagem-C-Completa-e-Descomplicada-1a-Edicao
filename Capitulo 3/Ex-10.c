/* 10) A importância de R$780.000,00 será dividida entre três ganhadores de um
concurso, sendo que:
    i. O primeiro ganhador receberá 46% do total.
    ii. O segundo receberá 32% do total.
    iii. O terceiro receberá o restante.
Calcule e imprima a quantia recebida por cada um dos ganhadores. */

#include <stdio.h>

int main() {
    float   premio_total = 780000,
            premio_1,
            premio_2,
            premio_3;

    premio_1 = premio_total * 46 / 100;
    premio_2 = premio_total * 32 / 100;
    premio_3 = premio_total - (premio_1 + premio_2);

    printf("Primeiro ganhador recebe: R$%.2f\n", premio_1);
    printf("Segindo ganhador recebe: R$%.2f\n", premio_2);
    printf("Terceiro ganhador recebe: R$%.2f\n", premio_3);

    return 0;
}
