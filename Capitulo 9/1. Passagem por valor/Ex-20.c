/* 20) Faça uma função que calcule e retorne o número neperiano e,
e = 2,71828183, usando a série a seguir:
A função deve ter como parâmetro o número de termos que serão somados, N. Note
que quanto maior esse número, mais próxima do valor e estará a resposta. */

#include <stdio.h>

unsigned long long fatorial(int n);
long double euler(int n);

int main() {
    int num = 0;

    do {
        printf("Limite da somatoria para calcular o numero de Euler: ");
        scanf("%d", &num);
    } while (num < 0);

    // Comente esta linha se somente 0 é impresso e estiver utilizando minGW
    printf("Com %d termos,\n\n e = %.20Lf\n", num, euler(num));
    
    // Descomente esta linha se somente 0 é impresso e estiver utilizando minGW
    // __mingw_printf("Com %d termos,\n\n e = %.20Lf\n", num, euler(num));

    /*
    Alternativamente, você pode compilar o programa com a opção
    -D__USE_MINGW_ANSI_STDIO (caso esteja usando o minGW). Ex: 
    
    gcc Ex-20.c -D__USE_MINGW_ANSI_STDIO

    Como último recurso, copie e cole no https://www.onlinegdb.com/
    */

    return 0;
}

unsigned long long fatorial(int n) {
    unsigned long long f = 1;

    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return 1;
    }

    for (int i = n; i > 0; i--) {
        f *= i;
    }

    return f;
}

long double euler(int n) {
    long double result = 0;

    if (n < 0) {
        return -1;
    }
    

    for (int i = 0; i <= n; i++) {
        result += 1.0L / fatorial(i);
    }
    
    return result;
}
