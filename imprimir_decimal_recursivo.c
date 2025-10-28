#include <stdio.h>

/**
 * @brief Imprime um inteiro n em formato decimal usando recursão.
 * Nota: Não lida corretamente com o maior inteiro negativo (INT_MIN).
 * @param n O inteiro a ser impresso.
 */
void impdec_recursivo(int n) {
    // Caso base: se n for negativo, imprime '-' e torna n positivo
    if (n < 0) {
        putchar('-');
        // Cuidado: -INT_MIN pode estourar se INT_MIN == -INT_MAX - 1
        // Para simplificar, assumimos que n não é INT_MIN aqui.
        n = -n; 
    }

    // Passo recursivo: se n / 10 não for zero, chama a função para o resto
    if (n / 10) {
        impdec_recursivo(n / 10);
    }

    // Imprime o último dígito (após as chamadas recursivas retornarem)
    putchar(n % 10 + '0'); // Converte dígito (0-9) para caractere ('0'-'9')
}

// Exemplo de uso
int main() {
    int numero1 = 12345;
    int numero2 = -987;
    int numero3 = 0;

    printf("Imprimindo %d: ", numero1);
    impdec_recursivo(numero1);
    putchar('\n');

    printf("Imprimindo %d: ", numero2);
    impdec_recursivo(numero2);
    putchar('\n');
    
    printf("Imprimindo %d: ", numero3);
    impdec_recursivo(numero3);
    putchar('\n');

    return 0;
}

