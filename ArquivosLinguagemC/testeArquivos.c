#include <stdio.h>
#include <stdlib.h>


FILE * palavras;
char palavra[60];

int main(){
    char * resultado = (char *) malloc(sizeof(char)*60);
    palavras = fopen("palavras.txt", "r");
    (palavras == NULL)?exit(1):printf("\narquivo aberto com sucesso\n");
    resultado = fgets(palavra, 60, palavras);
    printf("\nlendo a palavra: %s", palavra);
    printf("\nOu pode ser lido desta maneira: %s\n", resultado);
    fclose(palavras);

    return 0;
}