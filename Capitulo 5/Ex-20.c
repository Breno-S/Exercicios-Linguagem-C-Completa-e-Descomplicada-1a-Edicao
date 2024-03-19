/* 20) Faça um programa que leia um valor inteiro e positivo N, calcule o mostre
o valor E, conforme a fórmula a seguir: 
    E = 1/1! + 1/2! + 1/3! + ... 1/N! */

/* 
Quando o valor inserido pelo usuário aumenta, o resultado se aproxima ao
número de Euler menos um (e - 1). Tente observar isso pelo debugger. Criei
o programa com os tipos de dados mais precisos, mas dependendo da sua
máquina ou do valor que inserir, o cálculo ou a impressão do resultado no
final do programa talvez não saiam como o esperado.

A maior precisão no resultado foi obtida inserindo 20 como entrada.
*/

#include <stdio.h>

int main() {
    int num,    // valor de N

        y,      // maior fator do fatorial de n, em cada iteração
                // (n, n-1, n-2...)

        x;      // variável que assume o valor dos fatores do fatorial de y, em
                // cada iteração (y, y-1, y-2...)

    unsigned long long fact;    // denominador
                                // (resultado do fatorial de y em cada iteração) 

    long double	result = 1.0L;  // resultado final (soma das parcelas)

    do {
        printf("Digite um numero natural: ");
        scanf("%d", &num);
    } while (num < 0);

    if (num > 1) {
        x = y = fact = num;     // tudo é igual ao número inserido

        for (int i = 1; i < num; i++, y--) {
            x = fact = y;

            for (int j = 1; j < y; j++, x--) {
                fact *= x - 1;
            }

            result += 1.0L / fact;
        }
    }

    // Comente esta linha se somente 0 é impresso e estiver utilizando minGW
    printf("E = %.20Lf", result); 
    
    // Descomente esta linha se somente 0 é impresso e estiver utilizando minGW
    // __mingw_printf("E = %.20Lf", result); 

    /*
    Alternativamente, você pode compilar o programa com a opção
    -D__USE_MINGW_ANSI_STDIO (caso esteja usando o minGW). Ex: 
    
    gcc Ex-20.c -D__USE_MINGW_ANSI_STDIO

    Como último recurso, copie e cole no https://www.onlinegdb.com/
    */
    
    return 0;
}
