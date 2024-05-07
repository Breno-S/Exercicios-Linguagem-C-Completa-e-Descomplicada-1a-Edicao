/* 14) Faça um programa que converta uma letra maiúscula em letra minúscula.
Use a tabela ASCII para isso. */

#include <stdio.h>

int main() {
    char    letra_maiuscula,
            letra_minuscula;

    printf("Informe uma letra maiuscula: ");
    scanf("%c", &letra_maiuscula);

    // 32 = distância entre uma letra maiuscula e sua minúscula na tabela ASCII
    letra_minuscula = letra_maiuscula + 32; 

    printf("%c\n", letra_minuscula);

    return 0;
}

/****************************************************************************** 
 *                   ALTERNATIVA COM OPERADORES BIT-A-BIT                     *
 ******************************************************************************/

// A = 65 = 0100 0001 
//                    OU
//     32 = 0010 0000
//          --------- IGUAL
// a = 97 = 0110 0001 

/*
#include <stdio.h>

int main() {
    char    letra_maiuscula,
            letra_minuscula;

    printf("Informe uma letra maiuscula: ");
    scanf("%c", &letra_maiuscula);

    letra_minuscula = (char) (letra_maiuscula | 32); 

    printf("%c\n", letra_minuscula);

    return 0;
}
*/
