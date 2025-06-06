#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


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
    (*Lista)->fim = NULL;
    (*Lista)->inicio = NULL;
    (*Lista)->qtd = 0;

}

int IsEmpty(Descritor **Lista){

    if((*Lista)->qtd == 0){
        return TRUE;
    }

    return FALSE;
}

No *Busca(Descritor **Lista, int value){

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

void InserirNoInicio(Descritor **Lista, int value){

    if(IsEmpty(Lista) == 1){

        No *NovoNo;
        NovoNo=(No*)malloc(sizeof(No));
        NovoNo->ant = NULL;
        NovoNo->info = value;
        NovoNo->prox = NULL;

    }
    else{
        if(Busca(Lista) == NULL){

        No *NovoNo;
        NovoNo=(No*)malloc(sizeof(No));
        NovoNo->ant = NULL;
        NovoNo->info = value;
        NovoNo->prox = (*Lista)->inicio;

        (*Lista)->inicio->ant = NovoNo;
        (*Lista)->inicio = NovoNo;

        }
        else{
            printf("Valor repetido ou lista vazia!");
        }
    }
}

No *Buscar(Descritor **Lista, int value){

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


void InserirNoFinalSemRepetidos(Descritor **Lista, int value){

    if(IsEmpty(Lista) == 1){

        No *NovoNo;
        NovoNo = (No*)malloc(sizeof(No));
        NovoNo->ant = NULL;
        NovoNo->prox = NULL;
        NovoNo->info = value;

        (*Lista)->inicio = NovoNo;
        (*Lista)->fim = NovoNo;

    }
    else{
        if(Buscar(Lista, value) == NULL){

            No *NovoNo;
            NovoNo = (No*)malloc(sizeof(No));
            NovoNo->ant = (*Lista)->fim;
            NovoNo->prox = NULL;
            NovoNo->info = value;

            (*Lista)->fim->prox = NovoNo;
            (*Lista)->fim = NovoNo;

        }
        else{
            printf("Valor repetido!\n");
        }
    }
}

void RemoverEspecifico(Descritor **Lista, int value){

    //Verifica se o valor existe ou lista vazia
    if(Buscar(Lista, value) == NULL){
        printf("valor não existe ou lista vazia");
        return;
    }

    No *aux;
    aux = Buscar(Lista, value); //Aux agora tem a posição do número que eu quero remover 
    No *anterior;


      //verificar se é o único
    if((*Lista)->inicio == (*Lista)->fim){

        (*Lista)->inicio = NULL;
        (*Lista)->fim = NULL;
        (*Lista)->qtd = 0;
        free(aux);
    }
    else{ //Verifica se é o primeiro
        if(aux->ant == NULL){

        (*Lista)->inicio = aux->prox;
        (*Lista)->inicio->ant = NULL;
        (*Lista)->qtd--;
        free(aux);
        
    }
    else{
        //verificar se é o último
        if(aux->prox == NULL){
            
            (*Lista)->fim = aux->ant;
            (*Lista)->fim->prox = NULL;
            (*Lista)->qtd--;
            free(aux);
        }
        else{ //No meio
            anterior = aux->ant;
            anterior->prox = aux->prox;
            aux->prox->ant = anterior;
            (*Lista)->qtd--;
            free(aux);
            }
        }
    }
}

void ExibirLista(Descritor **Lista){

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        printf("%d\n", aux->info);
        aux = aux->prox;
    }

}

