#include <stdio.h>

// Usando #define (substituição textual pelo pré-processador)
#define PI_DEFINE 3.14159
#define MENSAGEM_DEFINE "Olá com define!"

// Usando const (variável cujo valor não pode ser alterado após inicialização)
// 'const' tem tipo e escopo definidos.
const double PI_CONST = 3.1415926535;
const char MENSAGEM_CONST[] = "Olá com const!";

int main() {
    double raio = 5.0;
    double circunferencia_define = 2 * PI_DEFINE * raio;
    double circunferencia_const = 2 * PI_CONST * raio;

    printf("%s\n", MENSAGEM_DEFINE);
    printf("Circunferencia (define): %f\n", circunferencia_define);
    
    printf("\n"); // Separador

    printf("%s\n", MENSAGEM_CONST);
    printf("Circunferencia (const): %f\n", circunferencia_const);

    // Tentar modificar uma constante 'const' geralmente causa erro de compilação:
    // PI_CONST = 3.0; // <- Isto daria erro!

    return 0;
}
