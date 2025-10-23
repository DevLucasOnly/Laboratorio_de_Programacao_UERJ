/* qsort: ordena v[esq]...v[dir] em ordem crescente */
void quicksort(int v[], int esq, int dir)
{
    void troca(int v[], int i, int j);
    if (esq >= dir) { /* não faz nada se vetor contém */
        return;       /* menos de dois elementos */
    } //
    troca(v, esq, (esq + dir) / 2); /* move elemento de partição */
    int ultimo = esq;              /* para v[0] */
    for (int i = esq + 1; i <= dir; i++) { /* particiona */
        if (v[i] < v[esq]) {
            troca(v, ++ultimo, i);
        }
    }
    troca(v, esq, ultimo); /* recupera elemento de partição */ 
    quicksort(v, esq, ultimo - 1); 
    quicksort(v, ultimo + 1, dir); 
} 
