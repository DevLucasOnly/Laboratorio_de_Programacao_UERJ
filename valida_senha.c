#include <stdio.h>
#include <ctype.h>
#include <string.h>

/**
 * @brief Valida uma senha simples (exemplo).
 * @param senha A string da senha.
 * @return 1 se válida, 0 se inválida.
 */
int valida_senha_simples(const char* senha) {
    int tem_maiuscula = 0;
    int tem_minuscula = 0;
    int tem_numero = 0;
    int len = strlen(senha);

    // Regra Exemplo: Mínimo 6 caracteres
    if (len < 6) {
        return 0; 
    }

    // Itera pela senha verificando os tipos de caracteres
    for (int i = 0; i < len; i++) {
        char c = senha[i];
        if (isupper(c)) {
            tem_maiuscula = 1;
        } else if (islower(c)) {
            tem_minuscula = 1;
        } else if (isdigit(c)) {
            tem_numero = 1;
        } 
        // Adicione outras verificações se necessário (ex: símbolos, espaços)
        // else if (!isalnum(c)) { return 0; // Inválida se não for alfanumérico }
    }

    // Regra Exemplo: Deve ter pelo menos uma de cada
    if (tem_maiuscula && tem_minuscula && tem_numero) {
        return 1; // Válida
    } else {
        return 0; // Faltou algum tipo
    }
}

// Exemplo de uso na main (pode remover ou adaptar para a prova)
int main() {
    char teste1[] = "Senha123";
    char teste2[] = "senhafraca";
    char teste3[] = "S1curta";

    printf("'%s': %s\n", teste1, valida_senha_simples(teste1) ? "Aceita" : "Rejeitada");
    printf("'%s': %s\n", teste2, valida_senha_simples(teste2) ? "Aceita" : "Rejeitada");
    printf("'%s': %s\n", teste3, valida_senha_simples(teste3) ? "Aceita" : "Rejeitada");

    return 0;
}

