#include <stdio.h>

/* conta caracteres da entrada; 1a. versão */
int main(void)
{
    long nc = 0; // Usa long para contadores maiores

    while (getchar() != EOF) {
        ++nc; // Operador de pré-incremento
    }
    printf("%ld\n", nc); // %ld para imprimir long
    return 0;
}
