/* 20) Faça um programa que leia um valor inteiro e positivo N, calcule o mostre
o valor E, conforme a fórmula a seguir: 
    E = 1/0! + 1/1! + 1/2! + 1/3! + ... 1/N! */

/* 
Conforme o valor inserido pelo usuário aumenta, o resultado se aproxima do
número de Euler. Criei o programa com os tipos de dados mais precisos, mas
dependendo da sua máquina ou do valor que inserir, o cálculo ou a impressão do
resultado no final do programa talvez não saiam como o esperado.

A maior precisão no resultado foi obtida inserindo 19 como entrada.
*/

#include <stdio.h>

int main() {
    int N,

        x;  // Assume o valor dos fatores de N! (N, N-1, N-2, ...)
            // em cada iteração

    unsigned long long fact;    // Denominador (N! em cada iteração)

    long double	result = 1.0L;  // Resultado final (soma das parcelas de E)

    do {
        printf("Digite um numero natural: ");
        scanf("%d", &N);
    } while (N < 0);

    for (; N >= 1; N--) {
        fact = N;

        for (x = N; x > 1; x--) {
            fact *= x - 1;
        }

        result += 1.0L / fact;
    }


    // Comente esta linha se somente 0 é impresso e estiver utilizando minGW
    printf("E = %.20Lf\n", result); 

    // Descomente esta linha se somente 0 é impresso e estiver utilizando minGW
    // __mingw_printf("E = %.20Lf\n", result); 

    /*
    Alternativamente, você pode compilar o programa com a opção
    -D__USE_MINGW_ANSI_STDIO (caso esteja usando o minGW). Ex: 

    gcc Ex-20.c -D__USE_MINGW_ANSI_STDIO

    Como último recurso, copie e cole no https://www.onlinegdb.com/
    */

    return 0;
}
