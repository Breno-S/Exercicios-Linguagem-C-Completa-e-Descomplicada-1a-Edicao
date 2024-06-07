/* 20) Considerando a estrutura atleta do exercício anterior, escreva um
programa que leia um arquivo binário contendo os dados de cinco atletas.
Calcule e exiba o nome do atleta mais alto e do mais velho. */

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
    Atleta  atleta[QTD_ATLETAS] = { 0 };
    
    size_t i_alto,
           i_velho;

    FILE  *fp;

    // Abre o arquivo
    if ((fp = fopen("atletas.bin", "rb")) == NULL) {
        perror("Error");
        return 1;
    }

    // Lê os dados dos atletas
    size_t result = fread(&atleta, sizeof atleta[0], QTD_ATLETAS, fp);

    if (result != QTD_ATLETAS) {
        if (feof(fp)) {
            printf("Erro: fim do arquivo atingido antes do esperado.\n");
        } else if (ferror(fp)) {
            printf("Erro de leitura em 'atletas.bin'.\n");
        }

        return 2;
    }

    i_alto = i_velho = 0;
    
    // Define o mais alto e o mais velho
    for (size_t i = 1; i < QTD_ATLETAS; i++) {
        if (atleta[i].altura > atleta[i_alto].altura) i_alto  = i;
        if (atleta[i].idade  > atleta[i_velho].idade) i_velho = i;
    }

    printf("Atleta mais alto: %s\n", atleta[i_alto].nome);
    printf("Atleta mais velho: %s\n", atleta[i_velho].nome);
    
    fclose(fp);

    return 0;
}
