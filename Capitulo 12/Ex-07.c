/* 7) Faça um programa que permita que o usuário entre com diversos nomes e
telefone para cadastro. Crie um arquivo com essas informações, uma por linha. O
usuário finaliza a entrada com o valor 0 para o telefone. */

#include <stdio.h>
#include <string.h>

int main() {
    char  nome[64] = { 0 },
          telefone[20] = { 0 },
          c;

    FILE *fp = NULL;

    // Cria o arquivo
    if ((fp = fopen("contatos.txt", "w")) == NULL) {
        perror("Error");
        return 1;
    }

    printf(
        "Informe os seus contatos ou digite 0 no campo de telefone "
        "para encerrar o programa\n"
    );

    // Lê os contatos
    for (size_t i = 1; ; i++) {
        printf("\nNome do Contato #%zu: ", i);
        fgets(nome, 64, stdin);

        // Sanitiza a variável ou o buffer do stdin
        if (nome[strlen(nome) - 1] == '\n') {
            nome[strlen(nome) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        printf("\tTelefone: ");
        fgets(telefone, 20, stdin);

        if (telefone[strlen(telefone) - 1] == '\n') {
            telefone[strlen(telefone) - 1] = '\0';
        } else {
            while ((c = getchar()) != '\n' && c != EOF);
        }

        // Condição para encerrar o programa
        if (strncmp(telefone, "0", 23) == 0) {
            break;
        }

        fprintf(fp, "%s | %s\n", nome, telefone);
    }

    fclose(fp);

    printf("\nContatos salvos em 'contatos.txt'.\n");
    
    return 0;
}
