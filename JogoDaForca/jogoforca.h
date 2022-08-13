#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//========== Área de prototipagem ==============
void configuracaoInicial();
int tamanhoTxt(FILE * palavras, int tamanhoLinha);
char * sortearPalavra(FILE * palavras, int tamanhoLinha);
char * definirCampo(char * escolhido);
void abertura();
void jogo();
void verificaJogada(char * letra);
void validarInput(char * caractere);
void carinha();
void avatar(int falhas);
void fim();
void fimTragico();
//==============================================