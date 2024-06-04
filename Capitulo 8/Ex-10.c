/* 10) Usando a estrutura “atleta” do exercício anterior, escreva um programa
que leia os dados de cinco atletas e os exiba por ordem de idade, do mais velho
para o mais novo. */

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
    struct Atleta atleta[QTD_ATLETAS] = { 0 };
    
    int c;

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
    
    // Ordena o array de structs
    for (size_t i = 0; i < QTD_ATLETAS; i++) {
        for (size_t j = i; j < QTD_ATLETAS; j++) {
            if (atleta[j].idade > atleta[i].idade) {
                struct Atleta temp = atleta[i];
                atleta[i] = atleta[j];
                atleta[j] = temp;
            }
        }
    }
    

    printf("\nAtletas em ordem etaria decrescente:\n\n");

    for (size_t i = 0; i < QTD_ATLETAS; i++) {
        printf("#%zu - %s\n",i+1, atleta[i].nome);
    }
    
    return 0;
}
