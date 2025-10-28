#include <stdio.h>
#include <math.h> // Necessário para sqrt()

/**
 * @brief Verifica se um número inteiro n é primo.
 * @param n O número a ser testado.
 * @return 1 (true) se n for primo, 0 (false) caso contrário.
 */
int eh_primo(int n) {
    // Números menores ou iguais a 1 não são primos
    if (n <= 1) {
        return 0;
    }
    // 2 é o único primo par
    if (n == 2) {
        return 1;
    }
    // Outros números pares não são primos
    if (n % 2 == 0) {
        return 0;
    }
    // Verifica divisores ímpares até a raiz quadrada de n
    int limite = (int)sqrt(n); 
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            return 0; // Encontrou um divisor, não é primo
        }
    }
    // Se não encontrou divisores, é primo
    return 1; 
}

// Exemplo de uso na main (pode remover ou adaptar para a prova)
int main() {
    int num1 = 2;
    int num2 = 20;
    long long soma = 0; 

    printf("Verificando primos entre %d e %d:\n", num1, num2);

    for (int i = num1; i <= num2; i++) {
        if (eh_primo(i)) {
            // printf("%d é primo.\n", i); // Descomente para depurar
            soma += i;
        }
    }
    printf("Soma dos primos: %lld\n", soma);

    return 0;
}

