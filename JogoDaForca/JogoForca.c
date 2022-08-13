#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


#include "jogoforca.h"



//======Variáveis globais=======================
//char palavras[][60] = {"PARALELEPIPEDO", "FAGOCITOSE", "ESTERNOCLEIDOMASTODIO", "ESCOPOLAMINA", "SONOPLASTIA"};
FILE * palavras; 
char * campo, * palavra, * letra;
int erros;
//==============================================

int main(){
    letra = (char*) malloc(sizeof(char));
    configuracaoInicial();
    jogo();
    return 0;
}
void jogo(){
    system("clear");
    abertura();
    avatar(erros);
    printf("\n\n%s\n", campo);
    printf("\nDigite uma letra: ");    
    scanf(" %c", letra);
    validarInput(letra);
    system("clear");
    verificaJogada(letra);//                1       0         
    (strcmp(campo, palavra) && erros < 6)?jogo():fim(erros);//strcmp(char) = 0 ->TRUE
}

void configuracaoInicial(){
    //srand(time(NULL));
    palavras = fopen("palavras.txt", "r+");
    palavra = (char*) malloc(60 * sizeof(char));
    campo = (char*) malloc(60 * sizeof(char));

    palavra = sortearPalavra(palavras, 60);
    //palavra = palavras[(rand() % 5)-1]; //----> Implementar escolha de palavras a partir do arquivo txt
    campo = definirCampo(palavra);
    erros = 0;
    fclose(palavras);
}

char * sortearPalavra(FILE * palavras, int tamanhoLinha){
	char * escolhido = (char *) malloc(sizeof(char) * tamanhoLinha);
	int selecao, i;
	srand(time(NULL));
	selecao = rand()%tamanhoTxt(palavras, tamanhoLinha);
	
	for(i = 0; i <= selecao; i++){
		fgets(escolhido, tamanhoLinha, palavras);
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



char * definirCampo(char * escolhido){
    int i;
    char * retorno = (char*) malloc(sizeof(char) * 60);
    for(i = 0; escolhido[i]!= 10; i++){
        retorno[i] = '_';
    }
    retorno[i] = '\n';
    return retorno;
}

void abertura(){
    printf("\n**********************************\n");
    printf("* BEM VINDO(A) AO JOGO DA FORCA! *\n");
    printf("**********************************\n");
    
    printf("Descubra a palavra secreta!\n");
}


void verificaJogada(char *letra){
    int i;
    int acertou = 0;
    *letra = toupper(*letra);
    for (i = 0; palavra[i] != 0; i++){
        if (*letra == palavra[i]){
            campo[i] = palavra[i];
            acertou = 1;          
        }
    }
    (!acertou)?erros++:printf("\nLetra correta!\n\n");   
}

void validarInput(char * caractere){   ;
    while(!(*caractere >= 65 && *caractere <= 90) && !(*caractere >= 97 && *caractere <= 122)){
        system("clear");
        printf("\nSão aceitos somente catacteres não especiais alfabéticos.\n");
        printf("Digite a letra novamente: ");
        scanf(" %c", caractere);        
        printf("\n");
    }
}

void fim(int falhas){
    if(falhas >= 6){
        system("clear");
        avatar(falhas);
        fimTragico();
        printf("\nVocê morreu!\n");
        printf("\nA palavra correta é: %s\n", palavra);
    }else{
        system("clear");
        carinha();
        printf("\nParabéns! Você conseguiu sobreviver!\n");
    }
}

void avatar(int falhas){
    char enforcado[8] = {'O', '/', '|', '\\', '/', '\\', '\0'};
    int i;
    if (falhas > 6){
        falhas = 6;
    }
    for (i = 0; i < falhas; i++){
        if (i == 0){
            printf(" %c\n", enforcado[i]);
        }
        else if (i > 0 && i < 4){
            (i == 3) ? printf("%c\n", enforcado[i]) : printf("%c", enforcado[i]);
        }else{
            (i == 7) ? printf("%c\n", enforcado[i]) : printf("%c ", enforcado[i]);
        }
    }
}


void carinha(){
    printf("\n░░░░░░░░░▄▀▀▀░░░░░░░▀▄░░░░░░░\n");
    printf("░░░░░░░▄▀░░░░░░░░░░░░▀▄░░░░░░\n");
    printf("░░░░░░▄▀░░░░░░░░░░▄▀▀▄▀▄░░░░░\n");
    printf("░░░░▄▀░░░░░░░░░░▄▀░░██▄▀▄░░░░\n");
    printf("░░░▄▀░░▄▀▀▀▄░░░░█░░░▀▀░█▀▄░░░\n");
    printf("░░░█░░█▄▄░░░█░░░▀▄░░░░░▐░█░░░\n");
    printf("░░▐▌░░█▀▀░░▄▀░░░░░▀▄▄▄▄▀░░█░░\n");
    printf("░░▐▌░░█░░░▄▀░░░░░░░░░░░░░░█░░\n");
    printf("░░▐▌░░░▀▀▀░░░░░░░░░░░░░░░░▐▌░\n");
    printf("░░▐▌░░░░░░░░░░░░░░░▄░░░░░░▐▌░\n");
    printf("░░▐▌░░░░░░░░░▄░░░░░█░░░░░░▐▌░\n");
    printf("░░░█░░░░░░░░░▀█▄░░▄█░░░░░░▐▌░\n");
    printf("░░░▐▌░░░░░░░░░░▀▀▀▀░░░░░░░▐▌░\n");
    printf("░░░░█░░░░░░░░░░░░░░░░░░░░░█░░\n");
    printf("░░░░▐▌▀▄░░░░░░░░░░░░░░░░░▐▌░░\n");
    printf("░░░░░█░░▀░░░░░░░░░░░░░░░░▀░░░\n");


}

void fimTragico(){
    printf("\n\n███████████████████████████\n");
    printf("███████▀▀▀░░░░░░░▀▀▀███████\n");
    printf("████▀░░░░░░░░░░░░░░░░░▀████\n");
    printf("███│░░░░░░░░░░░░░░░░░░░│███\n");
    printf("██▌│░░░░░░░░░░░░░░░░░░░│▐██\n");
    printf("██░└┐░░░░░░░░░░░░░░░░░┌┘░██\n");
    printf("██░░└┐░░░░░░░░░░░░░░░┌┘░░██\n");
    printf("██░░┌┘▄▄▄▄▄░░░░░▄▄▄▄▄└┐░░██\n");
    printf("██▌░│██████▌░░░▐██████│░▐██\n");
    printf("███░│▐███▀▀░░▄░░▀▀███▌│░███\n");
    printf("██▀─┘░░░░░░░▐█▌░░░░░░░└─▀██\n");
    printf("██▄░░░▄▄▄▓░░▀█▀░░▓▄▄▄░░░▄██\n");
    printf("████▄─┘██▌░░░░░░░▐██└─▄████\n");
    printf("█████░░▐█─┬┬┬┬┬┬┬─█▌░░█████\n");
    printf("████▌░░░▀┬┼┼┼┼┼┼┼┬▀░░░▐████\n");
    printf("█████▄░░░└┴┴┴┴┴┴┴┘░░░▄█████\n");
    printf("███████▄░░░░░░░░░░░▄███████\n");
    printf("██████████▄▄▄▄▄▄▄██████████\n");
    printf("███████████████████████████\n");
}
