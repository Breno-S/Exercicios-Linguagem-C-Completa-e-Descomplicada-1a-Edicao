/* 18) Crie um programa que leia um arquivo binário contendo uma quantidade
qualquer de números. O primeiro número lido indica quantos valores existem no
arquivo. Mostre na tela o maior e o menor valor lido. */

/*
Os ints de largura explícita informam o tamanho, em bits, que cada número deve
ter no arquivo.

Para editar o arquivo binário que este programa lê, utilizei a extensão do VS
Code "Hex Editor".
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    uint32_t qtd = 0; /* 4 bytes */

    int32_t *array,   /* 4 bytes */
             maior,
             menor;

    FILE    *fp;

    size_t   obj_lidos;

    // Abre o arquivo
    if ((fp = fopen("nums-e18.bin", "rb")) == NULL) {
        perror("Error");
        return 1;
    }

    // Lê a quantidade de números
    obj_lidos = fread(&qtd, sizeof qtd, 1, fp);

    if (obj_lidos != 1) {
        printf("Erro ao ler a quantidade de numeros do arquivo.\n");
        return 2;
    }

    // Aloca memória para armazenar os números
    if ((array = malloc(sizeof *array * qtd)) == NULL) {
        printf("Erro: memoria insuficiente\n");
        return 3;
    }

    // Lê os números diretamente do arquivo para o array alocado
    obj_lidos = fread(array, sizeof *array, qtd, fp);
    
    if (obj_lidos != qtd) {
        printf("Erro ao ler os numeros do arquivo.\n");
        return 2;
    }
    
    maior = menor = array[0];

    // Define o maior e o menor valor
    for (size_t i = 0; i < qtd; i++) {
        if (array[i] > maior) maior = array[i]; else
        if (array[i] < menor) menor = array[i];
    }

    printf("Maior numero do arquivo: %d\n", maior);
    printf("Menor numero do arquivo: %d\n", menor);

    free(array);

    array = NULL;

    fclose(fp);
    
    return 0;
}
