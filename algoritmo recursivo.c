#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct brasileirao {
	int posicao;
	int pontos;
	char time[50];
};
typedef struct brasileirao Br;

/*
	Autora: Danielen Silva	Data: 28/11/2023
	
	Algoritmo recursivo
	
	1) Tabela brasileirão serie A
	
	2) busca: nome e posição
	
	3) exibir os 5 primeiros colocados
	
	4) exibir os 5 ultimos colocados
	
	5) exibir a diferença de pontos dos 5 ultimos
	
	6) exibir a diferença de pontos dos 5 primeiros
	
	7) reordenar a tabela para exibir metade dos times
*/
Br nomeEPosicao(Br tabela[], int i) {
	
	if (i < 10) {
		printf("\nPosição %i\nTime: %s\nPontos: %i\n", tabela[i].posicao, tabela[i].time, tabela[i].pontos);
		nomeEPosicao(tabela, i+1);
	}
}


Br primeirosCincoColocados(Br tabela[], int i) {
	if (i < 5) {
		printf("\nPosição %i\nTime: %s\nPontos: %i\n", tabela[i].posicao, tabela[i].time, tabela[i].pontos);
		
		primeirosCincoColocados(tabela, i+1);
	}
}

Br ultimosCincoColocados(Br tabela[], int i) {
	//	10, 9, 8, 7, 6
	if (i >= 5 && i <= 10) {
		printf("\nPosição %i\nTime: %s\nPontos: %i\n", tabela[i-1].posicao, tabela[i-1].time, tabela[i-1].pontos);
		ultimosCincoColocados(tabela, i-1);
	}
}

Br difCincoP(Br tabela[], int i) {
	int difPontos = 0;
	int num1, num2;
	
	if (i < 5) {
		
		num1 = tabela[i].pontos;
		num2 = tabela[i+1].pontos;
		
		difPontos = num1 - num2;
	
		printf("\nDiferença de pontuação entre %s e %s é %i",tabela[i].time, tabela[i+1].time, difPontos);
		
		difCincoP(tabela, i+1);
	} 
}

Br difCincoU(Br tabela[], int i) {
	int difPontos = 0;
	int num1, num2;
	
	if (i >= 5 && i <= 10) {
		num1 = tabela[i].pontos;
		num2 = tabela[i-1].pontos;
		
		difPontos = num2 - num1;
	
		printf("\nDiferença de pontuação entre %s e %s é %i",tabela[i].time, tabela[i-1].time, difPontos);
		
		difCincoU(tabela, i-1);
	}
}
	
Br selectionSort(Br tabela[], int i) {
	int min;
	int j=0;
	char aux_time[255];
	int aux_pontos, aux_pos;
	
	if (i == 10) {
		return;
	} else {
		min = i; // Posição a ser ordenada
		
		for (j = i+1; j < 10; j++) {
			if(strcmp(tabela[min].time, tabela[j].time) > 0) {
				min = j; // indice 2
			}
			strcpy(aux_time, tabela[min].time);
			aux_pontos = tabela[min].pontos;
			aux_pos = tabela[min].posicao;
			
			strcpy(tabela[min].time, tabela[i].time);
			tabela[min].pontos = tabela[i].pontos;
			tabela[min].posicao = tabela[i].posicao;
	
			strcpy(tabela[i].time, aux_time);
			tabela[i].pontos = aux_pontos;
			tabela[i].posicao = aux_pos;
			
		}
		printf("[%i] %s\n", i, tabela[i].time);
		selectionSort(tabela, i+1);	
	}
}

Br insertionSort(Br tabela[], int i) {
	int j;
	Br atual;
	if (i == 10) {
		return;
	} else {
		atual = tabela[i];
		j = i - 1;
		
		while((j >= 0) && (strcmp(atual.time, tabela[j].time) > 0)) {
			tabela[j+1] = tabela[j];
			j = j - 1;
		}
		
		tabela[j + 1] = atual;
		insertionSort(tabela, i+1);
		printf("[%i] %s\n", i, tabela[i].time);
	}
}


Br busca(Br tabela[], int i, char nomeTime[]) {
	if (i < 10){
		if(strcasecmp(nomeTime, tabela[i].time) == 0) {
			printf("\nPosição %i\nTime: %s\nPontos: %i\n", tabela[i].posicao, tabela[i].time, tabela[i].pontos);
		}
		busca(tabela, i+1, nomeTime);
	}
	
}
int main() {
	setlocale(LC_ALL, "portuguese");
	
	Br tabela[10];
	int i;
	
	for (i = 0; i < 10; i++) {
		strcpy(tabela[i].time, "NULL");
		tabela[i].posicao = 0;
		tabela[i].pontos = 0;
	}
	
	strcpy(tabela[0].time, "Palmeiras");
	tabela[0].posicao = 1;
	tabela[0].pontos = 63;
	
	strcpy(tabela[1].time, "Flamengo");
	tabela[1].posicao = 2;
	tabela[1].pontos = 63;
	
	strcpy(tabela[2].time, "Botafogo");
	tabela[2].posicao = 3;
	tabela[2].pontos = 62;
	
	strcpy(tabela[3].time, "Atlético");
	tabela[3].posicao = 4;
	tabela[3].pontos = 60;
	
	strcpy(tabela[4].time, "Gremio");
	tabela[4].posicao = 5;
	tabela[4].pontos = 59;
	
	strcpy(tabela[5].time, "Bragantino");
	tabela[5].posicao = 6;
	tabela[5].pontos = 59;
	
	strcpy(tabela[6].time, "Fluminense");
	tabela[6].posicao = 7;
	tabela[6].pontos = 53; 
	
	strcpy(tabela[7].time, "Athletico-PR");
	tabela[7].posicao = 8;
	tabela[7].pontos = 52;
	
	strcpy(tabela[8].time, "Cuiabá");
	tabela[8].posicao = 9;
	tabela[8].pontos = 48;
	
	strcpy(tabela[9].time, "São Paulo");
	tabela[9].posicao = 10;
	tabela[9].pontos = 47;
	
	int j = 0;
	int k = 9;
	int l = 1;
	int op;
	char nomeTime[50];
	
	do {
		printf("\t    *.*.*.* BRASILEIRAO *.*.*.*\n\t-.-.- tabela de classificação -.-.-\n\n\n 1) Posição dos times \n 2) Primeiros colocados\n 3) Ultimos colocados\n 4) Diferença de pontos entre os cinco primeiros\n 5) Diferença de pontos entre os cinco ultimos\n 6) Buscar time\n ");
		printf("7) Insertion Sort\n 8) Selection Sort\n 0) SAIR\n Opção: ");
		scanf("%i", &op);
		
		switch(op) {
			case 1: nomeEPosicao(tabela, j); break;
			case 2: primeirosCincoColocados(tabela, j); break;
			case 3: ultimosCincoColocados(tabela, k); break;
			case 4: difCincoP(tabela, j); break;
			case 5: difCincoU(tabela, k); break;
			case 6:
				
				printf("Informe o time: ");
				scanf("%s", nomeTime);
				busca(tabela, j, nomeTime); 
				break;
			case 7: insertionSort(tabela, l); break;
			case 8: selectionSort(tabela, j); break;
			case 0: exit(1); break;
		}
	}while(op != 0);
	
	return 0;
}
