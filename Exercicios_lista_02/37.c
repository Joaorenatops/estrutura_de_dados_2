//Implemente a estrutura de um nó de árvore binária em C.
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    
    int valor;
    struct No *esq;
    struct No *dir;

} No;

// Função auxiliar para criar o nó
No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

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

int main(){
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

    return 0;
}