#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

//===============OBJETO MAPA============================================
typedef struct{
    FILE * arquivomapa;
    char ** mapa;
    int nlinhas;
    int ncolunas;
    void (*mostrarMapa)();    
}Mapa;

void mostrarMapa(Mapa * map){
    int l;
    attron(A_BOLD);
    for(l = 0; l < 5; l++){
        printw("%s", map->mapa[l]);
    }
    attron(A_BOLD);
}

void construtorMapa(Mapa * map, int nlinhas, int ncolunas){
    int l;
    map->arquivomapa = fopen("mapa.txt", "r");
    map->nlinhas = nlinhas;
    map->ncolunas = ncolunas;
    map->mapa = (char**) malloc(map->nlinhas * sizeof(char*));
    map->mostrarMapa = mostrarMapa;
    rewind(map->arquivomapa);
    for(l = 0; l < map->nlinhas; l++){
       map->mapa[l] = (char*) malloc(map->ncolunas*sizeof(char));
       fgets(map->mapa[l], 12, map->arquivomapa);
    }
    rewind(map->arquivomapa);
}