/* 10) Leia uma matriz de tamanho 10 × 3 com as notas de 10 alunos em três
provas. Em seguida, calcule e escreva na tela o número de alunos cuja pior nota
foi na prova 1, o número de alunos cuja pior nota foi na prova 2 e o número de
alunos cuja pior nota foi na prova 3. */

#include <stdio.h>

int main() {
    int notas[10][3] = { 0 },
        count_pior_nota_1 = 0,
        count_pior_nota_2 = 0,
        count_pior_nota_3 = 0;

    printf("Informe as notas dos alunos:\n");

    for (int i = 0; i < 10; i++) {
        printf("\nAluno %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("\tAvaliacao #%d: ", j + 1);
            scanf("%d", &notas[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    int   pior_nota;
    int     posicao_pior_nota;

    for (int i = 0; i < 10; i++) {
        pior_nota = notas[i][0];
        posicao_pior_nota = 0;

        for (int j = 1; j < 3; j++) {
            if (notas[i][j] < pior_nota) {
                pior_nota = notas[i][j];
                posicao_pior_nota = j;
            }
        }

        switch (posicao_pior_nota) {
            case 0:
                count_pior_nota_1++;
                break;
            case 1:
                count_pior_nota_2++;
                break;
            case 2:
                count_pior_nota_3++;
                break;
        }
    }

    printf(
        "\nNumero de alunos com a pior nota na primeira prova: %d\n",
        count_pior_nota_1
    );
    
    printf(
        "Numero de alunos com a pior nota na segunda prova: %d\n",
        count_pior_nota_2
    );
    
    printf(
        "Numero de alunos com a pior nota na terceira prova: %d\n",
        count_pior_nota_3
    );

    return 0;
}
