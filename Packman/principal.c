#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "mapa.h"


//===========OBJETO PACKMAN==================================================
typedef struct{
    Mapa * mapa;
    char avatar;
    int endx;
    int endy;
    char visaocima;
    char visaobaixo;
    char visaodireita;
    char visaoesquerda;
    void (*ondeEstou)();
    void (*verAoRedor)();
}Packman;

void ondeEstou(Packman * packman){
    int x, y;
    for(y = 0; y < packman->mapa->nlinhas; y++){
        for(x = 0; x < packman->mapa->ncolunas; x++){
            if(packman->mapa->mapa[y][x] == '@'){
                packman->endx = x;
                packman->endy = y;
            }            
        }
    }   
}

void verAoRedor(Packman * packman){
    packman->visaocima = packman->mapa->mapa[packman->endy - 1][packman->endx];
    packman->visaobaixo = packman->mapa->mapa[packman->endy + 1][packman->endx];
    packman->visaoesquerda = packman->mapa->mapa[packman->endy][packman->endx -1];
    packman->visaodireita = packman->mapa->mapa[packman->endy][packman->endx + 1];
}

void construtorPackman(Packman * packman, Mapa * map){
    packman->mapa = map;
    packman->ondeEstou = ondeEstou;
    packman->verAoRedor = verAoRedor;
    ondeEstou(packman);   
}


Mapa mapa;
Packman packman;
int main(){
    initscr();

    construtorMapa(&mapa, 5, 12);
    mapa.mostrarMapa(&mapa);
   
    construtorPackman(&packman, &mapa);
    printw("\nO packman está na coluna %i e na linha %i\n", packman.endx, packman.endy);

    packman.verAoRedor(&packman);

    printw("\nDireita: %c, Cima: %c, Esquerda: %c, Baixo: %c\n", packman.visaodireita, packman.visaocima, packman.visaoesquerda, packman.visaobaixo);

    refresh();
    getch();   
    endwin();
    return 0;
}