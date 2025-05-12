# Estutura de Dados Lineares em C - Lista Duplamente Encadeada

Este documento descreve a lógica e as funções utilizadas na implementação de uma Lista Duplamente Encadeada (LDE).

## Estrutura do Repositório

- `EstruturaDeDadosLineares` — Pasta principal
- `LDE/LDEcorrigida` — Código principal
- `README.md` — Documentação

## Lógica do Código

- **Definição das Estruturas Principais**: Define o modelo do descritor e do nó a ser usado na lista.
- **Inicialização da Lista**: Aloca memória para o descritor e preenche os campos do descritor.
- **Verificar o Estado de Uma Lista**: Criação do IsEmpty() para verificar se a lista está cheia ou vazia.
- **Inserir no Inicio**: 

### Definição das Estruturas Principais

As primeiras linhas de código definem a forma em que o `No` e o `Descritor` vão ter durante todo o programa.

```c

typedef struct no {

    struct no *ant;
    int info;
    struct no *prox;
}No;

```
Definindo primeiro o `No` para que o `Descritor` use o tipo `No` em seus campos `Inicio da lista` e `fim da lista`.

Depois é definido o modelo do descritor.

```c
typedef struct desc {

     no *ant;
    int qtd;
     no *prox;
}No;

```

### Inicialização da Lista

A inicialização da lista é responsável por ligar uma variável do tipo ponteiro *Lista para um descritor. 

A função `Inicializar()` tem como parâmetro um tipo de dado `Descritor` e um ponteiro para ponteiro. Tendo por fim a forma:

`Inicializar(Descritor **Lista)`

A função aloca um descritor para Lista e o preenche. Lembrar de que Lista, deve ser acompanhado de parênteses e o asterisco. 

```c
void Inicializar(Descritor **Lista){
    *Lista=(Descritor*)malloc(sizeof(Descritor));
    (*Lista)->inicio = NULL;
    (*Lista)->qtd = 0;
    (*Lista)->fim = NULL;
}
```


### Verificar o Estado de Uma Lista

