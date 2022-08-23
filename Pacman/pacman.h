//===========OBJETO pacman==================================================
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
    void (*mover)();
}Pacman;

void mover(Pacman * pacman, int  comando){	
	pacman->ondeEstou(pacman);
	pacman->verAoRedor(pacman);
	switch(comando){		
		case 119:			
			if(pacman->visaocima == '*'){
				pacman->mapa->mapa[(pacman->endy)-1][pacman->endx] = pacman->avatar;
				pacman->mapa->mapa[pacman->endy][pacman->endx] = '*';				
				//                         objeto mapa      matriz mapa
				pacman->mapa->salvarMapa(pacman->mapa, pacman->mapa->mapa);
			}
			break;
		case 97:
			if(pacman->visaoesquerda == '*'){
				pacman->mapa->mapa[pacman->endy][(pacman->endx) -1] = pacman->avatar;
				pacman->mapa->mapa[pacman->endy][pacman->endx] = '*';
				pacman->mapa->salvarMapa(pacman->mapa, pacman->mapa->mapa);
			}
			break;
		case 68:
			if(pacman->visaodireita == '*'){
				pacman->mapa->mapa[pacman->endy][(pacman->endx) +1] = pacman->avatar;
				pacman->mapa->mapa[pacman->endy][pacman->endx] = '*';
				pacman->mapa->salvarMapa(pacman->mapa, pacman->mapa->mapa);
			}
			break;
		case 115:
			if(pacman->visaobaixo == '*'){
				pacman->mapa->mapa[(pacman->endy)+1][pacman->endx] = pacman->avatar;
				pacman->mapa->mapa[pacman->endy][pacman->endx] = '*';	
				pacman->mapa->salvarMapa(pacman->mapa, pacman->mapa->mapa);
			}
			break;
			
	}
}

void ondeEstou(Pacman * pacman){
    int x, y;
    pacman->mapa->carregarMapa(pacman->mapa);
    for(y = 0; y < pacman->mapa->nlinhas; y++){
        for(x = 0; x < pacman->mapa->ncolunas; x++){
            if(pacman->mapa->mapa[y][x] == pacman->avatar){
                pacman->endx = x;
                pacman->endy = y;
            }            
        }
    }   
}

void verAoRedor(Pacman * pacman){
    pacman->visaocima = pacman->mapa->mapa[pacman->endy - 1][pacman->endx];
    pacman->visaobaixo = pacman->mapa->mapa[pacman->endy + 1][pacman->endx];
    pacman->visaoesquerda = pacman->mapa->mapa[pacman->endy][pacman->endx -1];
    pacman->visaodireita = pacman->mapa->mapa[pacman->endy][pacman->endx + 1];
}

void construtorpacman(Pacman * pacman, Mapa * map){
    pacman->mapa = map;
    pacman->avatar = '@';
    pacman->ondeEstou = ondeEstou;
    pacman->verAoRedor = verAoRedor;
    pacman->mover = mover;
    ondeEstou(pacman);   
}

