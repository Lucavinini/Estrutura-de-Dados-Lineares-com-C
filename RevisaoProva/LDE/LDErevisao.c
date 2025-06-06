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

int IsEmpty(Descritor **Lista){

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

void InserirNoFinal(Descritor **Lista, int value){

    No *NovoNo;
    NovoNo=(No*)malloc(sizeof(No));

    NovoNo->ant = NULL;
    NovoNo->info = value;
    NovoNo->prox = NULL;

    if(IsEmpty(Lista) == TRUE){

        (*Lista)->fim->prox = NovoNo;
        NovoNo->ant = (*Lista)->fim;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;
    }

}

//Inserir no meio

void InserirNoMeio(Descritor **Lista, int value){

    if((*Lista)->qtd > 2){

        No *NovoNo;
        NovoNo = (No*)malloc(sizeof(No));

        NovoNo->ant = (*Lista)->inicio;
        NovoNo->prox = (*Lista)->inicio->prox;
        NovoNo->info = value;

        (*Lista)->inicio->prox = NovoNo;
        NovoNo->prox->ant = NovoNo;

        (*Lista)->qtd++;

    }
    else{
        printf("Precisa-se inserir mais elementos na lista.\n");
    }

}



//Remover no inicio;

void RemoverNoInicio(Descritor **Lista){

    if(IsEmpty(Lista) == TRUE){
        printf("Lista vazia\n");
        return;
    }
    
    No *aux;
    aux = (*Lista)->inicio;

    (*Lista)->inicio = (*Lista)->inicio->prox;
    (*Lista)->qtd--;

    free(aux);
}

//remover no final

void RemoverNoFinal(Descritor **Lista, int value){

    if(IsEmpty(Lista) == TRUE){
        printf("Lista vazia\n");
        return;
    }

    No *aux;
    aux = (*Lista)->fim;

    (*Lista)->fim = (*Lista)->fim->ant;
    free(aux);

    (*Lista)->qtd--;
}

//Exibir lista

void ExibirLista(Descritor **Lista){

    if(IsEmpty(Lista) == TRUE){
        printf("Lista vazia\n");
        return;
    }

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }
}

//exibir ao contrario

void ExibirAoContrario(Descritor **Lista){

    if(IsEmpty(Lista) == TRUE){
        printf("Lista vazia\n");
        return;
    }
    
    No *aux;
    aux = (*Lista)->fim;

    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->ant;
    }

}

//Esvaziar lista

void EsvaziarLista(Descritor **Lista){

    if(IsEmpty(Lista) == TRUE){
        printf("Não há elementos a serem removidos..\n");
        return;
    }

    
    No *aux;

    while((*Lista)->qtd != 0){

        aux = (*Lista)->inicio;
        (*Lista)->inicio = (*Lista)->inicio->prox;
        (*Lista)->qtd--;
        free(aux);
    }

    (*Lista)->inicio = NULL;
    (*Lista)->fim = NULL;
    (*Lista)->qtd = 0;

   
}