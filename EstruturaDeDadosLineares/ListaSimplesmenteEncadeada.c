#include <stdio.h>
#include <stdlib.h>

typedef struct pedido{
    int info;
    struct pedido *prox;
} Pedido;

void Insercao(Pedido **lista, int valor){
    Pedido *NovaNo;
    NovaNo = (Pedido*)malloc(sizeof(Pedido));

    NovaNo->info = valor;
    NovaNo->prox = NULL;

    if(*lista == NULL){
        *lista = NovaNo;

    }else{
        NovaNo->prox = *lista;
        *lista = NovaNo;
    }
    printf("Adicionado..\n");
}
void ExibirMenu(){
    printf("------------------------\n");
    printf("1. Inserir elemento na lista\n");
    printf("2. Exibir Lista\n");
    printf("3. Excluir valor\n");
    printf("4. Sair\n");
    printf("------------------------\n");

}

void ExibirLista(Pedido *lista){

    Pedido *aux;

    if(lista == NULL){
        printf("Lista vazia caralho!\n");
    }
    else{
        aux = lista;
        while(aux != NULL){
          printf("%d\n", aux->info);
          aux = aux->prox;
        }
        printf("\n");
    }
}

void ExcluirNoInicio(Pedido **lista){
    Pedido *aux;

    if(*lista == NULL){
        printf("Não existem valores a serem excluidos!\n");
    }else{
        aux = *lista;
        *lista= (*lista)->prox;
        free(aux);
     }
    }



int main(){

Pedido *lista = NULL;

int num;
int i;

do {
    ExibirMenu();
    scanf ("%d",&i);
    switch(i) {
        case 1: printf ("Informe o valor: ");
                scanf ("%d",&num);
                Insercao(&lista,num);
                break;
        case 2: ExibirLista(lista);
                break;
        case 3: ExcluirNoInicio(&lista);
                break;
        case 0: printf ("Bye bye \n");
                break;
        default: printf ("Opcao invalida \n");
    }
} while (i != 0);

return 0;


}