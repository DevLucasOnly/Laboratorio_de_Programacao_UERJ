#include <stdio.h>
#include <string.h>
#include <ctype.h>

void gerarChaveValida(const char* frase_base, char* chave_final);
int obterValorCaractere(char c);
void criptografar(const char* frase, const char* chave, char* frase_cifrada);

int main() {
    char frase_base_chave[256];
    char chave[30];
    char frase_para_criptografar[256];
    char texto_cifrado[256];

    printf("Digite a frase base para gerar a chave: ");
    fgets(frase_base_chave, sizeof(frase_base_chave), stdin);
    frase_base_chave[strcspn(frase_base_chave, "\n")] = 0;

    gerarChaveValida(frase_base_chave, chave);
    printf("-------------------------------------------\n");
    printf("Chave gerada: %s\n", chave);
    printf("-------------------------------------------\n\n");

    printf("Digite a frase para criptografar: ");
    fgets(frase_para_criptografar, sizeof(frase_para_criptografar), stdin);
    frase_para_criptografar[strcspn(frase_para_criptografar, "\n")] = 0;

    criptografar(frase_para_criptografar, chave, texto_cifrado);

    printf("-------------------------------------------\n");
    printf("Frase criptografada: %s\n", texto_cifrado);
    printf("-------------------------------------------\n");

    return 0;
}

void gerarChaveValida(const char* frase_base, char* chave_final) {
    const char ALFABETO_COMPLETO[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ, .";
    char ja_visto[256] = {0};
    int indice_chave = 0;

    for (int i = 0; i < strlen(frase_base); ++i) {
        char c = toupper(frase_base[i]);

        if ((isalnum(c) || c == ',' || c == '.' || c == ' ') && ja_visto[(unsigned char)c] == 0) {
            chave_final[indice_chave++] = c;
            ja_visto[(unsigned char)c] = 1;
        }
    }

    for (int i = 0; i < strlen(ALFABETO_COMPLETO); ++i) {
        char c = ALFABETO_COMPLETO[i];
        if (ja_visto[(unsigned char)c] == 0) {
            chave_final[indice_chave++] = c;

        }
    }

    chave_final[indice_chave] = '\0';
}


int obterValorCaractere(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 1;
    }
    if (c == ',') {
        return 27;
    }
    if (c == '.') {
        return 28;
    }
    if (c == ' ') {
        return 29;
    }
    return 0;
}

void criptografar(const char* frase, const char* chave, char* frase_cifrada) {
    int indice_chave = 0;
    int indice_cifrada = 0;
    int tamanho_chave = strlen(chave);

    for (int i = 0; i < strlen(frase); ++i) {
        char c = toupper(frase[i]);
        int valor = obterValorCaractere(c);

        if (valor > 0) {
            indice_chave = (indice_chave + valor) % tamanho_chave;
            frase_cifrada[indice_cifrada++] = chave[indice_chave];
        }
    }
    frase_cifrada[indice_cifrada] = '\0';
}
