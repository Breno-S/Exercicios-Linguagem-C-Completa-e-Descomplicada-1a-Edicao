/* 9) Crie uma estrutura representando um aluno de uma disciplina. Essa
estrutura deve conter o número de matrícula do aluno, seu nome e as notas de
três provas. Agora, escreva uma função que receba um vetor de tamanho N dessa
estrutura. Essa função deve retornar o índice do aluno que possui a maior média
geral entre todos os alunos. */

#include <stdio.h>

#define QTD_ALUNOS 5

struct Aluno {
    unsigned matricula;
    char nome[64];
    double nota1, nota2, nota3;
};

int indice_melhor_media(struct Aluno *alunos, size_t quantidade) {
    // Define o primeiro aluno como possuidor da maior média
    size_t indice_maior_media = 0;

    // Define a maior media como a do primeiro aluno
    double maior_media = (alunos[0].nota1 + alunos[0].nota2 +
                                                        alunos[0].nota3) / 3;

    for (size_t i = 0; i < quantidade; i++) {
        int media_i = 0;

        media_i = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if (media_i > maior_media) {
            indice_maior_media = i;
        }
    }

    return indice_maior_media;
}

int main() {
    struct Aluno aluno[QTD_ALUNOS] = { 0 };

    int c;

    // Leitura dos dados de cada aluno

    for (int i = 0; i < QTD_ALUNOS; i++) {
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
    }

    size_t i_best = indice_melhor_media(aluno, QTD_ALUNOS);

    printf(
        "\nAluno com maior media:\n\n"
        "Nome: %s\tMatricula: %u\n\n"
        "Nota 1: %f\n"
        "Nota 2: %f\n"
        "Nota 3: %f\n\n"
        "Media Geral: %f\n",
        aluno[i_best].nome,
        aluno[i_best].matricula,
        aluno[i_best].nota1,
        aluno[i_best].nota2,
        aluno[i_best].nota3,
        (aluno[i_best].nota1 + aluno[i_best].nota2 + aluno[i_best].nota3) / 3.0
    );

    return 0;
}
