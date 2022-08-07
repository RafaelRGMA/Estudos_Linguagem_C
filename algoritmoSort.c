#include <stdio.h>
#include <stdlib.h>

//=======Estruturas========================
typedef struct{
	char nome[20];
	double valor;
}Carro;
//=========================================



//=======Prototipagem de funções===========
Carro * menorEmaior(Carro * frota, int tamanhomax);
Carro * ordenar(Carro * frota, int tamanhomax);
Carro * ordenarInsercao (Carro * frota, int tamanhomax);
//=========================================

//=======Variáveis globais=================
Carro carros[] = {{"Lamborghini", 1000000.00}, {"Jeep", 45000.00}, {"Cacareco", 10000.00}, {"Brasília", 16000.00}, {"Smart", 46000.00}, {"Fusca", 17000.00}, {"Ferrari", 1200000.00}, {"Uno", 30000.00}};
Carro barato;
Carro * selecionados;
//=========================================



int main(){
	int i;
	selecionados = (Carro*) malloc(2 * sizeof(Carro));
	selecionados = ordenarInsercao(carros, (sizeof(carros)/sizeof(Carro)));
	

	for(i = 0; i < (sizeof(carros)/sizeof(Carro)); i++){
		printf("\n%s\n", selecionados[i].nome);
		printf("R$%.2f\n", selecionados[i].valor);
	}


	return 0;
}


Carro * menorEmaior (Carro * frota, int tamanhomax){	
	Carro * retorno = (Carro*) malloc(sizeof(Carro)*2);
	int i;

	retorno[0] = frota[0];
	retorno[1] = frota[0];
	
	
	for(i = 0; i < tamanhomax; i++){
		(retorno[0].valor > frota[i].valor)? retorno[0] = frota[i]:retorno[0];
		(retorno[1].valor < frota[i].valor)? retorno[1] = frota[i]:retorno[1];
	}	
	return retorno;
}

Carro * ordenar(Carro * frota, int tamanhomax){
	Carro * retorno = (Carro*) malloc(sizeof(Carro)*tamanhomax);
	Carro registrador;
	int i, k;

	retorno = frota;
	for(i = 0; i < (tamanhomax-1); i++){
		for(k = (i+1); k < tamanhomax; k++){
			if(frota[i].valor > frota[k].valor){
				registrador = retorno[i];
				retorno[i] = retorno[k];
				retorno[k] = registrador;			
			}
		}
	}
	return retorno;
}

Carro * ordenarInsercao (Carro * frota, int tamanhomax){
	Carro * retorno = (Carro*) malloc(sizeof(Carro)*tamanhomax);
	Carro registrador;
	int i, k;
	retorno = frota;
	for(i = 0; i < tamanhomax-1; i++){
		k = i;
		while(retorno[k].valor > retorno[k+1].valor){
			registrador = retorno[k+1];
			retorno[k+1] = retorno[k];
			retorno[k] = registrador;
			k--;
		}
	}
	return retorno;
}