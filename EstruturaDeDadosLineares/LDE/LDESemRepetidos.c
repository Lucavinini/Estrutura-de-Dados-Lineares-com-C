#include <stdio.h>
#include <stdlib.h>

#DEFINE TRUE 1;
#DEFINE FALSE 0;

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

void Inicializar(**Lista){
 
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

    //Verificar Repetido

    No *aux;
    aux = (*Lista)->inicio;

    while(aux != NULL){
        if(aux->info == value){
            printf("Valor repetido\n");
            return
        }
        aux = aux->prox;
    }

    if(IsEmpty(*Lista) == TRUE){

        
    }

   
}








//Inserir No final sem ser repetido;
//Exibir Todos os números da lista
//Remover um especifico usando a função a)