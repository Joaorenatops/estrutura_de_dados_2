//Etapa 1 — Cada nó da árvore precisa armazenar:
//um valor;
//ponteiro para filho da esquerda; 
//ponteiro para filho da direita.

//Em linguagem C:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

//Etapa 2 — Criando um novo nó
//Agora criamos uma função para alocar memória para um nó.
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}
//Etapa 3 — Inserção na ABB
//A inserção é o coração da árvore.
//Regras:
//se o valor for menor → vai para esquerda;
//se o valor for maior → vai para direita.
//Implementação
No* inserir(No *raiz, int valor) {
    // árvore vazia
    if (raiz == NULL) {
        return criarNo(valor);
    }
    // inserção à esquerda
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    // inserção à direita
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    return raiz;
    
}

void emOrdem(No *raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        printf("%d ", raiz->valor);
        emOrdem(raiz->dir);
    }
}

void empreOrdem(No *raiz){
    if(raiz != NULL) {
        printf("%d ", raiz->valor);
        empreOrdem(raiz->esq);
        empreOrdem(raiz->dir);
    }
}

void emposOrdem(No *raiz){
    if(raiz != NULL) {
        emposOrdem(raiz->esq);
        emposOrdem(raiz->dir);
        printf("%d ", raiz->valor);
    }
}

No* buscar(No *raiz, int valor) {

    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }

    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }

    return buscar(raiz->dir, valor);
}
int main() {

    No *raiz = NULL;

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    
    
    printf("Percurso em ordem:\n");

    emOrdem(raiz);

    printf("\nPercurso em pré-ordem:\n");

    empreOrdem(raiz);

    printf("\nPercurso em pós-ordem:\n");

    emposOrdem(raiz);

    return 0;
}