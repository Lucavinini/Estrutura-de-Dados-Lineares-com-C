# Estutura de Dados Lineares em C - Lista Duplamente Encadeada

Este documento descreve a lógica e as funções utilizadas na implementação de uma Lista Duplamente Encadeada (LDE).

## 📁 Estrutura do Repositório

- `EstruturaDeDadosLineares` — Pasta principal
- `LDE/LDEcorrigida` — Código principal
- `README.md` — Documentação

## 🧠 Lógica do Código

- **Definição das Estruturas Principais**: Define o modelo do descritor e do nó a ser usado na lista.
- **Inicializar a Lista**: Aloca memória para o descritor e preenche os campos do descritor.
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

    struct no *ant;
    int info;
    struct no *prox;
}No;



```