/* 17) Escreva um programa que leia um número inteiro positivo N e em seguida
imprima N linhas do chamado triângulo de Floyd:

1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
16 17 18 19 20 21 */

#include <stdio.h>

int main() {
	int qtd_linhas, x = 1;

	do {
		printf("Informe um numero de linhas para o triangulo de Floyd: ");
		scanf("%d", &qtd_linhas);

		char c;
		while ((c = getchar()) != '\n' && c != EOF) {}

	} while (qtd_linhas < 0);


	for (int i = 0; i <= qtd_linhas; i++) {
		for (int j = 0; j < i; j++) {
			printf("%llu ", x++);
		}
		printf("\n");
	}


	return 0;
}
