#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>
#include "mapa.h"
#include "pacman.h"

Mapa mapa;
Pacman pacman;
int main(){
   	char comando;

    construtorMapa(&mapa, 5, 12);
    mapa.mostrarMapa(&mapa);
   
    construtorpacman(&pacman, &mapa);
    printf("\nDigite 'w' para mover\n");
    scanf(" %c", &comando);
    pacman.mover(&pacman, comando);

   	fclose(mapa.arquivomapa);
    return 0;
}
