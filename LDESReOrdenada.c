#include <stdio.h>
#include <stdlib.h>

typedef struct no{

    struct no *ant;
    struct no *prox;
    int info;
}No;

typedef struct desc{

    No *inicio;
    No *fim;
    int qtd;

}Descritor;

No  *Buscar(Descritor **Lista, int value){

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux ->info == value){
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}

void InserirCrescenteSR(Descritor **Lista, int value){

    No *NovoNo;
    NovoNo=(No*)malloc(sizeof(No));
    NovoNo->info = value;

    NovoNo->ant = NULL;
    NovoNo->prox = NULL;

    if(IsEmpty(Lista) == 1){
        (*Lista)->inicio = NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;
    }
    else{
        if(Buscar(Lista, value) == NULL){

            No *aux;
            aux = (*Lista)->inicio;

            if((*Lista)->fim->info < NovoNo->info){

                (*Lista)->fim->prox = NovoNo;
                NovoNo->ant = (*Lista)->fim;
                NovoNo->prox = NULL;
                (*Lista)->fim = NovoNo;
                (*Lista)->qtd++;
            }
            else{
                printf("Valor menor, insira um maior\n");
            }

        }else{
        printf("Valor repetido!\n");
        }
    }
}