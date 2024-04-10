/* 3) Crie uma estrutura chamada Cadastro. Essa estrutura deve conter o nome, a
idade e o endereço de uma pessoa. Agora, escreva uma função que receba um
inteiro positivo N e retorne o ponteiro para um vetor de tamanho N, alocado
dinamicamente, dessa estrutura. Solicite também que o usuário digite os dados
desse vetor dentro da função.*/

#include <stdio.h>
#include <stdlib.h>

// Armazena os dados de uma pessoa.
struct Cadastro {
    char nome[64];
    unsigned idade;
    char endereco[128];
};

// Aloca e lê um array de N cadastros.
struct Cadastro *cadastrar(unsigned N);

// Lê dados do usuário para um array de cadastros de tamanho N.
void ler_cadastros(struct Cadastro *cadastros, unsigned N);

int main() {
    int num = 0;
    struct Cadastro *cadastros = NULL;

    while (num <= 0) {
        printf("Informe a quantidade de cadastros: ");
        scanf("%d", &num);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }

    cadastros = cadastrar(num);

    if (cadastros == NULL) {
        printf("\nErro: memoria insuficiente");
        return 1;
    }

    printf("\nCadastros:\n");

    for (int i = 0; i < num; i++) {
        printf(
            "\t#%d: %s, %u - %s\n",
            i+1,
            cadastros[i].nome,
            cadastros[i].idade,
            cadastros[i].endereco
        );
    }

    free(cadastros);
    cadastros = NULL;

    return 0;
}

struct Cadastro *cadastrar(unsigned N) {
    struct Cadastro *cadastros = NULL;

    // Alocação de memória para o array de cadastros
    cadastros = calloc(N, sizeof(struct Cadastro));

    if (cadastros == NULL) {
        return NULL;
    }

    // Leitura de dados para cada cadastro do array
    ler_cadastros(cadastros, N);

    return cadastros;
}

void ler_cadastros(struct Cadastro *cadastros, unsigned N) {
    int strlen;

    for (unsigned i = 0; i < N; i++) {
        printf("Cadastro #%d\n", i+1);

        printf("\tNome: ");
        fgets(cadastros[i].nome, 64, stdin);

        for (strlen = 0; cadastros[i].nome[strlen] != '\0'; strlen++) {}

        if (cadastros[i].nome[strlen-1] == '\n') {
            cadastros[i].nome[strlen-1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }

        printf("\tIdade: ");
        scanf("%u", &cadastros[i].idade);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        printf("\tEndereco: ");
        fgets(cadastros[i].endereco, 128, stdin);

        for (strlen = 0; cadastros[i].endereco[strlen] != '\0'; strlen++) {}

        if (cadastros[i].endereco[strlen-1] == '\n') {
            cadastros[i].endereco[strlen-1] = '\0';
        } else {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
        }
    }
}
