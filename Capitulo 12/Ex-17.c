/* 17) Elabore um programa que leia um arquivo binário contendo 100 números.
Mostre na tela a soma desses números. */

#include <stdio.h>

#define MAX 100

int main() {
    int    nums[MAX] = { 0 };
    size_t soma = 0;
    FILE  *fp;

    // Abre o arquivo
    if ((fp = fopen("numeros.bin", "rb")) == NULL) {
        perror("Error");
        return 1;
    }

    // Tenta ler os dados do arquivo para o array `nums`
    if ((fread(&nums, sizeof nums[0], MAX, fp)) == MAX) {
        for (size_t i = 0; i < MAX; i++) {
            soma += nums[i];
        }

        printf(
            "Soma dos 100 numeros contidos no arquivo 'numeros.bin': %zu\n",
            soma
        );
    } else if (feof(fp)) {
        printf("Erro: fim do arquivo atingido antes do esperado.\n");
    } else if (ferror(fp)) {
        printf("Erro de leitura em 'numeros.bin'.\n");
    }
    
    fclose(fp);

    return 0;
}
