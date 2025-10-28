#include <stdio.h>
#include <ctype.h> // Para isdigit, isspace, etc.

int main() {
    int c;
    long nc_digitos = 0;
    long nc_espacos = 0; // Inclui espaço, \t, \n, etc.
    long nc_letras = 0;
    long nc_outros = 0;

    // Lê caractere por caractere
    while ((c = getchar()) != EOF) {
        if (isdigit(c)) {
            nc_digitos++;
        } else if (isspace(c)) {
            nc_espacos++;
        } else if (isalpha(c)) { // isalpha() verifica se é letra (maiúscula ou minúscula)
            nc_letras++;
        } else {
            nc_outros++;
        }
    }

    printf("Contagem:\n");
    printf("Digitos = %ld\n", nc_digitos);
    printf("Espaços em branco = %ld\n", nc_espacos);
    printf("Letras = %ld\n", nc_letras);
    printf("Outros = %ld\n", nc_outros);

    return 0;
}

