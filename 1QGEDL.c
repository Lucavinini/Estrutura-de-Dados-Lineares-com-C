

//Segunda questão 

No *Buscar(Descritor **Lista, int value){

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

void RemoverEspecifico(Descritor **Lista, int value){
    
    No *aux;
    aux = Buscar(Lista, value);

    //Verifica se o valor existe ou lista vazia
    if(aux == NULL){
        return;
    }

    //verificar se é o único

    if((*Lista)->inicio == (*Lista)->fim){

        (*Lista)->inicio = NULL;
        (*Lista)->fim = NULL;
        (*Lista)->qtd--;
        free(aux);
    }
    else{
        if(aux->ant == NULL){
            (*Lista)->inicio = aux->prox;
            aux->prox->ant = NULL;
            free(aux);
            (*Lista)->qtd--;
        }
        else{
            if(aux == (*Lista)->fim){

                (*Lista)->fim = aux->ant;
                (*Lista)->fim->prox = NULL;
                free(aux);
                (*Lista)->qtd--;
            }
            else{

                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                free(aux);
                (*Lista)->qtd--;
            }

        }

    }

}