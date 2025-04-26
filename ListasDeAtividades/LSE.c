#include <stdio.h>
#include <stdlib.h>

typedef struct lista{

    int info;
    struct lista *prox;
}Lista;

void InserirNoInicio(Lista **ptr, int valor){
    Lista *NovoNo;
    Lista *ptr = (Lista*)malloc(sizeof(Lista));
    NovoNo->info = valor;
    NovoNo->prox = NULL;

    if(*ptr == NULL){
        *ptr = NovoNo;
    }
    else{
        NovoNo->prox = *ptr;
        *ptr = NovoNo;
    }
}

void ExibirValores(Lista *ptr){

    Lista *aux;

    if(ptr == NULL){
        printf("Lista vazia.\n");
    }
    else{
        aux = ptr;
        while(aux != NULL){
            printf("%d", aux->info);
            aux = aux->prox;
        }
    }
}

void RemoverNoInicio(Lista **ptr){
    Lista *aux;

    if(*ptr == NULL){
        printf("Não há Nós.\n");
    }
    else{
        aux = *ptr;
        *ptr = (*ptr)->prox;
        free(aux);
    }
}

void InserirNoFinal(Lista **ptr, int valor){

    Lista *NovoNoFinal;
    NovoNoFinal = (Lista*)malloc(sizeof(Lista));

    NovoNoFinal->info = valor;
    NovoNoFinal->prox = NULL;

    if(*ptr == NULL){
        *ptr = NovoNoFinal;
    }
    else{
        Lista *aux;
        aux = *ptr;

        while(aux->prox != NULL){
           aux = aux->prox;
        }
        aux->prox = NovoNoFinal;
    }
}

void RemoverNoFinal(Lista **ptr){
    
    Lista *aux;
    Lista *anterior;

    if(*ptr == NULL){
        printf("Não há elementos na lista.\n");
    }
    else{
        if(ptr->prox == NULL){
            free(*ptr);
            *ptr = NULL;
            printf("A lista só tinha 1 elemento, e ele foi removido.\n");
        }
        else{

            anterior = *ptr;
            aux = *ptr;

            aux = aux->prox;
            while(aux->prox != NULL){

                aux = aux->prox;
                anterior = anterior->prox;
               
            }
            free(aux);
            anterior->prox = NULL;
            printf("Remoção Efetuada");            

        }
    }
}

int ContarElementos(Lista *ptr){

    int contador = 0;
    Lista *aux;

    if(ptr == NULL){
        return contador;
    }
    
    else{
        aux = ptr;
        while(aux != NULL){
            contador++;
            aux = aux->prox;
        }
        return contador;
    }
}

int ContarValor(Lista *ptr, int value){

    int cont = 0;
    if(ptr == NULL){
        return cont;
    }
    else{
        Lista *aux;
        aux = ptr;
        while(aux != NULL){
            if(aux->info == value){
                cont++;
            }
            aux = aux->prox;
        }
        return cont;
    }
}

void Desalocar(Lista **ptr){
    if(*ptr == NULL){
        return;
    }
    else{
        Lista *aux;
        aux = *ptr;
        Lista *aux2;
        aux2 = *ptr;
        while(aux != NULL){
            *ptr = aux2->prox;
            free(aux);
            aux = *ptr;
            aux2 = *ptr;
        }
    }
}

void ExibirOp(){
    printf("--------------");
    printf("1. Inserir no inicio\n");
    printf("2. Exibir lista\n");
    printf("3. Remover no inicio\n");
    printf("4. Inserir no final\n");
    printf("5. Remover no final\n");
    printf("6. Contagem de elementos da lista\n");
    printf("7. Contar valor especifico\n");
    printf("8. Sair");
    printf("--------------");
}

int main(){

    Lista *MinhaLista = NULL;
    int op, num, result;
    do {
        ExibirOp();
        scanf ("%d",&op);
        switch(op) {
            case 1: printf ("Informe o valor: ");
                    scanf ("%d",&num);
                    InserirNoFinal(&MinhaLista,num);
                    break;
            case 2: printf ("Informe o valor: ");
                    scanf ("%d",&num);
                    InserirNoFinal(&MinhaLista,num);
                    break;
            case 3: RemoverNoInicio(&MinhaLista);
                    break;
            case 4: RemoverNoFinal(&MinhaLista);
                    break;
            case 5: ExibirValores(MinhaLista);
                    break;
            case 6: result = ContarElementos(MinhaLista);
                    printf ("A lista possui %d elementos \n", result);
                    break;
            case 7: printf ("Informe o valor: ");
                    scanf ("%d",&num);
                    result = ContarValor(MinhaLista, num);
                    printf ("O elemento %d aparece %d vez(es) na lista \n", num, result);
                    break;
            case 8: printf ("Bye bye \n");
                    Desalocar(&MinhaLista);
                    break;
            default: printf ("Opcao invalida \n");
        }
    } while (op != 0);

}