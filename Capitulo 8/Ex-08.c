/* 8) Crie uma estrutura capaz de armazenar o nome e a data de nascimento de
uma pessoa. Agora, escreva um programa que leia os dados de seis pessoas. 
Calcule e exiba os nomes da pessoa mais nova e da mais velha. */

/*
Este algoritmo só aceita datas do calendário gregoriano a partir do ano 1, com
isso ele não reflete os anos históricos e ainda por cima é descriminatório
contra aqueles nascidos antes de Jesus de Nazaré... Que vergonha...

Falando sério agora, eu gostaria de chamar atenção ao fato de que a
representação do tempo nos computadores nunca será perfeita, por diferentes
motivos, sejam eles históricos, culturais, astronômicos ou ligados limitações
do próprio hardware. Sempre teremos que abrir mão de alguma coisa se quisermos
medir o tempo e representá-lo.
*/

#include <stdio.h>

#define QTD_PESSOAS 6

struct Data {
    unsigned char dia;
    unsigned char mes;
    unsigned ano;
};

struct Pessoa {
    char nome[64];
    struct Data dataNasc;
};

int main() {
    struct Pessoa pessoa[QTD_PESSOAS] = { 0 };
    int i_velha, i_nova;

    int c, strlen, data_valida;

    printf(
        "Informe o nome e a data de nascimento de %d pessoas\n\n",
        QTD_PESSOAS
    );

    for (int i = 0; i < QTD_PESSOAS; i++) {
        printf("#%d\n", i+1);

        printf("\tNome: ");
        fgets(pessoa[i].nome, 64, stdin);

        // Sanitização da variável e do buffer de entrada
        for (strlen = 0; pessoa[i].nome[strlen] != '\0'; strlen++) {}

        if (pessoa[i].nome[strlen-1] == '\n' ) {
            pessoa[i].nome[strlen-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF)) {}
        }

        data_valida = 0;
        while (!data_valida) {
            // Inicializa os campos da data de nascimento com valores inválidos
            pessoa[i].dataNasc.dia = 0;
            pessoa[i].dataNasc.mes = 0;
            pessoa[i].dataNasc.ano = 0;

            printf("\tData de nascimento (dd/mm/aaaa): ");
            scanf(
                "%2u/%2u/%4u",
                &pessoa[i].dataNasc.dia,
                &pessoa[i].dataNasc.mes,
                &pessoa[i].dataNasc.ano
            );

            while ((c = getchar()) != '\n' && c != EOF) {}

            if (pessoa[i].dataNasc.ano == 0 || pessoa[i].dataNasc.dia == 0) {
                printf("Data de nascimento invalida.\n");
                continue;
            }

            switch (pessoa[i].dataNasc.mes) {
                case 2:
                    if (pessoa[i].dataNasc.dia > 29 ||
                        (pessoa[i].dataNasc.dia == 29 && 
                            !( (pessoa[i].dataNasc.ano % 4 == 0 &&
                                pessoa[i].dataNasc.ano % 100 != 0
                               ) || (pessoa[i].dataNasc.ano % 400 == 0)
                            )
                        )
                    ) {
                        printf("Data de nascimento invalida.\n");
                    } else {
                        data_valida = 1;
                    } 
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (pessoa[i].dataNasc.dia > 30) {
                        printf("Data de nascimento invalida.\n");
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
                    if (pessoa[i].dataNasc.dia > 31) {
                            printf("Data de nascimento invalida.\n");
                    } else {
                        data_valida = 1;
                    } 
                    break;
                default:
                    printf("Data de nascimento invalida.\n");
            }
        }
    }

    i_nova = 0;
    // Busca pela maior data
    for (size_t i = 1; i < QTD_PESSOAS; i++) {
        if (pessoa[i].dataNasc.ano > pessoa[i_nova].dataNasc.ano) {

            i_nova = i;

        } else if (pessoa[i].dataNasc.ano == pessoa[i_nova].dataNasc.ano) {

            if (pessoa[i].dataNasc.mes > pessoa[i_nova].dataNasc.mes) {
            
                i_nova = i;

            } else if (pessoa[i].dataNasc.mes == pessoa[i_nova].dataNasc.mes) {

                if (pessoa[i].dataNasc.dia > pessoa[i_nova].dataNasc.dia) {

                    i_nova = i;

                }
            }
        }
    }

    i_velha = 0;
    // Busca pela menor data
    for (size_t i = 1; i < QTD_PESSOAS; i++) {
        if (pessoa[i].dataNasc.ano < pessoa[i_velha].dataNasc.ano) {

            i_velha = i;

        } else if (pessoa[i].dataNasc.ano == pessoa[i_velha].dataNasc.ano) {

            if (pessoa[i].dataNasc.mes < pessoa[i_velha].dataNasc.mes) {
            
                i_velha = i;

            } else if (pessoa[i].dataNasc.mes == pessoa[i_velha].dataNasc.mes) {

                if (pessoa[i].dataNasc.dia < pessoa[i_velha].dataNasc.dia) {

                    i_velha = i;

                }
            }
        }
    }

    printf("\nPessoa mais nova: %s\n", pessoa[i_nova].nome);
    printf("Pessoa mais velha: %s\n", pessoa[i_velha].nome);

    return 0;
}
