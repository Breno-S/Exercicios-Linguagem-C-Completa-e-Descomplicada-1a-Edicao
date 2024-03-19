/* 10) Escreva uma função que receba dois valores numéricos e um símbolo. Esse
símbolo representará a operação que se deseja efetuar com os números. Assim, se
o símbolo for “+”, deverá ser realizada uma adição, se for “−”, uma subtração,
se for “/”, uma divisão, e, se for “*”, será efetuada uma multiplicação.
Retorne o resultado da operação para o programa principal. */

#include <stdio.h>

double calcula_op(double a, double b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b; 
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                return 0;   // Matematicamente Incorreto
            }
            return a / b;
        default:
            return 0;       // ¯\_(ツ)_/¯
    }
}

int main() {
    double num1, num2;
    char operacao;
    int c;

    printf("Informe o primeiro operando: ");
    scanf("%lf", &num1);

    while ((c = getchar()) != '\n' && c != EOF) {}

    do {
        printf("Informe a operacao (+, -, *, /): ");
        scanf("%c", &operacao);

        while ((c = getchar()) != '\n' && c != EOF) {}
    } while (operacao != '+' && operacao != '-' &&
             operacao != '*' && operacao != '/'
    );
    
    printf("Informe o segundo operando: ");
    scanf("%lf", &num2);

    printf(
        "%f %c %f = %f",
        num1,
        operacao,
        num2,
        calcula_op(num1, num2, operacao)
    );

    return 0;
}
