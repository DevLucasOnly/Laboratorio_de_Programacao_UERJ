#include <stdio.h>
#include <string.h> // Para strlen

/**
 * @brief Inverte uma string 's' no local.
 * @param s A string a ser invertida.
 */
void inverter_string_local(char s[]) {
    int i, j;
    char temp;
    int len = strlen(s);

    // Itera trocando o caractere do início com o do fim,
    // movendo os índices 'i' e 'j' em direção ao centro.
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// Exemplo de uso
int main() {
    char minha_string[] = "Celacanto";

    printf("Original: %s\n", minha_string);
    inverter_string_local(minha_string);
    printf("Invertida: %s\n", minha_string);

    return 0;
}

