#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h> //Em breve, impelementaremos com biblioteca ncurses


typedef struct{
    char avatar;
    int x;
    int y;
}Personagem;

typedef struct{
    char avatar;
    int x;
    int y;
}Fantasma;


//======Área de prototipagem=================
void alocarMatriz();
void carregarMapa();
void abrirDocumentoMapa();
void localizarPackman();
void localizarFantasma();
void imprimeMapa();
void movimento();
void moverFantasma();
//===========================================


//====Variáveis globais======================
FILE * arquivomapa;
char ** matrizMapa;
Personagem packman;
Fantasma fantasma;
//===========================================

int main(){
    int i;
    packman.avatar = '@';
    fantasma.avatar = '$';
    system("clear");
    abrirDocumentoMapa();
    alocarMatriz();
    carregarMapa();
    localizarPackman();
    localizarFantasma();
    movimento();
    

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

void movimento(){
    char comando = 0;
    while(comando != 27){      
        imprimeMapa();
        scanf(" %c", &comando);
        system("clear");
        setbuf(stdin, NULL);
        switch(comando){
            case 119: //Seta para cima
                if(matrizMapa[packman.y-1][packman.x] == '*'){                
                    matrizMapa[packman.y][packman.x] = '*';            
                    packman.y--;
                    matrizMapa[packman.y][packman.x] = packman.avatar;
                }
                break;                
                
                              
            case 97: //Seta para esquerda
                if(matrizMapa[packman.y][packman.x-1] == '*'){                    
                    matrizMapa[packman.y][packman.x] = '*';             
                    packman.x--;
                    matrizMapa[packman.y][packman.x] = packman.avatar;
                }
                break;

            case 115: //Seta para baixo
                if(matrizMapa[packman.y+1][packman.x] == '*'){                    
                    matrizMapa[packman.y][packman.x] = '*';             
                    packman.y++;
                    matrizMapa[packman.y][packman.x] = packman.avatar;
                }
                break;

            case 100: //Seta para direita
                if(matrizMapa[packman.y][packman.x+1] == '*'){                    
                    matrizMapa[packman.y][packman.x] = '*';             
                    packman.x++;
                    matrizMapa[packman.y][packman.x] = packman.avatar;
                }
                break;          
                                
        }
        moverFantasma();
    }

}

void moverFantasma(){
    if((fantasma.x - packman.x) > 0){
        matrizMapa[fantasma.y][fantasma.x] = '*';
        fantasma.x--;
        matrizMapa[fantasma.y][fantasma.x] = fantasma.avatar;
    }else if(fantasma.x - packman.x < 0){
        matrizMapa[fantasma.y][fantasma.x] = '*';
        fantasma.x++;
        matrizMapa[fantasma.y][fantasma.x] = fantasma.avatar;
    }

    if((fantasma.y - packman.y) > 0){
        matrizMapa[fantasma.y][fantasma.x] = '*';
        fantasma.y--;
        matrizMapa[fantasma.y][fantasma.x] = fantasma.avatar;
    }else if(fantasma.y - packman.y < 0){
        matrizMapa[fantasma.y][fantasma.x] = '*';
        fantasma.y++;
        matrizMapa[fantasma.y][fantasma.x] = fantasma.avatar;
    }
}

void imprimeMapa(){    
    int i;
    for(i = 0; i < 5; i++){
        printf("%s", matrizMapa[i]);
    }  
}

void localizarPackman(){
    int y,x;
    for(y = 0; y < 5; y++){
        for(x = 0; x < 10; x++){
            if(matrizMapa[y][x] == packman.avatar){
                packman.x = x;
                packman.y = y;
            }
        }
    }

}

void localizarFantasma(){
    int y,x;
    for(y = 0; y < 5; y++){
        for(x = 0; x < 10; x++){
            if(matrizMapa[y][x] == fantasma.avatar){
                fantasma.x = x;
                fantasma.y = y;
            }
        }
    }

}