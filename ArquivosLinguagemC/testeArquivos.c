#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//=========PROTOTIPAGEM================================
int tamanhoTxt(FILE * palavras, int tamanhoLinha);
void adicionarRegistro(FILE * documento, char * palavra);
char * sortearPalavra(FILE * palavras, int tamanhoLinha);
//=====================================================

//====VARIÁVEIS GLOBAIS================================
FILE * palavras;
char palavra[60];
char * resultado;
//=====================================================

int main(){
    resultado = (char *) malloc(sizeof(char)*60);	    
    palavras = fopen("palavras.txt", "r+");


	resultado = sortearPalavra(palavras, 60);
	printf("\nPalavra selecionada: %s\n", resultado);

    fclose(palavras);
    return 0;
}

char * sortearPalavra(FILE * palavras, int tamanhoLinha){
	char * escolhido = (char *) malloc(sizeof(char) * tamanhoLinha);
	char linha[60];
	int selecao, i;
	srand(time(NULL));
	selecao = rand()%tamanhoTxt(palavras, tamanhoLinha);
	printf("\nPosição sorteada: %i\n", selecao);
	
	for(i = 0; i <= selecao; i++){
		escolhido = fgets(linha, tamanhoLinha, palavras);
	}
	rewind(palavras);
	return escolhido;
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
	rewind(palavras);
	return i;
}

void adicionarRegistro(FILE * documento, char * palavra){
	fseek(documento, 0 * sizeof(palavra), SEEK_END);
	fprintf(documento, "\n%s", palavra);
	rewind(documento);
}
