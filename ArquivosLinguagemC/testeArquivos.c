#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamanhoTxt(FILE * palavras, int tamanhoLinha);
void adicionarRegistro(FILE * documento, char * palavra);

FILE * palavras;
char palavra[60];

int main(){
	char * novapalavra = (char *) malloc(sizeof(char)*60);
    char * resultado = (char *) malloc(sizeof(char)*60);
	    
    palavras = fopen("palavras.txt", "r+");
    printf("\n%i\n", tamanhoTxt(palavras, 60));
	printf("\nDigite a nova palavra: ");
	scanf("\n%s", novapalavra);
	adicionarRegistro(palavras, novapalavra);
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

void adicionarRegistro(FILE * documento, char * palavra){
	fseek(documento, 0 * sizeof(palavra), SEEK_END);
	fprintf(documento, "\n%s", palavra);
	//fwrite(palavra, sizeof(char), 60, documento); //Parametros: vetor, tamanho da unidade do vetor, número de unidades do vetor, arquivo
	rewind(documento);
}
