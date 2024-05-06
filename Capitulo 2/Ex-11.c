/* 11) Elabore um programa que contenha uma constante qualquer do tipo float.
Use o comando #define. Imprima essa constante. */

#include <stdio.h>

#define EULER 2.71828F // F no final indica que o literal é float e não double

int main() {
    printf("%f\n", EULER);

    return 0;
}
