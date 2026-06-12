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

void preOrdem(No *raiz) {
    if (raiz != NULL){
        print("%d",raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void posOrdem(No *raiz) {
    if(raiz != NULL){
        posOrdem(raiz->esq);
        posOrdem(raiz->dir);
        print("%d",raiz->valor);
    }
}

//pre ordem ???

//pos ordem ???

No* buscar(No *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }
    return buscar(raiz->dir, valor);
}

//Remoção
//Remoção
No* remover(No *raiz, int valor) {
    No *temp = NULL;
    // árvore vazia
    if (raiz == NULL) {
        return NULL;
    }

    // busca do nó
    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    }

    else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    }

    // encontrou o nó
    else {
        
        // CASO 1 - sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {

            free(raiz);

            return NULL;
        }

        // CASO 2 - um filho à direita
        else if (raiz->esq == NULL) {

            temp = raiz->dir;

            free(raiz);

            return temp;
        }

        // CASO 2 - um filho à esquerda
        else if (raiz->dir == NULL) {

            temp = raiz->esq;

            free(raiz);

            return temp;
        }
    raiz->dir = temp;
    //raiz->valor = temp->valor;
    return raiz;
}
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
    raiz = inserir(raiz, 90);
    raiz = inserir(raiz, 35);
    raiz = inserir(raiz, 25);

    
    printf("Antes de remover elementos:\n");
    emOrdem(raiz);

    raiz = remover(raiz, 80);

    printf("\n\nDepois de remover elemento:\n");
    emOrdem(raiz);

    return 0;
}