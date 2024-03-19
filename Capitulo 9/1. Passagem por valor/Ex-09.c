/* 9) Elabore uma função que receba três notas de um aluno como parâmetros e
uma letra. Se a letra for “A”, a função deverá calcular a média aritmética das
notas do aluno; se for “P”, deverá calcular a média ponderada, com pesos 5, 3 e
2. Retorne a média calculada para o programa principal. */

#include <stdio.h>

float calc_media_tipo(float n1, float n2, float n3, char tipo) {
    switch (tipo) {
        case 'A':
        case 'a':
            return (n1 + n2 + n3) / 3;
            break;
        case 'P':
        case 'p':
            return (n1*5 + n2*3 + n3*2) / 3;
            break;
        default:
            return -1;
    }
}

int main() {
    float nota1, nota2, nota3;
    char opcao;

    nota1 = nota2 = nota3 = -1;

    printf("Informe tres notas de um aluno: ");

    while (1) {
        int c;

        scanf("%f", &nota1);
        while ((c = getchar()) != '\n' && c != EOF) {}

        scanf("%f", &nota2);
        while ((c = getchar()) != '\n' && c != EOF) {}

        scanf("%f", &nota3);
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (nota1 < 0 || nota2 < 0 || nota3 < 0) {
            printf("Uma ou mais notas invalidas. Tente novamente\n\nR: ");
        } else {
            break;
        }
    }

    printf(
        "\nAgora informe o tipo de media "
        "(A = aritmetica | P = ponderada): "
    );
    
    while (1) {
        scanf("%c", &opcao);

        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}

        if (opcao != 'A' && opcao != 'P' && opcao != 'a' && opcao != 'p') {
            printf("Opcao invalida. Tente novamente\n\nR: ");
        } else {
            break;
        }
    }

    printf("\nMedia: %.2f", calc_media_tipo(nota1, nota2, nota3, opcao));

    return 0;
}
