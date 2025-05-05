#include <stdio.h>
#include <stdio.h>

typedef struct desc{

    struct desc *inicio;
    struct desc qtd;
    struct desc *fim;

}Descritor;

typedef struct no{

    struct no *anterior;
    int info;
    struct no *prox;

}No;

//Iniciar no inicio;


//Iniciar no final


//Exibir os elementos da lista

//Remover no inicio;

//Remover no final

//Remover todos os valores específicos de uma lista

//Esvaziar a lista




void iniciar(Descritor **Lista){

    if (*Lista == NULL) {
        Lista=(Descritor*)malloc(sizeof(Descritor));
    }
    else{
        return;
    }
}



int main(){

    Descritor *Lista = NULL;

    return 0;
}