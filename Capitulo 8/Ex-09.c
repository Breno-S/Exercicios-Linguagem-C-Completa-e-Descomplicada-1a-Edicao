/* 9) Crie uma estrutura representando um atleta. Essa estrutura deve conter o
nome do atleta, seu esporte, idade e altura. Agora, escreva um programa que leia
os dados de cinco atletas. Calcule e exiba os nomes do atleta mais alto e do
mais velho. */

#include <stdio.h>
#include <string.h>

#define QTD_ATLETAS 5

struct Atleta {
    char nome[64];
    char esporte[32];
    int idade;
    double altura;
};

int main() {
    struct Atleta atleta[5] = { 0 };

    // Índices para os atletas que se busca no array
    int i_alto,
        i_velho;

    int c;

    i_alto = i_velho = 0;

    printf("Informe os dados de %d atletas\n\n", QTD_ATLETAS);

    for (size_t i = 0; i < QTD_ATLETAS; i++) {
        printf("#%zu\n", i+1);

        printf("\tNome: ");
        fgets(atleta[i].nome, 64, stdin);

        // Sanitização da variável e do buffer de entrada
        if (atleta[i].nome[strlen(atleta[i].nome)-1] == '\n' ) {
            atleta[i].nome[strlen(atleta[i].nome)-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF)) {}
        }

        printf("\tEsporte: ");
        fgets(atleta[i].esporte, 32, stdin);

        if (atleta[i].esporte[strlen(atleta[i].esporte)-1] == '\n' ) {
            atleta[i].esporte[strlen(atleta[i].esporte)-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF)) {}
        }

        printf("\tIdade: ");
        scanf("%d", &atleta[i].idade);

        while ((c = getchar() != '\n' && c != EOF)) {}
        
        printf("\tAltura (metros): ");
        scanf("%lf", &atleta[i].altura);

        while ((c = getchar() != '\n' && c != EOF)) {}
    }
    
    for (size_t i = 1; i < QTD_ATLETAS; i++) {
        if (atleta[i].altura > atleta[i_alto].altura) {
            i_alto = i;
        }

        if (atleta[i].idade > atleta[i_velho].idade) {
            i_velho = i;
        }
    }
    
    printf("\nAtleta mais alto: %s", atleta[i_alto].nome);
    printf("\nAtleta mais velho: %s\n", atleta[i_velho].nome);
    
    return 0;
}
