/* 13) Faça um programa que leia um arquivo texto contendo os dados de um
aluno. Cada linha do arquivo contém o número de matrícula, o nome e as notas
de três provas de um aluno. Os dados devem ser lidos e armazenados em uma
estrutura. Em seguida, exiba os dados lidos em tela. */

#include <stdio.h>

typedef struct {
    char matricula[10];
    char nome[64];
    float notas[3];
} Aluno;

int main() {
    Aluno aluno = { 0 };
    FILE *fp;
    
    if ((fp = fopen("aluno.txt", "r")) == NULL) {
        perror("Error");
        return 1;
    }

    fscanf(
        fp,
        "%[^\n] %[^\n] %f %f %f",
        aluno.matricula,
        aluno.nome,
        &aluno.notas[0],
        &aluno.notas[1],
        &aluno.notas[2]
    );

    printf("Nome: %s\tMatricula: %s\n\n", aluno.nome, aluno.matricula);
    printf("\tNota 1: %f\n", aluno.notas[0]);
    printf("\tNota 2: %f\n", aluno.notas[1]);
    printf("\tNota 3: %f\n", aluno.notas[2]);

    fclose(fp);

    return 0;
}
