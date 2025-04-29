#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	
	struct no *anterior;
	int valor;
	struct no *prox;
	
}No;

typedef struct desc{
	
	struct no *inicio;
	int qtd = 0;
	struct no *fim;	
	
}Descritor;

void Inicializar(Descritor **mydesc){
	// vou alocar o descritor no MAIN
	if(mydesc->qtd == 0){
		mydesc->inicio = NULL;
		mydesc->prox = NULL;
	}
	else{
		return;	
	}	
	
}

void InserirNoInicio(Descritor **mydesc, int valor){
	
	Inicializar();
	
	//Descritor vazio
	if(mydesc->qtd == 0){
		
		No *MeuNo;
		MeuNo = (No*)malloc(sizeof(MeuNo));
		
		MeuNo->anterior = NULL;
		MeuNo->prox = NULL;
		MeuNo->valor = valor;
		
		mydesc->inicio = MeuNo
		mydesc->qtd++;
		mydesc->fim = MeuNo;	
	}
	else{ //Lista com elementos
	
	No *aux;
	aux = mydesc->inicio;
	
	No *MeuNo;
	MeuNo = (No)malloc(sizeof(No));
	
	MeuNo->anterior = NULL;
	MeuNo->valor = valor;
	MeuNo->prox = NULL;
	
	mydesc->incio = MeuNo;
	MeuNo->prox = *aux;
	mydesc->qtd++;
	
	aux->anterior = MeuNo;		
	}	
}

void InserirNoFinal(Descritor **mydesc, int valor){
	
	Inicializar(&mydesc)
		
	if(mydesc->qtd == 0){
		
		No *MeuNo;
		MeuNo=(No*)malloc(sizeof(No))
		
		MeuNo->anterior = NULL;
		MeuNo->prox= NULL;
		MeuNo->valor = valor;
		
		mydesc->inicio = MeuNo;
		mydesc->fim = MeuNo;
		mydesc->qtd++;	
	}
	else{
	
		No *aux;
		aux = mydesc->fim;
		
		No *MeuNo;
		MeuNo = (No*)malloc(sizeof(No));
		
		MeuNo->anterior = *aux;
		MeuNo->prox = NULL;
		MeuNo->valor = valor;
		
		aux->prox = MeuNo;
		
		mydesc->qtd++;
		
	}	
}