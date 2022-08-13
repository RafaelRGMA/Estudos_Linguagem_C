#include <stdio.h>
#include <stdlib.h>


//======Área de prototipagem=================
void alocarMatriz();
void carregarMapa();
void abrirDocumentoMapa();
//===========================================


//====Variáveis globais======================
FILE * arquivomapa;
char ** matrizMapa;
//===========================================

int main(){
    int i;
    abrirDocumentoMapa();
    alocarMatriz();
    carregarMapa();

    

   
    printf("%s", matrizMapa[0]);
    printf("%s", matrizMapa[1]);
    printf("%s", matrizMapa[2]);
    printf("%s", matrizMapa[3]);
    printf("%s\n", matrizMapa[4]);
    

    return 0;
}

void abrirDocumentoMapa(){
    arquivomapa = fopen("mapa.txt", "r");
    if(arquivomapa == NULL){
        printf("\nErro durante a abertura do documento!\n");
        system("pause");
        exit(1);
    }
}

void alocarMatriz(){
    int i;
    matrizMapa = (char**) malloc(5*sizeof(char*));
    for(i = 0; i < 5; i++){
        matrizMapa[i] = (char*) malloc(12 * sizeof(char));
    }
}

void carregarMapa(){
    int i;
    rewind(arquivomapa);
    for(i = 0; i < 5; i++){
        fgets(matrizMapa[i], 12, arquivomapa); //São lidos 11 caracteres. O último caractere é um '\n'
    }
    rewind(arquivomapa);
}