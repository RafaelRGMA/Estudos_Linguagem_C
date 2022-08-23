#include <stdio.h>
#include <stdlib.h>
//#include <ncurses.h>

//===============OBJETO MAPA============================================
typedef struct{
    FILE * arquivomapa;
    char ** mapa;
    int nlinhas;
    int ncolunas;
    void (*mostrarMapa)();
	void (*carregarMapa)();
	void (*salvarMapa)();
}Mapa;

void salvarMapa(Mapa * map, char ** matriz){
	int l;
	rewind(map->arquivomapa);
    for(l = 0; l < map->nlinhas; l++){
    	fprintf(map->arquivomapa, "%s", matriz[l]);    
		//fwrite(matriz[l], map->ncolunas, sizeof(char), map->arquivomapa);
		printf("%s", matriz[l]);
	}
	rewind(map->arquivomapa);
}

void carregarMapa(Mapa * map){
	int l;
	rewind(map->arquivomapa);
    for(l = 0; l < map->nlinhas; l++){
		fgets(map->mapa[l], 12, map->arquivomapa);
	}
	rewind(map->arquivomapa);
}

void mostrarMapa(Mapa * map){
    int l;
    map->carregarMapa(map);
    //attron(A_BOLD);
    for(l = 0; l < 5; l++){
        printf("%s", map->mapa[l]);
    }
    //attron(A_BOLD);
}

void construtorMapa(Mapa * map, int nlinhas, int ncolunas){
    int l;
    map->arquivomapa = fopen("mapa.txt", "r+");
    map->nlinhas = nlinhas;
    map->ncolunas = ncolunas;
    map->mapa = (char**) malloc(map->nlinhas * sizeof(char*));
    map->mostrarMapa = mostrarMapa;
	map->carregarMapa  = carregarMapa;
	map->salvarMapa = salvarMapa; 
    for(l = 0; l < map->nlinhas; l++){
       map->mapa[l] = (char*) malloc(map->ncolunas*sizeof(char));       
    }    
}
