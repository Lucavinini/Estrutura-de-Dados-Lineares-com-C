#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int info;
    struct lista *proximo;

}Lista;

void InserirNoInicio(Lista **ptr, int valor){ //**ptr serve para modificar diretamente a lista
    
    Lista *Nova; //Cria uma variável que suporta o tipo de dado 
    Nova = (Lista*) malloc(sizeof(Lista)); //Aloca para essa variável um bloco de estrutura

//Uma vez iniciada a lista, podemos preencher ela:

Nova->info = valor;
Nova->proximo = NULL;

/*
Esse nó foi criado, recebeu valores, mas não está ligado na lista.
Por isso, precisamos ligar a lista, verificando se a mesma está cheia ou vazia,

se a mesma estiver vazia, ptr (que é a lista iniciada, vai receber esse nó). 

Se a lista tiver cheia, vamos fazer o novo nó apontar para a lista
e a lista apontar para o novo nó. 

*/ 

if (*ptr == NULL)
{
    *ptr = Nova;

}else{
    Nova->proximo = *ptr;
    *ptr = Nova;
}
printf("Novo No adicionado\n");

}

//Imprimindo a lista;

void ExibirLista(Lista *ptr){

    Lista *aux;

    if(ptr == NULL){
        printf("Lista vazia\n");
    }
    else{
        aux = ptr;
        printf("----Lista----\n");

        while(aux != NULL){ //aux para quando receber um endereço contendo NULL, até lá ele já percorreu a lista, printando tudo.
            printf("%d\n", aux->info);
            aux = aux->proximo; 
        }
        printf("-----------\n");
        printf("\n");
    }

 }    

void ExibirMenu(){
    printf("Menu\n");
    printf("1. Adicionar valor\n");
    printf("2. Exibir lista \n");
    printf("3. Remover Inicio\n");
    printf("5. Inserir no final\n");
    printf("6. Sair\n");
    printf("\n");
}

void RemoverNoInicio(Lista **ptr){

    Lista *aux;

    if(*ptr == NULL){
        printf("Lista vazia, insira um nó.\n");
    }
    else{
            aux = *ptr;
            *ptr = (*ptr)->proximo;
            free(aux);
        }
}

void InserirNoFinal(Lista **ptr, int valor){
    Lista *aux;

    Lista *NovoNo;
    NovoNo = (Lista*)malloc(sizeof(Lista));
    NovoNo->info = valor;
    NovoNo->proximo = NULL;

    if(*ptr == NULL){
        *ptr = NovoNo;
    }
    else{

    aux = *ptr;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo = NovoNo;
    }
    
}

int main(){

Lista *lista = NULL;

int op;
int num;

do {
    ExibirMenu();
    scanf ("%d",&op);
    switch(op) {
        case 1: printf ("Informe o valor: ");
                scanf ("%d",&num);
                InserirNoInicio(&lista, num);
                break;
        case 2: ExibirLista (lista);
                break;
        case 3: RemoverNoInicio (&lista);
                break;
        case 4: printf ("ByeBye \n");
                break;
    }
} while (op != 0);

return 0;
}