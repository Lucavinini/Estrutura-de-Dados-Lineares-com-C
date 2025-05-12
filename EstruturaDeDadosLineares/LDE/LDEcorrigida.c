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

    if(Lista->qtd == 0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}


//Iniciar no inicio;
//Iniciar no final
//Exibir os elementos da lista
//Remover no inicio;
//Remover no final
//Remover todos os valores específicos de uma lista
//Esvaziar a lista





int main(){

    Inicializar();

  
}