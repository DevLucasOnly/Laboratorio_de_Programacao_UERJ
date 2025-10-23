// Uma forma de criptografia usa chaves formadas com todas as letras maiúsculas, entre A e Z, vírgula(,), ponto (.) e espaço. Cada caractere tem um valor: A=1.. Z=26, vírgula=27, ponto=28 e espaço=29. O usuário dá uma frase que deve ser convertida numa chave criptográfica válida do seguinte modo: Todas as letras da frase devem ser convertidas para maiúsculas, e todos os caracteres diferentes de letras, vírgula, ponto e espaço devem ser eliminados. Só deve permanecer a primeira ocorrência de cada caractere. No final da string, devem ser adicionados os caracteres que faltaram.

// Assim, a frase “Celacanto provoca maremoto” deve ser convertida numa chave válida como “CELANTO PRVMBDFGHIJKQSUWXYZ,.”

// 1) Crie um programa que faça essa conversão entre uma frase e uma chave válida.
// Pontuação:
// a) Função que faz a conversão correta para letras maiúsculas de todas as letras (1pt)
// b) Função que elimina todos os caracteres diferentes de letra, vírgula, ponto e espaço, deixando apenas a primeira ocorrência de cada um desses caracteres (2pts)
// c) Função que completa a chave corretamente com os caracteres que faltam. (3pts)

// 2) Dada uma chave criptográfica do tipo acima, faça uma função que converta uma frase, passada como parâmetro, usando o seguinte algoritmo: comece com um índice apontando para o primeiro caractere na chave. Para cada caractere na frase a ser transcrita, o índice é movido para a direita pelo valor do caractere (A=1..Z=26, vírgula=27, ponto=28 e espaço=29) a partir da sua posição atual. Voltando para o início se o fim da chave é atingido (ou seja, é circular). O valor criptografado é aquele dado pelo caractere onde o índice parou. Assim, a frase CELACANTO PROVOCA MAREMOTO, com a chave “CELANTO PRVMBDFGHIJKQSUWXYZ,.” produz a saída “APQSXYVEHHAS CGJKKANU,MZIA” (3pts)

// 3) Considere que todas a funções acima estejam funcionando corretamente. Sem uso de variável global, escreva a função principal main() que receba uma frase para ser convertida em chave válida e em seguida, usando a chave recém-criada, criptografe outra frase lida pelo teclado. (1pt) 





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
