//Implemente a estrutura de um nó de árvore binária em C.
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// 17. Função que inicializa uma árvore vazia
No* inicializarArvore() {
    return NULL;
}

int main(){
//inicializando a variável raiz
   No *raiz = inicializarArvore();
    raiz = criarNo(10); 
};