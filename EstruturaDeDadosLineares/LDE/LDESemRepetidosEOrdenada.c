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

No *RetornarEndereco(Descritor **Lista, int value){

    if(IsEmpty(*Lista) == TRUE){
        return 0;
    }

    No *aux;
    Aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux->info == value){
            return aux;
        }
        aux = aux->prox;
    }
    
    return NULL;
}