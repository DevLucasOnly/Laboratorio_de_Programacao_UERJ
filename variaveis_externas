#include <stdio.h>

#define MAXLINHA 1000 // tamanho máximo da linha

int max;                 // tamanho visto até agora (externa)
char linha[MAXLINHA];    // linha de entrada (externa)
char maior[MAXLINHA];   // linha mais longa (externa)

int lelinha(void); // Funções agora usam externas
void copia(void);

/* imprime maior linha entrada; versão especializada */
int main(void)
{
    int tam;
    // extern int max; // Declaração extern opcional aqui
    // extern char maior[];
    max = 0;
    while ((tam = lelinha()) > 0) {
        if (tam > max) {
            max = tam;
            copia();
        }
    }
    if (max > 0) { // entrada tinha uma linha
        printf("%s", maior);
    }
    return 0;
}

/* lelinha: versão especializada */
int lelinha(void)
{
    int c, i = 0;
    // extern char linha[]; // Declaração extern opcional aqui
    // ... (usa 'linha' diretamente) ...
    linha[i] = '\0';
    return i;
}

/* copia: versão especializada */
void copia(void)
{
    int i = 0;
    // extern char linha[], maior[]; // Declaração extern opcional aqui
    while ((maior[i] = linha[i]) != '\0') {
        ++i;
    }
}
