#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

struct produto {
	char nome[255];
	float valor;
	int id;
	struct produto *prox;
};
typedef struct produto *Produto;



Produto addNovoProd(int id, char nome[], float valor, Produto e) {	
	// dados inserido na minha struct 
	Produto prod = (Produto)malloc(sizeof(struct produto));

	if (e == NULL) {
		// primeiro produto adicionado ao estoque
		prod->id = id;
		strcpy(prod->nome, nome); // strcpy soluciona o problema de atribuiçoes do tipo char
		prod->valor = valor;
		prod->prox = NULL;
		
		return prod;
	} else {
		
		prod->id = id;
		strcpy(prod->nome, nome);
		prod->valor = valor;
		prod->prox = e;
		
		return prod;
	}
}

void dados(int id, char n[], float *v) {
	getchar();
	printf("\nID: %i\n", id);
	printf("Produto: ");
	gets(n);
	
	printf("Valor: ");
	scanf("%f", v);
}

Produto ordenaProds(Produto aux) {
	if (aux == NULL) {
//		printf("Nomes ordenados automáticamente...\n");
	} else {
		char nome[255];
		int id;
		float valor;
		
		Produto aux_proximo = aux->prox;
		
		if(aux_proximo != NULL) {
			
			if(strcmp(aux->nome, aux_proximo->nome) > 0) {
				
				id = aux->id;				
				strcpy(nome, aux->nome);
				valor = aux->valor;
				
				aux->id = aux_proximo->id;
				strcpy(aux->nome, aux_proximo->nome);
				aux->valor = aux_proximo->valor;
				
				aux_proximo->id = id;
				strcpy(aux_proximo->nome, nome);
				aux_proximo->valor = valor;
			}	
			ordenaProds(aux_proximo->prox);
		}
		ordenaProds(aux->prox);
	}
}

Produto buscarProd(Produto aux) {
	char nome[255];
	int flagAchou = 0;
	
	int c=0;
	
	getchar();
	printf("Nome do produto: ");
	gets(nome);
	
	while (aux != NULL) {
		
		if (strcmp(aux->nome, nome) == 0) {
			printf("\nProduto encontrado:\n");
			printf("	ID: %i\n", aux->id);
			printf("	Produto: %s\n", aux->nome);
			printf("	Valor: %.2f\n", aux->valor);
			
			flagAchou = 1;
			
			break;	
		}
		
		aux = aux->prox;
	}
	
	if(flagAchou == 0) {
		printf("\nProduto não encontrado...\n");
	}
}

void visualizarProds(Produto aux) {
	if (aux == NULL) {
//		printf("Lista vazia!\n");
	} else {
		if (aux->prox == NULL) {
			printf("\nID: %i\nProduto: %s\nValor: %.2f\n", aux->id, aux->nome, aux->valor);
			
		} else {
			printf("\nID: %i\nProduto: %s\nValor: %.2f\n", aux->id, aux->nome, aux->valor);
		}
		
		visualizarProds(aux->prox);
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	int id=0;
	char produto[255];
	float valor;
	
	int option;
	
	Produto estoque = NULL;
	do {
		printf("\nOpções..\n1) Adicionar produto\n2) Visualizar produto\n3) Buscar produto\n0) Sair\nOpcão: ");
		scanf("%i", &option);
		switch(option){
			
			case 1: 
				dados(id, produto, &valor);
				estoque = addNovoProd(id, produto, valor, estoque); // addNovoProd recebe também o e que se refere ao conjunto de produtos na lista de "e" de estoque
				// acrescenta o id.
				id++;
				
				ordenaProds(estoque);
			break;
			
			case 2: 
				printf("\n****** Lista de produtos no Estoque ******\n"); 
				visualizarProds(estoque); 
				printf("\n********************************************\n");
			break;
			
			case 3: buscarProd(estoque); break;
			
//			case 4: buscaBinaria(estoque); break;
			case 0: exit(1); break;
		}
	} while (option != 0);
	
	return 0;
}
