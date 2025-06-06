#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    
    struct No *ant;
    int info;
    struct No *prox;

}No;

typedef struct desc{

    No *inicio;
    int qtd;
    No *fim;

}Descritor;

void Inicializar(Descritor **Lista){

    Lista=(Descritor*)malloc(sizeof(Descritor));
    (*Lista)->inicio = NULL;
    (*Lista)->fim = NULL;
    (*Lista)->qtd = 0;

}

void IsEmpty(Descritor **Lista){

    if((*Lista)->qtd == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

// Feito ! Item A)
No *RetornarEndereco(Descritor **Lista, int value){

    if(IsEmpty(*Lista) == TRUE){
        return 0;
    }

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux->info == value){
            return aux;
        }
        aux = aux->prox;
    }
    
    return NULL;
}

//Função criada para verificar se há algum valor igual.
int VerificarValor(Descritor **Lista, int value){

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux->info == value){
            return 1;
        }
       aux = aux->prox;
    }
    
    return 0;
}

void InserirOrdenadoNaoRepetido(Descritor **Lista, int value){

    if(IsEmpty(*Lista) == TRUE){

        No *NovoNo;
        NovoNo=(No*)malloc(sizeof(No));
        NovoNo->info = value;
        NovoNo->ant = NULL;
        NovoNo->prox = NULL;

        (*Lista)->inicio = NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;

    }
    else{

        if(VerificarValor(Lista, value) == 1){
            printf("Valor repetido");
            return;
        }

        

    }





}