#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int info;
    struct lista *prox;
}Lista;

void InserirNoFinalSemRepetidos(Lista **ptr, int valor){

    Lista *aux;
    aux = *ptr;

    //Verificar se a lista contém elementos repetidos

    while(aux != NULL){
        if(aux->info == valor){
            printf("Valor repetido!");
            return;
        }
        aux = aux->prox;
    }

    //criar o meu nó;
    Lista *NovoNo;
    NovoNo = (Lista*)malloc(sizeof(Lista));
    NovoNo->info = valor;
    NovoNo->prox = NULL;

    //criar o meu nó;
    if(*ptr == NULL){ //inserir se ela estiver vazia
        *ptr = NovoNo;
    }
    else{ //inserir se ela estiver cheia no final
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = NovoNo;
    }
    //inserir se ela estiver vazia
}