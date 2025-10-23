#define MAXLIN 5000 // máximo de linhas a ordenar
char *ptrlinha[MAXLIN]; // Vetor de ponteiros para char

int lelinhas(char *ptrlinha[], int nlinhas);
void imprlinhas(char *ptrlinha[], int nlinhas);
void qsort(char *ptrlinha[], int esq, int dir); // qsort modificada

int main()
{
    int nlinhas; // número de linhas lidas
    if ((nlinhas = lelinhas(ptrlinha, MAXLIN)) >= 0) {
        qsort(ptrlinha, 0, nlinhas - 1); // Passa vetor de ponteiros
        imprlinhas(ptrlinha, nlinhas);
        return 0;
    } else { /* ... erro ... */ }
}
