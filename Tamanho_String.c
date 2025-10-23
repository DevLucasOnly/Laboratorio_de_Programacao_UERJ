/* strlen: retorna o tamanho de uma string s */
int strlen(char *s) // s é um ponteiro para char
{
    int n;
    for (n = 0; *s != '\0'; s++) {
        n++;  
    } 
    return n;
} 
