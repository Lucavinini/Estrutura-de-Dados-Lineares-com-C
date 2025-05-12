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

    *Lista=(Descritor*)malloc(sizeof(Descritor));
    (*Lista)->inicio = NULL;
    (*Lista)->qtd = 0;
    (*Lista)->fim = NULL;

}

int IsEmpty(Descritor *Lista){

    if((*Lista)->qtd == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


//Adicionar no inicio;

void InserirNoInicio(Descritor **Lista, int value){

    No *NovoNo;
    NovoNo=(No*)malloc(sizeof(No));
    NovoNo->ant = NULL;
    NovoNo->info = value;
    NovoNo->prox = NULL;

    if(IsEmpty(*Lista) == TRUE){

        (*Lista)->fim = NovoNo;
        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;

    }
    else{

        NovoNo->prox = (*Lista)->inicio;
        (*Lista)->inicio->ant= NovoNo;
        (*Lista)->inicio = NovoNo;
        (*Lista)->qtd++;
    }

}

//Adinionar no final

void InserirNoFinal(Descritor **Lista, int value){

    No *NovoNo;
    NovoNo=(No*)malloc(sizeof(No));
    NovoNo->ant= NULL;
    NovoNo->prox = NULL;
    NovoNo->info = value;

    if(IsEmpty(*Lista) == TRUE){

        (*Lista)->inicio = NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;

    }
    else{

        NovoNo->ant = (*Lista)->fim;
        (*Lista)->fim->prox= NovoNo;
        (*Lista)->fim = NovoNo;
        (*Lista)->qtd++;

    }
}



//Exibir os elementos da lista

void ExibirLista(Descritor *Lista){

    No *aux;
    aux = Lista->inicio;

    if(IsEmpty(*Lista) == TRUE){

        printf("Lista sem elementos\n");
        return;

    }
    else{
        while(aux != NULL){
            printf("%d ", aux->info);
            aux = aux->prox;
        }
    }
}



//Remover no inicio;
//Remover no final
//Remover todos os valores específicos de uma lista
//Esvaziar a lista





int main(){

    Inicializar();

  
}