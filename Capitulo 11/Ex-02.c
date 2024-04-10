/* 2) Crie uma estrutura representando um aluno de uma disciplina. Essa
estrutura deve conter o número de matrícula do aluno, seu nome e as notas de
três provas. Escreva um programa que mostre o tamanho em byte dessa estrutura. */

/*
Aqui é possível perceber que nem sempre o tamanho da estrutura será igual à soma
dos tamanhos de seus membros. Isso acontece por que os compiladores alinham as
variáveis aos endereços de memória múltiplos de 4 ou 8, preenchendo os espaços
vazios com bytes extras. É possível evitar este comportamento com diretivas de
pre-processamento e atributos, dependendo do compilador usado.
*/

#include <stdio.h>

struct Aluno {
    unsigned matricula;
    char nome[64];
    double nota1, nota2, nota3;
};

int main() {
    printf("Definicao da estrutura:\n\n");
    printf(
        "struct Aluno {\n"
        "    unsigned matricula;\n"
        "    char nome[64];\n"
        "    double nota1, nota2, nota3;\n"
        "}"
    );

    printf("\n\nTamanho em bytes (sizeof): %d", sizeof(struct Aluno));

    return 0;
}
