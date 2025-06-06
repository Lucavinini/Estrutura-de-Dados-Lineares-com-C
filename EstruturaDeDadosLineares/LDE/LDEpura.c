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
void RemoverNoInicio(Descritor **Lista){

    No *aux;
    aux = (*Lista)->inicio;

    if(IsEmpty(*Lista) == TRUE){
        printf("Não há elementos a serem removidos\n");
        return;
    }
    else{

        (*Lista)->inicio = (*Lista)->inicio->prox;

        if((*Lista)->inicio != NULL){

        (*Lista)->inicio->ant = NULL;

        }
        else{
            (*Lista)->fim = NULL;
        }
        (*Lista)->qtd--;
        free(aux);
    }
}

//Remover no Meio

void RemoverNoMeio(Descritor **Lista){

    No *aux;
    aux = (*Lista)->inicio->prox;

    //verificar se a lista tem pelo menos 3 nós. Se tiver faz a remoção, se não, não faz.

    if((*Lista)->qtd >= 3){

        (*Lista)->inicio->prox->prox->ant= (*Lista)->inicio;
        (*Lista)->inicio->prox = (*Lista)->inicio->prox->prox;

        (*Lista)->qtd--;
        free(aux);

    }
    else{
        printf("Não existe elementos no meio para remover \n");
    }
}

//Remover no final

void RemoverNoFinal(Descritor **Lista){

    No *aux, *aux2;

    aux = (*Lista)->fim;
    aux2 = (*Lista)->fim;

    if((*Lista)->qtd <= 1){

        (*Lista)->inicio = NULL;
        (*Lista)->fim = NULL;
        (*Lista)->qtd--;
        free(aux);

    }
    else{
        aux2 = aux->ant;
        aux2->prox = NULL;
        (*Lista)->fim = aux2;
        (*Lista)->qtd--;
        free(aux);
    }
}

//a)Valor a ser procurado

No *Especifico(Descritor *Lista, int value){

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



//Remover todos os valores específicos de uma lista

void RemoverEspecificos(Descritor **Lista, int value) {

    if (IsEmpty(*Lista)) {
        printf("Lista vazia\n");
        return;
    }

    No *aux = (*Lista)->inicio;
    No *anterior = NULL;
    int contador = 0;

    while (aux != NULL) {
        if (aux->info == value) { //Acha o valor
            No *temp = aux;

            //Entende a posição do valor

            //primeiro no
            if (anterior == NULL) {
                // Remover o primeiro nó
                (*Lista)->inicio = aux->prox;
                aux = (*Lista)->inicio;
            } else {
                anterior->prox = aux->prox;
                aux = aux->prox;
            }

            free(temp);
            contador++;
            (*Lista)->qtd--;
        } else {
            anterior = aux;
            aux = aux->prox;
        }
    }

    printf("Foram removidos %d elemento(s) com o valor %d.\n", contador, value);
}


//Esvaziar a lista

void EsvaziarLista(Descritor **Lista){

    No *aux;
    aux = (*Lista)->inicio;

    if(IsEmpty(*Lista) == TRUE){
        printf("A lista já está vazia\n");
        return;
    }

    while(aux != NULL){
        (*Lista)->inicio = aux->prox;
        free(aux);
        (*Lista)->qtd--;
        aux = (*Lista)->inicio;
    }

    (*Lista)->inicio = NULL;
    (*Lista)->fim = NULL;
    (*Lista)->qtd = 0

    printf("Lista vazia\n");
}


int main(){

    Descritor *Lista;
    Inicializar(Lista);

  
}