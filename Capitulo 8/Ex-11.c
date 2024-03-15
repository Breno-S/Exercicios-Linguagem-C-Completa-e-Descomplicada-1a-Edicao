/* 11) Escreva um programa que contenha uma estrutura representando uma data
válida. Essa estrutura deve conter os campos dia, mês e ano. Em seguida, leia
duas datas e armazene nessa estrutura. Calcule e exiba o número de dias que
decorreram entre as duas data */

#include <stdio.h>
#include <math.h>

enum {
    PRIMEIRA,
    SEGUNDA
};

struct Data {
    unsigned char dia;
    unsigned char mes;
    unsigned ano;
};

int main() {
    struct Data data[2] = { 0 };

    int	diff_total = 0,         // Quantidade total de dias entre as datas.
        qtd_meses_completos = 0,// Meses inteiros entre as duas datas.
        qtd_dias_completos = 0, // Dias entre as datas e os meses adjacentes.
        i_menor,                // Índice da menor data.
        i_maior,                // Índice da maior data.
        data_valida;            // Booleano para armazenar a validade da data.

    printf("Informe duas datas no formato dd/mm/aaaa:\n\n");

    for (int i = 0; i < 2; i++) {
        data_valida = 0;

        while (!data_valida) {
            // Inicializa a data com valores inválidos
            data[i].dia = 0;
            data[i].mes = 0;
            data[i].ano = 0;

            printf("\t#%d: ", i+1);
            scanf("%2u/%2u/%4u", &data[i].dia, &data[i].mes, &data[i].ano);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}

            if (data[i].ano == 0 || data[i].dia == 0) {
                printf("Data invalida.\n");
                continue;
            }

            switch (data[i].mes) {
                case 2:
                    if (data[i].dia > 29 ||
                        (data[i].dia == 29 && 
                            !((data[i].ano % 4 == 0 && data[i].ano % 100 != 0)
                                || (data[i].ano % 400 == 0)
                            )
                        )
                    ) {
                        printf("Data invalida.\n");
                    } else {
                        data_valida = 1;
                    } 
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (data[i].dia > 30) {
                        printf("Data invalida.\n");
                    } else {
                        data_valida = 1;
                    } 
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if (data[i].dia > 31) {
                            printf("Data invalida.\n");
                    } else {
                        data_valida = 1;
                    } 
                    break;
                default:
                    printf("Data invalida.\n");
            }
        }
    }

    // Verifica qual é a menor data
    i_menor = PRIMEIRA;
    i_maior = SEGUNDA;

    if (data[SEGUNDA].ano < data[PRIMEIRA].ano) {
        i_menor = SEGUNDA;
        i_maior = PRIMEIRA;
    } else if (data[SEGUNDA].ano == data[PRIMEIRA].ano) {
        if (data[SEGUNDA].mes < data[PRIMEIRA].mes) {
            i_menor = SEGUNDA;
            i_maior = PRIMEIRA;
        } else if (data[SEGUNDA].mes == data[PRIMEIRA].mes) {
            if (data[SEGUNDA].dia < data[PRIMEIRA].dia) {
                i_menor = SEGUNDA;
                i_maior = PRIMEIRA;
            }
        }
    }

    // Adiciona os anos completos que se encontram entre as duas datas

    for (int ano = data[i_menor].ano + 1; ano < data[i_maior].ano; ano++) {
        if ( (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ) {
            diff_total += 366;
        } else {
            diff_total += 365;
        }
    }

    // Calcula os meses completos entre as duas datas
    if (data[PRIMEIRA].ano == data[SEGUNDA].ano) {
        qtd_meses_completos = abs(data[PRIMEIRA].mes - data[SEGUNDA].mes) - 1;
    } else {
        if (data[i_maior].mes > data[i_menor].mes) {
            qtd_meses_completos = 12 + abs(data[PRIMEIRA].mes - data[SEGUNDA].mes) - 1;
        } else if (data[i_maior].mes < data[i_menor].mes) {
            qtd_meses_completos = 12 - abs(data[PRIMEIRA].mes - data[SEGUNDA].mes) - 1;
        } else {
            qtd_meses_completos = 11;
        }
    }

    // Adiciona os meses completos
    for (
        int mes = data[i_menor].mes + 1, ano = data[i_menor].ano;
        qtd_meses_completos > 0;
        qtd_meses_completos--
    ) {
        switch (mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                diff_total += 31;
                mes++;
                break;
            case 12:
                diff_total += 31;
                mes -= 11;
                ano = data[i_maior].ano;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                diff_total += 30;
                mes++;
                break;
            case 2: 
                if ((ano % 4 == 0 && ano % 100 != 0)
                    || (ano % 400 == 0)
                ) {
                    diff_total += 29;
                } else {
                    diff_total += 28;
                }
                mes++;
                break;
        }
    }

    // Se o ano e o mês forem iguais nas duas datas
    if (
        (data[PRIMEIRA].ano == data[SEGUNDA].ano) &&
        (data[PRIMEIRA].mes == data[SEGUNDA].mes)
    ) {
        // Os dias restantes são a diferença entre as datas
        qtd_dias_completos = abs(data[PRIMEIRA].dia - data[SEGUNDA].dia);
    } else {
        // Senão...

        // Calcula quantos dias há entre o dia da menor data e o mes à direita
        switch (data[i_menor].mes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                qtd_dias_completos += 31 - data[i_menor].dia;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                qtd_dias_completos += 30 - data[i_menor].dia;
                break;
            case 2: 
                if ((data[i_menor].ano % 4 == 0 && data[i_menor].ano % 100 != 0)
                    || (data[i_menor].ano % 400 == 0)
                ) {
                    qtd_dias_completos += 29 - data[i_menor].dia;
                } else {
                    qtd_dias_completos += 28 - data[i_menor].dia;
                }
                break;
        }

        // ... e quantos dias há entre o dia da maior data e o mes à esquerda
        qtd_dias_completos += data[i_maior].dia;
    }

    diff_total += qtd_dias_completos;

    printf("\nQuantidade de dias entre as duas datas: %d", diff_total);

    return 0;
}
