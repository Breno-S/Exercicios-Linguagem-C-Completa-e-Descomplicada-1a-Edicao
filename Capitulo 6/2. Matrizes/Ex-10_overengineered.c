/* 10) Leia uma matriz de tamanho 10 × 3 com as notas de 10 alunos em três
provas. Em seguida, calcule e escreva na tela o número de alunos cuja pior nota
foi na prova 1, o número de alunos cuja pior nota foi na prova 2 e o número de
alunos cuja pior nota foi na prova 3. */

/* 
Este algoritmo resolve o problema que ocorre quando duas ou mais notas são
iguais. Agora quando duas ou tres notas são iguais, não se acumula mais no 
contador da primeira pior nota, mas em um contador para as notas específicas.
*/

#include <stdio.h>

#define NUM_ALUNOS 10

// Código numérico que indica a combinação.
enum {
    PRIMEIRA = 1,           // 1 = 001 = primeira
    SEGUNDA,                // 2 = 010 = segunda
    PRIMEIRA_E_SEGUNDA,     // 3 = 011 = primeira e segunda
    TERCEIRA,               // 4 = 100 = terceira
    PRIMEIRA_E_TERCEIRA,    // 5 = 101 = primeira e terceira
    SEGUNDA_E_TERCEIRA,     // 6 = 110 = segunda e terceira
    TODAS                   // 7 = 111 = tudo igual 
};

int main() {
    // Matriz que armazena as notas dos alunos.
    short notas[NUM_ALUNOS][3] = { 0 };

    // Array que armazena as flags de cada aluno.
    unsigned char piores_notas[NUM_ALUNOS] = { 0 };

    // Valor da pior nota.
    short pior_nota;

    // Contadores para cada nota

    short   count_pior_1 = 0,
            count_pior_2 = 0,
            count_pior_3 = 0,
            count_pior_1_2 = 0,
            count_pior_1_3 = 0,
            count_pior_2_3 = 0,
            count_pior_all = 0;

    // Inserção das notas
    printf("Informe as notas dos alunos:\n");

    for (int i = 0; i < NUM_ALUNOS; i++) {
        printf("\nAluno %d:\n", i + 1);

        for (int j = 0; j < 3; j++) {
            printf("\tAvaliacao #%d: ", j + 1);
            scanf("%hd", &notas[i][j]);

            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }

    // Calculo das piores notas

    for (int i = 0; i < NUM_ALUNOS; i++) {
        // Define a primeira nota como a pior
        pior_nota = notas[i][0];

        piores_notas[i] = PRIMEIRA;    // 1 = 001
        
        for (int j = 1; j < 3; j++) {

            // Se encontrou uma nota mais baixa
            if (notas[i][j] < pior_nota) {
                pior_nota = notas[i][j];
                
                if (j == 1) {
                    piores_notas[i] = SEGUNDA;      // muda para a segunda
                } else {
                    piores_notas[i] = TERCEIRA;     // muda para a terceira
                }
            }
            
            // Se encontrou uma nota igual à pior
            else if (notas[i][j] == pior_nota) {
                if (j == 1) {
                    piores_notas[i] |= SEGUNDA;     // adiciona a segunda
                } else {
                    piores_notas[i] |= TERCEIRA;    // adiciona a terceira
                }
            }
        }
    }

    int total_1, total_2, total_3;

    total_1 = total_2 = total_3 = 0;

    for(int i = 0; i < NUM_ALUNOS; i++) {
        switch(piores_notas[i]) {
            case PRIMEIRA:
                count_pior_1++;
                total_1++;
                break;
            case SEGUNDA:
                count_pior_2++;
                total_2++;
                break;
            case TERCEIRA:
                count_pior_3++;
                total_3++;
                break;
            case PRIMEIRA_E_SEGUNDA:
                count_pior_1_2++;
                total_1++;
                total_2++;
                break;
            case PRIMEIRA_E_TERCEIRA:
                count_pior_1_3++;
                total_1++;
                total_3++;
                break;
            case SEGUNDA_E_TERCEIRA:
                count_pior_2_3++;
                total_2++;
                total_3++;
                break;
            case TODAS:
                count_pior_all++;      
                total_1++;
                total_2++;
                total_3++;
                break;
        }
    }

    printf(
        "\nTotal de alunos cuja pior nota foi a primeira: %hd\n",
        count_pior_1
    );
    printf(
        "Total de alunos cuja pior nota foi a segunda: %hd\n",
        count_pior_2
    );
    printf(
        "Total de alunos cuja pior nota foi a terceira: %hd\n",
        count_pior_3
    );
    printf(
        "Total de alunos cujas piores notas foram a "
        "primeira e a segunda: %hd\n",
        count_pior_1_2
    );
    printf(
        "Total de alunos cujas piores notas foram a "
        "primeira e a terceira: %hd\n",
        count_pior_1_3
    );
    printf(
        "Total de alunos cujas piores notas foram a "
        "segunda e a terceira: %hd\n",
        count_pior_2_3
    );
    printf(
        "Total de alunos cujas notas foram iguais nas tres provas: %hd\n",
        count_pior_all
    );
    
    printf("\nProva mais dificil: ");

    if (total_1 > total_2 && total_1 > total_3) {
        printf("1");
    } 
    if (total_2 > total_1 && total_2 > total_3) {
        printf("2");
    } 
    if (total_3 > total_1 && total_3 > total_2) {
        printf("3");
    }
    if (total_1 == total_2 && total_1 > total_3) {
        printf("1 e 2");
    }
    if (total_1 == total_3 && total_1 > total_2) {
        printf("1 e 3");
    }
    if (total_2 == total_3 && total_1 > total_1) {
        printf("2 e 3");
    }
    if (total_1 == total_2 && total_1 == total_3) {
        printf("N/A");
    }
    
    return 0;
}
