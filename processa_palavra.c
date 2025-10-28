#include <stdio.h>
#include <ctype.h> // Para isspace()

#define MAX_PALAVRA 100

// Protótipo da função que processa uma palavra encontrada
void processa_palavra(char palavra[]);

int main() {
    int c;
    char palavra_atual[MAX_PALAVRA];
    int indice_palavra = 0;
    int dentro_da_palavra = 0; // Estado: 0=fora, 1=dentro

    // Lê caractere por caractere até EOF
    while ((c = getchar()) != EOF) {
        
        // Se NÃO for espaço/tab/newline, adiciona ao buffer da palavra
        if (!isspace(c)) {
            if (indice_palavra < MAX_PALAVRA - 1) {
                palavra_atual[indice_palavra++] = c;
                dentro_da_palavra = 1; 
            }
            // Se exceder MAX_PALAVRA, ignora o resto da palavra (ou trata erro)
        
        // Se FOR espaço/tab/newline E estávamos dentro de uma palavra antes...
        } else if (dentro_da_palavra) {
            // ... finaliza a palavra atual e a processa
            palavra_atual[indice_palavra] = '\0';
            processa_palavra(palavra_atual);

            // Reseta para a próxima palavra
            indice_palavra = 0;
            dentro_da_palavra = 0;
        }
        // Se for espaço e já estávamos fora de uma palavra, ignora (trata múltiplos espaços)
    }

    // Processa a última palavra se o arquivo não terminar com espaço/newline
    if (dentro_da_palavra) {
         palavra_atual[indice_palavra] = '\0';
         processa_palavra(palavra_atual);
    }

    return 0;
}

// Função exemplo para processar a palavra encontrada
void processa_palavra(char palavra[]) {
    // --- Coloque sua lógica de processamento aqui ---
    // Ex: Inverter a palavra, verificar se é número, imprimir, etc.
    printf("Palavra encontrada: %s\n", palavra); 
}
