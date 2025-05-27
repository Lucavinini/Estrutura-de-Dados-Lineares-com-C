#include <stdio.h>

typedef struct no{

    int info;
    struct no *prox;
    struct no *ant;

}No;

typedef struct desc{

    No *topo;
    int qtd;
    int limite;

}Descritor;

void Inicializar(Descritor **Mydesc, int li){

    Mydesc = (Descritor*)malloc(sizeof(Descritor));
    (*Mydesc)->qtd = 0;
    (*Mydesc)->topo = NULL;
    (*Mydesc)->limite = li;

}

//Push - empilhar
//Pop - Desempilhar;
//Top - Printar o topo;
//IsEmpty 
//IsFull

int main(){

Descritor *Lista;

int x;

printf("Digite o limite: \n");
scanf("%d", &x);

Inicializar(&Lista, x);


}