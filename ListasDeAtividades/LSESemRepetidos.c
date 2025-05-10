#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *prox;
} Lista;

void InserirNoInicio(Lista **ptr, int valor) {
    Lista *NovoNo;
    NovoNo = (Lista*)malloc(sizeof(Lista));
    if (NovoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    NovoNo->info = valor;
    NovoNo->prox = *ptr;
    *ptr = NovoNo;
}

void ExibirValores(Lista *ptr) {
    Lista *aux;

    if (ptr == NULL) {
        printf("Lista vazia.\n");
    } else {
        aux = ptr;
        while (aux != NULL) {
            printf("%d ", aux->info);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void RemoverNoInicio(Lista **ptr) {
    Lista *aux;

    if (*ptr == NULL) {
        printf("Não há Nós.\n");
    } else {
        aux = *ptr;
        *ptr = (*ptr)->prox;
        free(aux);
    }
}

void InserirNoFinal(Lista **ptr, int valor) {
    Lista *NovoNoFinal;
    NovoNoFinal = (Lista*)malloc(sizeof(Lista));
    if (NovoNoFinal == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    NovoNoFinal->info = valor;
    NovoNoFinal->prox = NULL;

    if (*ptr == NULL) {
        *ptr = NovoNoFinal;
    } else {
        Lista *aux;
        aux = *ptr;

        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = NovoNoFinal;
    }
}

void RemoverNoFinal(Lista **ptr) {
    Lista *aux;
    Lista *anterior;

    if (*ptr == NULL) {
        printf("Não há elementos na lista.\n");
    } else {
        if ((*ptr)->prox == NULL) { 
            free(*ptr);
            *ptr = NULL;
            printf("A lista só tinha 1 elemento, e ele foi removido.\n");
        } else {
            anterior = *ptr;
            aux = (*ptr)->prox;

            while (aux->prox != NULL) {
                anterior = aux;
                aux = aux->prox;
            }
            free(aux);
            anterior->prox = NULL;
            printf("Remoção Efetuada\n");
        }
    }
}

int ContarElementos(Lista *ptr) {
    int contador = 0;
    Lista *aux = ptr;

    while (aux != NULL) {
        contador++;
        aux = aux->prox;
    }
    return contador;
}

int ContarValor(Lista *ptr, int value) {
    int cont = 0;
    Lista *aux = ptr;

    while (aux != NULL) {
        if (aux->info == value) {
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
}

void Desalocar(Lista **ptr) {
    Lista *aux;

    while (*ptr != NULL) {
        aux = *ptr;
        *ptr = (*ptr)->prox;
        free(aux);
    }
}

void ExibirOp() {
    printf("\n--------------\n");
    printf("0. Sair\n");
    printf("1. Inserir no inicio\n");
    printf("2. Inserir no final\n");
    printf("3. Remover no inicio\n");
    printf("4. Remover no final\n");
    printf("5. Exibir lista\n");
    printf("6. Contagem de elementos da lista\n");
    printf("7. Contar valor especifico\n");
    printf("--------------\n");
}

int main() {
    Lista *MinhaLista = NULL;
    int op, num, result;

    do {
        ExibirOp();
        printf("Escolha uma opção: ");
        scanf("%d", &op);
        switch(op) {
            case 1: 
                printf("Informe o valor: ");
                scanf("%d", &num);
                InserirNoInicio(&MinhaLista, num);
                break;
            case 2: 
                printf("Informe o valor: ");
                scanf("%d", &num);
                InserirNoFinal(&MinhaLista, num);
                break;
            case 3: 
                RemoverNoInicio(&MinhaLista);
                break;
            case 4: 
                RemoverNoFinal(&MinhaLista);
                break;
            case 5: 
                ExibirValores(MinhaLista);
                break;
            case 6: 
                result = ContarElementos(MinhaLista);
                printf("A lista possui %d elementos\n", result);
                break;
            case 7: 
                printf("Informe o valor: ");
                scanf("%d", &num);
                result = ContarValor(MinhaLista, num);
                printf("O elemento %d aparece %d vez(es) na lista\n", num, result);
                break;
            case 0: 
                printf("Bye bye\n");
                Desalocar(&MinhaLista);
                break;
            default: 
                printf("Opção inválida\n");
        }
    } while (op != 0);

    return 0;
}
