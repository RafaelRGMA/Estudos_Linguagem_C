#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>



//========== Área de prototipagem ==============
void configuracaoInicial();
    char * definirCampo(char * escolhido);
void abertura();
void jogo();
    void verificaJogada(char * letra);
        void validarInput(char * caractere);
    void avatar(int falhas);
    void fim();

//==============================================

//======Variáveis globais=======================
char palavras[][60] = {"PARALELEPIPEDO", "FAGOCITOSE", "ESTERNOCLEIDOMASTODIO", "ESCOPOLAMINA", "SONOPLASTIA"};
char * campo, * palavra, * letra;
int erros;
//==============================================

int main(){
    letra = (char*) malloc(sizeof(char));
    configuracaoInicial();
    abertura();
    jogo();
    return 0;
}
void jogo(){
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
    srand(time(NULL));
    palavra = (char*) malloc(60 * sizeof(char));
    palavra = palavras[(rand() % 5)-1];
    campo = (char*) malloc(60 * sizeof(char));
    campo = definirCampo(palavra);
    erros = 0;
}



char * definirCampo(char * escolhido){
    int i;
    char * retorno = (char*) malloc(60 * sizeof(char));
    for(i = 0; escolhido[i]!= 0; i++){
        retorno[i] = '_';
    }
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
        printf("\nSão aceitos somente catacteres não especiais alfabéticos.\n");
        printf("Digite a letra novamente: ");
        scanf(" %c", caractere);        
        printf("\n");
    }
}

void fim(int falhas){
    if(falhas >= 6){
        avatar(falhas);
        printf("\nVocê morreu!\n");
    }else{
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
