/* 19) Crie uma estrutura representando um atleta. Essa estrutura deve conter o
nome do atleta, seu esporte, idade e altura. Agora, escreva um programa que leia
os dados de cinco atletas e os armazene em um arquivo binário. */

#include <stdio.h>
#include <string.h>

#define QTD_ATLETAS 5

typedef struct {
    char nome[64];
    char esporte[32];
    short idade;
    float altura;
} Atleta;

int main() {
    Atleta atleta[QTD_ATLETAS] = { 0 };
    char   c;
    FILE  *fp;

    // Abre o arquivo
    if ((fp = fopen("atletas.bin", "wb")) == NULL) {
        perror("Error");
        return 1;
    }

    printf("Informe os dados de %d atletas\n\n", QTD_ATLETAS);

    // Lê os dados dos atletas pelo usuário
    for (size_t i = 0; i < QTD_ATLETAS; i++) {
        printf("#%zu\n", i+1);

        printf("\tNome: ");
        fgets(atleta[i].nome, 64, stdin);

        // Sanitização da variável ou do buffer de entrada
        if (atleta[i].nome[strlen(atleta[i].nome)-1] == '\n' ) {
            atleta[i].nome[strlen(atleta[i].nome)-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF));
        }

        printf("\tEsporte: ");
        fgets(atleta[i].esporte, 32, stdin);

        if (atleta[i].esporte[strlen(atleta[i].esporte)-1] == '\n' ) {
            atleta[i].esporte[strlen(atleta[i].esporte)-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF));
        }

        printf("\tIdade: ");
        scanf("%hd", &atleta[i].idade);

        while ((c = getchar() != '\n' && c != EOF));
        
        printf("\tAltura (metros): ");
        scanf("%f", &atleta[i].altura);

        while ((c = getchar() != '\n' && c != EOF));
    }

    // Escreve os dados no arquivo binário
    size_t result = fwrite(&atleta, sizeof atleta[0], QTD_ATLETAS, fp);

    fclose(fp);

    if (result != QTD_ATLETAS) {
        printf("Erro ao salvar os dados dos atletas.\n");
        return 2;
    }
    
    printf("\nDados salvos com sucesso em 'atletas.bin'.\n");

    return 0;
}
