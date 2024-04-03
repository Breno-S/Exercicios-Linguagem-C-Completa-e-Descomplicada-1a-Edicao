/* 1) Implemente um programa que leia o nome, a idade e o endereço de uma pessoa
e armazene esses dados em uma estrutura. Em seguida, imprima na tela os dados da
estrutura lida. */

#include <stdio.h>

struct Pessoa {
    char nome[64];
    unsigned idade;
    char endereco[128];
};

int main() {
    struct Pessoa p1 = { 0 };

    printf("Informe o seu nome: ");
    fgets(p1.nome, 64, stdin);

    int strlen;
    for (strlen = 0; p1.nome[strlen] != '\0'; strlen++) {}
    
    if (p1.nome[strlen-1] == '\n') {
        p1.nome[strlen-1] = '\0';
    } else {
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
    }
    
    printf("Informe sua idade: ");
    scanf("%u", &p1.idade);
    
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}

    printf("Informe o seu endereco: ");
    fgets(p1.endereco, 128, stdin);

    printf("Seus dados:\n\n");
    printf("\tNome: %s\n", p1.nome);
    printf("\tIdade: %u\n", p1.idade);
    printf("\tEndereco: %s\n", p1.endereco);

    return 0;
}
