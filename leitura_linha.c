#include <stdio.h>
#include <string.h> // Para strlen, strcspn

#define MAX_LINHA 1000 // Defina um tamanho máximo razoável

// Protótipo de uma função que processa a linha (exemplo)
void processa_linha(char linha[]);

int main() {
    char linha_atual[MAX_LINHA];

    // Lê linha por linha até EOF (fim do arquivo/entrada)
    while (fgets(linha_atual, sizeof(linha_atual), stdin) != NULL) {
        
        // Remove o '\n' que fgets geralmente inclui, se houver espaço
        linha_atual[strcspn(linha_atual, "\n")] = '\0'; 

        // Chama uma função para fazer o trabalho específico daquela linha
        processa_linha(linha_atual);
    }

    return 0;
}

// Função exemplo para processar a linha lida
void processa_linha(char linha[]) {
    int i = 0;
    char caractere_atual;

    // printf("Processando linha: %s\n", linha); // Exemplo de ação (descomente se útil)

    // Itera pela string caractere a caractere
    while (linha[i] != '\0') {
        caractere_atual = linha[i];

        // --- Coloque sua lógica de processamento aqui ---
        // Ex: Contar caracteres, substituir, verificar condições, etc.
        // putchar(caractere_atual); // Exemplo: reimprimir o caractere

        i++;
    }
    // putchar('\n'); // Adiciona nova linha se necessário após processar
}
