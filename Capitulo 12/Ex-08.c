/* 8) Dado um arquivo contendo um conjunto de nomes e datas de nascimento (dia,
mês e ano, isto é, três inteiros seguidos), escrever um programa que leia esse
arquivo e a data atual e gere outro arquivo contendo o nome e a idade. */

/*
O conteudo do arquivo precisa estar num formato análogo ao CSV:

João, 01/04/1969
Silvio, 12/12/2012
Maria, 13/05/1942
Fulano, 01/01/1984
*/

#include <stdio.h>
#include <ctype.h>

typedef struct {
    unsigned short dia;
    unsigned short mes;
    unsigned ano;
} Data;

typedef struct {
    char nome[64];
    Data data_nasc;
} Pessoa;

// Retorna 1 para datas válidas, 0 para datas inválidas.
int is_data_valida(Data data);

/* Retorna a idade de acordo com as datas informadas. O resultado
será negativo e não simétrico caso a segunda data seja maior do que a primeira. */
int idade_anos(Data hoje, Data nasc);

int main() {
    Pessoa pessoa = { 0 };
    Data   data_atual = { 0 };

    FILE  *fp_leitura,
          *fp_escrita;

    short  idade = 0;

    char   c;

    // Abrir arquivos
    if ((fp_leitura = fopen("pessoas_datas.txt", "r")) == NULL) {
        perror("Error");
        return 1;
    }

    if ((fp_escrita = fopen("pessoas_idades.txt", "w")) == NULL) {
        fclose(fp_leitura);
        perror("Error");
        return 1;
    }

    // Ler a data atual
    while (1) {
        printf("Informe a data atual no formato dd/mm/aaaa: ");
        scanf("%hu/%hu/%u", &data_atual.dia, &data_atual.mes, &data_atual.ano);

        while ((c = getchar()) != '\n' && c != EOF);

        if (is_data_valida(data_atual)) {
            break;
        }

        printf("Data invalida.\n");
    }

    // Salvar os nomes e as idades
    while (!feof(fp_leitura)) {
        // "Pula" os caracteres de espaçamento antes do nome
        while (isspace(c = fgetc(fp_leitura)));

        ungetc(c, fp_leitura);

        if (c == EOF) {
            break;
        }

        fscanf(
            fp_leitura,
            "%63[^,], %hu/%hu/%u",
            pessoa.nome,
            &pessoa.data_nasc.dia,
            &pessoa.data_nasc.mes,
            &pessoa.data_nasc.ano
        );

        if (!is_data_valida(pessoa.data_nasc)) {
            printf("%s ignorado, data invalida\n", pessoa.nome);
            continue;
        }

        idade = idade_anos(data_atual, pessoa.data_nasc);

        if (idade < 0) {
            printf("%s ignorado(a), data invalida\n", pessoa.nome);
            continue;
        }

        fprintf(fp_escrita, "%s, %hu\n", pessoa.nome, idade);
    }

    printf("Idades salvas no arquivo 'pessoas_idades.txt'\n");

    fclose(fp_leitura);
    fclose(fp_escrita);

    return 0;
}

int is_data_valida(Data data) {
    if (data.dia == 0 || data.mes == 0 || data.ano == 0) {
        return 0;
    }

    int data_valida = 1;

    switch (data.mes) {
        case 2:
            if (data.dia > 29 ||
                (data.dia == 29 && 
                    !((data.ano % 4 == 0 && data.ano % 100 != 0) ||
                        (data.ano % 400 == 0)
                    )
                )
            ) {
                data_valida = 0;
            } 
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (data.dia > 30) {
                data_valida = 0;
            } 
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (data.dia > 31) {
                data_valida = 0;
            } 
            break;
        default:
            data_valida = 0;
    }

    return data_valida;
}

int idade_anos(Data hoje, Data nasc) {
    int idade = hoje.ano - nasc.ano;

    if (nasc.mes > hoje.mes || (nasc.mes == hoje.mes && nasc.dia > hoje.dia)) {
        idade -= 1;
    } 

    return idade;
}
