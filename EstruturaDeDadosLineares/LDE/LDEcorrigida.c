#include <stdio.h>
#include <stdio.h>

typedef struct desc{

    struct desc *inicio;
    int qtd;
    struct desc *fim;

}Descritor;

typedef struct no{

    struct no *anterior;
    int info;
    struct no *prox;

}No;

//Iniciar no inicio;



//Iniciar no final

void InserirNoInicio(Descritor **mydesc, int valor){

    if(mydesc->qtd == 0){  //Lista sem nó?
        
        No *NovoNo;
        NovoNo=(No*)malloc(sizeof(No));

        NovoNo->info = valor;
        NovoNo->anterior = NULL;
        NovoNo->prox = NULL;

        mydesc->inicio =*NovoNo;
        mydesc->fim =*NovoNo;
        mydesc->qtd++;
    }
    else{
        
    }

    //Lista com nó?

}


//Exibir os elementos da lista

//Remover no inicio;

//Remover no final

//Remover todos os valores específicos de uma lista

//Esvaziar a lista




void Iniciar(){

        //Criando a lista e alocando a mesma;
        Descritor *Lista = NULL;
        Lista=(Descritor*)malloc(sizeof(Descritor));
    
        //Criando o descritor e alocando o mesmo
        Descritor *mydesc;
        mydesc=(Descritor*)malloc(sizeof(Descritor));

        //Inicializado o descritor
        mydesc->qtd = 0;
        mydesc->fim = NULL;
        mydesc->inicio = NULL;

        //Conectando a lista com o descritor
        *Lista = mydesc;
}





int main(){

    Iniciar(); //A função "Iniciar()" Cria a lista, aloca a lista, cria o 
                //Descritor, aloca o descritor.

  
}