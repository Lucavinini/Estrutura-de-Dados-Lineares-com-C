#include <stdio.h>
#include <stdlib.h>

//Processo de inicialização

typedef struct no{

    struct no *ant;
    int info;
    struct no *prox;

}No;

typedef struct desc{

    No *inicio;
    int qtd;
    No *fim;

}Descritor;

void Inicializar(Descritor **Lista){

    Lista=(Descritor*)malloc(sizeof(Descritor));
    (*Lista)->inicio = NULL;
    (*Lista)->qtd = 0;
    (*Lista)->fim = NULL;

}

void IsEmpty(Descritor **Lista){

    if((*Lista)->qtd == 0){
        return TRUE;
    }

    return FALSE;
}

//Inserir no inicio

void InserirNoInicio(Descritor **Lista, int value){
    No *NovoNo;
    NovoNo = (No*)malloc(sizeof(No));

    NovoNo->ant = NULL;
    NovoNo->info = value;
    NovoNo->prox = NULL;

    if(IsEmpty(Lista) == TRUE){

        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;
        (*Lista)->fim = NovoNo;
        
    }
    else{
        No *aux;
        aux = (*Lista)->inicio;
        NovoNo->prox = aux;
        aux->ant = NovoNo;
        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;
    }
}

//Inserir No final

//Inserir no meio

//Remover no inicio;

//remover no final

//Exibir lista

//exibir ao contrario


//Esvaziar lista