#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoTxt(FILE * palavras, int tamanhoLinha);

FILE * palavras;
char palavra[60];

int main(){
    char * resultado = (char *) malloc(sizeof(char)*60);    
    palavras = fopen("palavras.txt", "r");
    printf("\n%i\n", tamanhoTxt(palavras, 60));

    fclose(palavras);

    return 0;
}

int tamanhoTxt(FILE * palavras, int tamanhoLinha){
	int i = 0;
	char linha[tamanhoLinha];
	char linhaAnterior[tamanhoLinha];
	while(strcmp(linha, linhaAnterior) != 0){	
		strcpy(linhaAnterior, linha);
		fgets(linha, tamanhoLinha, palavras);
		if(strcmp(linha, linhaAnterior) == 0){
			break;
		}
		i++;
	}
	return i;
}
