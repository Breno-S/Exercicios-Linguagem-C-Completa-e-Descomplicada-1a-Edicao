/* 6) Crie uma estrutura representando um aluno de uma disciplina. Essa
estrutura deve conter o número de matrícula do aluno, seu nome e as notas de
três provas. Agora, escreva um programa que leia os dados de cinco alunos e os
armazena nessa estrutura. Em seguida, exiba o nome e as notas do aluno que
possui a maior média geral dentre os cinco. */

#include <stdio.h>

#define QTD_ALUNOS 3

struct Aluno {
    unsigned matricula;
    char nome[64];
    double nota1, nota2, nota3;
    double media;
};

int main() {
    struct Aluno aluno[QTD_ALUNOS] = { 0 };

    // Define o primeiro aluno como possuidor da maior média
    unsigned indice_maior_nota = 0;

    int i, c;

    // Leitura dos dados de cada aluno
    for (i = 0; i < QTD_ALUNOS; i++) {
        printf("Aluno #%d\n", i+1);

        printf("\tMatricula: ");
        scanf("%d", &aluno[i].matricula);

        while ((c = getchar() != '\n' && c != EOF)) {}

        printf("\tNome: ");
        fgets(aluno[i].nome, 64, stdin);

        int strlen;
        for (strlen = 0; aluno[i].nome[strlen] != '\0'; strlen++) {}

        if (aluno[i].nome[strlen-1] == '\n' ) {
            aluno[i].nome[strlen-1] = '\0';
        } else {
            while ((c = getchar() != '\n' && c != EOF)) {}
        }

        printf("\n\tInforme a nota na prova 1: ");
        scanf("%lf", &aluno[i].nota1);

        while ((c = getchar() != '\n' && c != EOF)) {}

        printf("\tInforme a nota na prova 2: ");
        scanf("%lf", &aluno[i].nota2);

        while ((c = getchar() != '\n' && c != EOF)) {}

        printf("\tInforme a nota na prova 3: ");
        scanf("%lf", &aluno[i].nota3);

        while ((c = getchar() != '\n' && c != EOF)) {}

        // Calcula a média
        aluno[i].media = (aluno[i].nota1 + aluno[i].nota2 + aluno[i].nota3) / 3;
    }
    
    // Comparação das médias dos alunos
    for (i = 1; i < QTD_ALUNOS; i++) {
        if (aluno[i].media > aluno[indice_maior_nota].media) {
            indice_maior_nota = i;
        }
    }
    
    printf(
        "\nAluno com maior media:\n\n"
        "Nome: %s\tMatricula: %u\n\n"
        "Nota 1: %f\n"
        "Nota 2: %f\n"
        "Nota 3: %f\n\n"
        "Media Geral: %f\n",
        aluno[indice_maior_nota].nome,
        aluno[indice_maior_nota].matricula,
        aluno[indice_maior_nota].nota1,
        aluno[indice_maior_nota].nota2,
        aluno[indice_maior_nota].nota3,
        aluno[indice_maior_nota].media
    );

    return 0;
}
