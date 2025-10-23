#include <stdio.h>

/* conta dígitos, espaços, outros */
int main(void)
{
    int c, nbranco, noutro;
    int ndigito[10]; // Vetor para contar dígitos de 0 a 9

    nbranco = noutro = 0;
    for (int i = 0; i < 10; ++i) { // Inicializa o vetor
        ndigito[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') { // Se for dígito
            ++ndigito[c - '0']; // Incrementa contador específico
        } else if (c == ' ' || c == '\n' || c == '\t') { // Se for espaço em branco
            ++nbranco;
        } else { // Outros caracteres
            ++noutro;
        }
    }

    printf("digitos =");
    for (int i = 0; i < 10; ++i) {
        printf(" %d", ndigito[i]);
    }
    printf(", espaço branco = %d, outros = %d\n", nbranco, noutro);
    return 0;
}
