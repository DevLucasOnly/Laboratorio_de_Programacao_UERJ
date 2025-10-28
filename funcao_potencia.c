#include <stdio.h>

/**
 * @brief Calcula 'base' elevada à potência 'n' (n >= 0).
 * @param base A base inteira.
 * @param n O expoente inteiro não negativo.
 * @return base^n.
 */
long potencia(int base, int n) {
    long p = 1; // Use long para evitar estouro com resultados grandes

    // Multiplica p por 'base', 'n' vezes
    for (int i = 1; i <= n; ++i) {
        p = p * base;
    }
    return p;
}

// Exemplo de uso
int main() {
    printf("Testando a função potencia:\n");
    for (int i = 0; i < 10; ++i) {
        printf("2^%d = %ld, 3^%d = %ld\n", i, potencia(2, i), i, potencia(3, i));
    }
    return 0;
}
