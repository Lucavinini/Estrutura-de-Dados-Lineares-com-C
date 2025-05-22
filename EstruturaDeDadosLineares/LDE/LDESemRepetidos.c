#include <stdio.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

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

//Inicializar Lista

void Inicializar(Descritor **Lista){
 
    Lista=(Descritor*)malloc(sizeof(Descritor));
    (*Lista)->inicio = NULL;
    (*Lista)->qtd = 0;
    (*Lista)->fim = NULL;
}

void IsEmpty(*Lista){

    if((*Lista)->qtd == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

// a) 
//Função que retorna o endereço de um número procurado

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

//Inserir No inicio sem ser repetido

void InserirNoInicio(Descritor **Lista, int value){

    No *aux;
    aux = (*Lista)->inicio;

    No *NovoNo;
    NovoNo = (No*)malloc(sizeof(No));

    NovoNo->ant = NULL;
    NovoNo->info = value;
    NovoNo->prox = NULL;

    while(aux != NULL){
        if(aux->info == value){
            printf("Valor repetido\n");
            return;
        }
        aux = aux->prox;
    }

    if(IsEmpty(*Lista) == TRUE){

        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;
        (*Lista)->fim = NovoNo;

    }
    else{
        
        NovoNo->prox = (*Lista)->inicio;
        (*Lista)->inicio->ant = NovoNo;
        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;
    }

}


//Inserir No final sem ser repetido;

void InserirNoFinalSemRepetidos(Descritor **Lista, int value){

    No *NovoNo;
    NovoNo=(No*)malloc(sizeof(No));

    NovoNo->ant = NULL;
    NovoNo->info = value;
    NovoNo->prox = NULL;

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux->info == value){
            printf("Repetido.\n");
            return;
        }
        aux = aux->prox;
    }

    if(IsEmpty(*Lista) == TRUE){
        
        (*Lista)->inicio = NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;

    }
    else{
        NovoNo->ant = (*Lista)->fim;
        (*Lista)->fim->prox = NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;
    }
}

//Exibir Todos os números da lista

void ExibirElemetos(Descritor **Lista){

    if(IsEmpty(*Lista) == TRUE){
        printf("Lista sem elementos\n");
        return;
    }

    No aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        printf("%d", aux->info);
        aux = aux->prox;
    }
}

//Remover um especifico usando a função a)

void RemoverEspecifico(Descritor **Lista, int value){

    if(RetornarEndereco(*Lista, value) == 0){
        printf("Lista vazia\n");
        return;
    }

    if(RetornarEndereco(*Lista, value) == NULL){
        printf("Valor não existe na lista\n");
        return;
    }

    No *aux;
    aux = RemoverEspecifico(*Lista, value);

    No *anterior;


    if(aux->ant == NULL){

        (*Lista)->inicio = (*Lista)->inicio->prox;
        free(aux);
        (*Lista)->qtd--;
    }
    else{
        anterior = aux->ant;
        anterior->prox = aux->prox;
        free(aux);
        (*Lista)->qtd--;
    }

}
