/* 14) O código de César é uma das técnicas de criptografia mais simples e
conhecidas. É um tipo de substituição no qual cada letra do texto é substituída
por outra, que se apresenta n posições após ela no alfabeto. Por exemplo, com
uma troca de três posições, a letra A seria substituída por D, B se tornaria E e
assim por diante. Escreva um programa que faça uso desse código de César para 
três posições. Entre com uma string e imprima a string codificada. Exemplo:
    String: a ligeira raposa marrom saltou sobre o cachorro cansado
    Nova string: d oljhlud udsrvd pduurp vdowrx vreuh r fdfkruur fdqvdgr */

#include <stdio.h>

int main() {
    char    str[128],
            zona_limite[] = {'X', 'Y', 'Z', 'x', 'y', 'z'};

    int     flag;

    printf("Informe a frase: ");
    fgets(str, 64, stdin);

    for (size_t i = 0; (str[i] != '\0') && (str[i] != '\n'); i++) {
        flag = 0;

        if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122)) {
            for (size_t j = 0; j < sizeof(zona_limite); j++) {
                if (str[i] == zona_limite[j]) {
                    str[i] -= 23;
                    flag = 1;
                    break;
                }
            }
        
            if (flag == 0) {
                str[i] += 3;
            }
        }
    }

    printf("\nFrase codificada: %s", str);

    return 0;
}
