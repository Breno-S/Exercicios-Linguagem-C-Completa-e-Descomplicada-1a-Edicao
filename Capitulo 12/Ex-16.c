/* 16) Faça um programa que leia 100 números. Esse programa deverá, em seguida,
armazenar esses números em um arquivo binário. */

#include <stdio.h>

#define MAX 100

int main() {
    int nums[MAX] = { 0 };

    FILE *fp;

    if ((fp = fopen("numeros.bin", "wb")) == NULL) {
        perror("Error");
        return 1;
    }

    for (size_t i = 0; i < MAX; i++) {
        /* Descomente se estiver a fim de digitar 100 números no terminal */
        // scanf("%d", &nums[i]);

        // int c;
        // while ((c = getchar()) != '\n' && c != EOF) {}

        /* Comente se estiver a fim de digitar 100 números no terminal */
        nums[i] = i;
    }

    // Tenta salvar no arquivo binário
    size_t result = fwrite(&nums, sizeof nums[0], MAX, fp);

    fclose(fp);

    if (result != MAX) {
        printf("Erro ao gravar dados em 'numeros.bin'.\n");
        return 1;
    }

    printf("\nDados salvos com sucesso em 'numeros.bin'\n");
    
    return 0;
}
